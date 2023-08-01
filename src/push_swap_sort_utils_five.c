/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_utils_five.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:01:12 by mvisca-g          #+#    #+#             */
/*   Updated: 2023/08/01 19:00:04 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	ps_isorder(t_ps *ps)
{
	t_ps_list	*current;
	t_ps_list	*following;

	current = ps->a->head;
	following = current->next;
	while (following)
	{
		if (current->content < following->content || \
			(current->content == ps->a->max && \
			following->content == ps->a->min))
		{
			current = following;
			following = current->next;
		}
		else
			return (FALSE);
	}
	return (TRUE);
}

void	ps_sort_five(t_ps *ps)
{
	t_ps_list	*current;
	t_ps_list	*next;

	current = ps->a->head;
	next = current->next;
	if (ps_isorder(ps))
		ps_min_to_top(ps);
	else
	{
		while (ps->a->size > 3)
		{
			
		}
	}
}
