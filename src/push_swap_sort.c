/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 10:18:02 by mvisca            #+#    #+#             */
/*   Updated: 2023/07/24 16:35:39 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	min_to_top(t_stack *a)
{
	while (*(a->head->content) != a->min)
		make_a(rra, a, a);
}

void	sort_stack(t_stack *a, t_stack *b)
{	
	if (a->size == 2)
		sort_two(a);
	else if (a->size == 3)
		sort_three(a, b);
	else
		sort_long(a, b);
	min_to_top(a);
	print_stacks(a->head, b->head);
}
