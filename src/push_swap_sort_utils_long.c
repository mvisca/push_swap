/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_utils_long.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:28:38 by mvisca            #+#    #+#             */
/*   Updated: 2023/07/27 18:10:15 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int				ps_move_cost(t_com *moves);
static t_com	*ps_get_best_move(t_stack *a, t_stack *b);
static void		ps_move_b_to_a(t_ps *ps);

void ps_sort_long(t_ps *ps)
{
	int		i;
	t_com	*best_move;

	while (ps->a->size > 3 && ps->b->size < 3)
		ps_command(pb, ps);
	while (ps->a->size > 3)
	{
		best_move = ps_get_best_move(ps->a, ps->b);
		// best_move = optimize_move(best_move);
		i = 0;
		while (best_move[i] != end)
			ps_command(best_move[i++], ps);
		free(best_move);
		ps_command(pb, ps);
	}
	ps_sort_three(ps);
	ps_move_b_to_a(ps);
}

int	ps_move_cost(t_com *moves)
{
	int	i;

	i = 0;
	while (moves[i] != end)
		i++;
	return (i);
}

static t_com	*ps_get_best_move(t_stack *a, t_stack *b)
{
	t_com	*test_move;
	t_com	*best_move;
	t_ps_list	*current;

	best_move = prep_b(b, a->head->content);
	best_move = prep_a(a, a->head, best_move);
	current = a->head->next;
	while (current)
	{
		test_move = prep_b(b, current->content);
		test_move = prep_a(a, current, test_move);
		if (ps_move_cost(test_move) < ps_move_cost(best_move))
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

static void	ps_move_b_to_a(t_ps *ps)
{
	while (ps->b->size > 0)
	{
		ps_min_to_top(ps);
		
		while (ps->b->size > 0 && ps->b->head->content > ps->a->max)
			ps_command(pa, ps);

		while (ps->b->size > 0 && ps->b->head->content > ps->a->min)
		{
			if (ps->b->head->content > ps_lstlast(ps->a->head)->content)
				ps_command(pa, ps);
			ps_command(ra, ps);
		}

		while(ps->b->size > 0 && ps->b->head->content < ps->a->min)
			ps_command(pa, ps);
	}
	ps_min_to_top(ps);
}
