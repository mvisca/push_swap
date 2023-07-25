/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 10:18:02 by mvisca            #+#    #+#             */
/*   Updated: 2023/07/25 16:04:53 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	min_to_top(t_ps *ps)
{
	while (ps->a->head->content != ps->a->min)
		ps_command(rra, ps);
}

void	sort_stack(t_ps *ps)
{
	if (ps->a->size == 2)
		sort_two(ps);
	else if (ps->a->size == 3)
		sort_three(ps);
	else
		sort_long(ps);
	min_to_top(ps);
	print_stacks(ps);
}
