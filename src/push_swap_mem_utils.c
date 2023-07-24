/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_mem_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:02:50 by mvisca            #+#    #+#             */
/*   Updated: 2023/07/24 19:14:48 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_stack	*free_stack(t_stack **stack)
{
	t_list	*node;
	t_list	*next;

	if (*stack)
		node = (*stack)->head;
	while (node)
	{
		next = node->next;
		free(node->content);
		free(node);
		node = next;
	}
	free(*stack);
	stack = NULL;
	return (NULL);
}

t_stack	*alloc_stack(void)
{
	t_stack	*stack;

	stack = malloc (sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->head = NULL;
	stack->max = INT_MIN;
	stack->min = INT_MAX;
	stack->size = 0;
	return (stack);
}

char	*free_tab(char ***tab)
{
	int	i;

	if (!(*tab) || !(*(*tab)))
		return (NULL);
	i = 0;
	while ((*tab)[i])
	{
		free((*tab)[i]);
		(*tab)[i] = NULL;
		i++;
	}
	free((*tab));
	tab = NULL;
	return (NULL);
}

void	update_stack(t_stack **stack)
{
	t_list	*node;

	(*stack)->max = INT_MIN;
	(*stack)->min = INT_MAX;
	node = (*stack)->head;
	while (node)
	{
		if (*(node->content) > (*stack)->max)
			(*stack)->max = *(node->content);
		if (*(node->content) < (*stack)->min)
			(*stack)->min = *(node->content);
		node = node->next;
	}
	(*stack)->size = ft_lstsize((*stack)->head);
}

void	*free_ps(t_ps *ps)
{
	if (ps->a)
		free_stack(&ps->a);
	if (ps->b)
		free_stack(&ps->b);
	if (ps->tab)
		free_tab(&ps->tab);
	free(ps);
	return (NULL);
}