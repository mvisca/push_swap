/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_utils_b_to_a.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 14:40:35 by mvisca            #+#    #+#             */
/*   Updated: 2023/07/22 16:24:41 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void    move_b_to_a(t_stack *a, t_stack *b)
{
	t_list	*la;
	t_list	*lb;

	while (b->size > 0)
	{
		la = a->head;
		lb = b->head;
		(void)lb;
		(void)la;
	}
}