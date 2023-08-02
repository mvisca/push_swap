/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_utils_five.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:01:12 by mvisca-g          #+#    #+#             */
/*   Updated: 2023/08/02 15:37:45 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ps_sort_five(t_ps *ps)
{
	while (ps->a->size > 3)
	{
		ps_min_to_top(ps);
		ps_command(pb, ps);
	}
	ps_sort_three(ps);
	ps_command(pa, ps);
	ps_command(pa, ps);
}
