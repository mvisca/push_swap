/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_utils_long.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:28:38 by mvisca            #+#    #+#             */
/*   Updated: 2023/08/01 19:18:57 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int				ps_cost_to_move(t_com *moves);
static t_com	*ps_get_best_move(t_ps *ps);
static void		ps_move_b_to_a(t_ps *ps);

void	ps_sort_long(t_ps *ps)
{
	int		i;
	t_com	*best_move;

	while (ps->a->size > 3 && ps->b->size < 2)
		ps_command(pb, ps);
	while (ps->a->size > 3)
	{
		best_move = ps_get_best_move(ps);
		i = 0;
		while (best_move[i] != end)
			ps_command(best_move[i++], ps);
		free(best_move);
		ps_command(pb, ps);
	}
	ps_sort_three(ps);
	ps_move_b_to_a(ps);
	ps_min_to_top(ps);
}

int	ps_cost_to_move(t_com *moves)
{
	int	i;

	i = 0;
	while (moves[i] != end)
		i++;
	return (i);
}

static t_com	*ps_get_best_move(t_ps *ps)
{
	t_com		*test_move;
	t_com		*best_move;
	t_ps_list	*current;

	best_move = prep_b(ps, ps->a->head->content);
	best_move = prep_a(ps, ps->a->head->content, best_move);
	current = ps->a->head->next;
	while (current)
	{
		test_move = prep_b(ps, current->content);
		test_move = prep_a(ps, current->content, test_move);
		if (ps_cost_to_move(test_move) < ps_cost_to_move(best_move))
		{
			free(best_move);
			best_move = test_move;
			test_move = NULL;
		}
		else
			free(test_move);
		current = current->next;
	}
	return (best_move);
}

static t_com	ps_rot_direction(t_ps *ps, int curr)
{
	int			rotations;
	t_com		rot_type;
	t_ps_list	*last;
	t_ps_list	*first;

	rotations = 0;
	rot_type = rra;
	last = ps->a->head;
	first = last->next;
	while (!(curr > last->content && curr < first->content))
	{
		last = last->next;
		first = last->next;
		rotations++;
	}
	if (rotations > ps->a->size + 1 / 2)
	{
		rotations = ps->a->size - rotations;
		rot_type = ra;
	}
	return (rot_type);
}

static void	ps_move_b_to_a(t_ps *ps)
{
	int	curr;

	while (ps->b->size)
	{
		curr = ps->b->head->content;
		ps_min_to_top(ps);
		if (curr > ps->a->max && ps_command(pa, ps))
			ps_command(ra, ps);
		else if (curr < ps->a->max && curr > ps->a->min)
		{
			while (!(curr > ps_lstlast(ps->a->head)->content \
				&& curr < ps->a->head->content))
				ps_command(ps_rot_direction(ps, curr), ps);
			ps_command(pa, ps);
		}
		else
		{
			ps_command(pa, ps);
		}
	}
}
