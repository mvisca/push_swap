/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_mem_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:02:50 by mvisca            #+#    #+#             */
/*   Updated: 2023/08/01 16:38:21 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ps_update_stack(t_stack *stack)
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

void	ps_free_stack(t_stack *stack)
{
	t_ps_list	*current;
	t_ps_list	*next;

	if (stack)
	{
		current = stack->head;
		while (current)
		{
			next = current->next;
			free(current);
			current = next;
		}
	}
	free(stack);
	stack = NULL;
}

void	ps_free_tab(char ***tab)
{
	int	i;

	i = 0;
	while ((*tab)[i])
	{
		free((*tab)[i]);
		(*tab)[i] = NULL;
		i++;
	}
	free(*tab);
	*tab = NULL;
}

int	ps_end_error(t_ps *ps, char ***tab, int msg)
{
	if (msg)
		write (2, "Error\n", 6);
	if (tab && *tab)
		ps_free_tab(tab);
	if (ps)
	{
		if (ps->a)
			ps_free_stack(ps->a);
		if (ps->b)
			ps_free_stack(ps->b);
		free(ps);
		ps = NULL;
	}
	exit (EXIT_FAILURE);
}
