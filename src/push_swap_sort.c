/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 10:18:02 by mvisca            #+#    #+#             */
/*   Updated: 2023/07/22 17:04:18 by mvisca           ###   ########.fr       */
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
		// ft_printf("test\n");
		// print_moves(cheapest_move);
		// ft_printf("end test\n");
		// ft_printf("cheapest\n");
		// print_moves(cheapest_move);
		// ft_printf("end cheapest\n");
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

void	sort_stack(t_stack *a, t_stack *b)
{
	int 	two;
	int		i;
	t_com	*next_move;

	two = 2;
	while (a->size > 3 && two--)
		make_a(pb, a, b);
	while (a->size > 0)
	{
		next_move = get_next_move(a, b);
		// next_move = optimize_move(next_move);
		i = 0;
		while (next_move[i] != end)
			make_a(next_move[i++], a, b);
		free(next_move);
		make_a(pb, a, b);
	}
//	sort_three(a, b);
//	move_b_to_a(a, b);
	while (b->size > 0)
		make_a(pa, a, b);
	while (a->min != *(a->head->content))
		make_a(ra, a, b);
//	print_stacks(a->head, b->head);
}
