/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:02:50 by mvisca            #+#    #+#             */
/*   Updated: 2023/07/09 13:03:01 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	*free_ptr(void *ptr)
{
	free(ptr);
	ptr = NULL;
	return (NULL);
}

t_stack	*free_stack(t_stack **stack)
{
	t_list	*list;

	list = (*stack)->head;
	ft_lstclear(&((*stack)->head), &free_ptr);
	stack = NULL;
	return (NULL);
}

t_stack	*alloc_stack(t_stack **stack)
{
	*stack = (t_stack *) malloc (sizeof(t_stack) * 1);
	if (!(*stack))
		return (NULL);
	(*stack)->head = NULL;
	(*stack)->max = INT_MIN;
	(*stack)->min = INT_MAX;
	(*stack)->size = 0;
	return *(stack);
}

char    *free_tab(char ***tab)
{
	int i;

	i = 0;
	while (*tab && (*tab)[i])
	{
		free((*tab)[i]);
		i++;
	}
	if ((*tab)[i])
		free((*tab)[i]);
	free(*tab);
	*tab = NULL;
	return (NULL);
}
