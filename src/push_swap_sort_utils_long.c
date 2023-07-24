/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_utils_long.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:28:38 by mvisca            #+#    #+#             */
/*   Updated: 2023/07/24 19:13:34 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	move_cost(t_com *moves)
{
	int	i;

	i = 0;
	while (moves[i] != end)
		i++;
	return (i);
}

static t_com	*get_next_move(t_stack *a, t_stack *b)
{
	t_com	*test_move;
	t_com	*cheapest_move;
	t_list	*current;

	cheapest_move = prep_b(b, *(a->head->content));
	cheapest_move = prep_a(a, a->head, cheapest_move);
	current = a->head->next;
	while (current)
	{
		test_move = prep_b(b, *(current->content));
		test_move = prep_a(a, current, test_move);
		if (move_cost(test_move) < move_cost(cheapest_move))
		{
			free(cheapest_move);
			cheapest_move = test_move;
			test_move = NULL;
		}
		else
			free(test_move);
		current = current->next;
	}
	return (cheapest_move);
}

void sort_long(t_ps *ps)
{
	int		two;
	int		i;
	t_com	*next_move;

	two = 2;
	while (ps->a->size > 3 && two--)
		ps_command(pb, ps);
	while (ps->a->size > 3)
	{
		next_move = get_next_move(ps->a, ps->b);
		// next_move = optimize_move(next_move);
		i = 0;
		while (next_move[i] != end)
			ps_command(next_move[i++], ps);
		free(next_move);
		ps_command(pb, ps);
	}
	sort_three(ps);
	//	move_b_to_a(a, b);
	while (ps->b->size > 0)
		ps_command(pa, ps);
	// while (a->min != *(a->head->content))
	// 	make_a(ra, a, b);
}