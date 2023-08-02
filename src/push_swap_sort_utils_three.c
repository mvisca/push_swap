/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_utils_three.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 16:37:24 by mvisca            #+#    #+#             */
/*   Updated: 2023/08/02 19:40:23 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ps_sort_three(t_ps *ps)
{
	t_stack	*a;
	int		first;
	int		third;

	a = ps->a;
	first = a->head->content;
	third = a->head->next->next->content;
	if (first == a->min && third == a->max)
		return ;
	else if (first == a->min && !ps_command(sa, ps))
		ps_command(ra, ps);
	else if (first == a->max && third == a->min && !ps_command(sa, ps))
		ps_command(rra, ps);
	else if (first == a->max)
		ps_command(ra, ps);
	else if (third == a->max)
		ps_command(sa, ps);
	else if (third == a->min)
		ps_command(rra, ps);
}
