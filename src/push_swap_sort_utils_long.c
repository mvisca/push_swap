/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_utils_long.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:28:38 by mvisca            #+#    #+#             */
/*   Updated: 2023/08/04 12:56:38 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static t_com	*ps_get_best_move(t_ps *ps);

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

static t_com	*ps_get_best_move(t_ps *ps)
{
	t_com		*test_move;
	t_com		*best_move;
	t_ps_list	*current;
	int			node_num;

	node_num = 1;
	best_move = prep_b(ps, ps->a->head->content);
	best_move = prep_a(ps, ps->a->head->content, best_move);
	current = ps->a->head->next;
	while (current && node_num < (ps->a->size / 2))
	{
		test_move = prep_b(ps, current->content);
		test_move = prep_a(ps, current->content, test_move);
		if (ps_cost_to_move(test_move) < ps_cost_to_move(best_move))
		{
			free(best_move);
			best_move = test_move;
			node_num++;
		}
		else
			free(test_move);
		current = current->next;
	}
	return (best_move);
}
