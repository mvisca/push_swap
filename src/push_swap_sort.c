/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 10:18:02 by mvisca            #+#    #+#             */
/*   Updated: 2023/07/11 13:07:39 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sort_stack(t_stack *a, t_stack *b)
{
	int two;
	int	i;
	enum e_command	*next_move;


	print_stacks(a->head, b->head);
	two = 2;
	while (a->size > 3 && two--)
	{
		make_a(pb, a, b);
		print_stacks(a->head, b->head);
	}
	i = 0;
	while (a->size > 3)
	{
		next_move = cheapest_move(a, b);
		while (ft_strncmp(next_move[i], "end", 3) != 0)
		{
			make_a(next_move[i++], a, b);
			print_stacks(a->head, b->head);
		}
	}
	sort_tail(a);
	while (b->size > 0)
	{
		make_a(pa, a, b);
		print_stacks(a->head, b->head);
	}	
}
