/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_mem_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:02:50 by mvisca            #+#    #+#             */
/*   Updated: 2023/07/25 19:17:03 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static t_stack	*ps_free_stack(t_stack *stack)
{
	t_ps_list	*node;
	t_ps_list	*next;

	node = stack->head;
	while (node)
	{
		next = node->next;
		free(node);
		node = next;
	}
	return (NULL);
}

void	*ps_free(t_ps *ps)
{
	if (ps->a)
	{
		ps_free_stack(ps->a);
		free(ps->a);
		ps->a = NULL;
	}
	if (ps->b)
	{
		ps_free_stack(ps->b);
		free(ps->b);
		ps->b = NULL;
	}
	free(ps);
	ps = NULL;
	return (NULL);
}

void	update_stack(t_stack *stack)
{
	t_ps_list	*node;

	stack->max = INT_MIN;
	stack->min = INT_MAX;
	node = stack->head;
	while (node)
	{
		if (node->content > stack->max)
			stack->max = node->content;
		if (node->content < stack->min)
			stack->min = node->content;
		node = node->next;
	}
	stack->size = ps_lstsize(stack->head);
}
