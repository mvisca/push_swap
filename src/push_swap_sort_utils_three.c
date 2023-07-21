/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_utils_three.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 16:37:24 by mvisca            #+#    #+#             */
/*   Updated: 2023/07/21 16:40:41 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sort_three(t_stack *a, t_stack *b)
{
	int	first;
	int	third;

	first = *(a->head->content);
	third = *(a->head->next->next->content);
	if (first == a->min && third == a->max)
		return ;
	else if (first == a->min && !make_a(sa, a, b))
		make_a(ra, a, b);
	else if (first == a->max && third == a->min && !make_a(sa, a, b))
		make_a(rra, a, b);
	else if (first == a->max)
		make_a(ra, a, b);
	else if (third == a->max)
		make_a(sa, a, b);
	else if (third == a->min)
		make_a(rra, a, b);
}