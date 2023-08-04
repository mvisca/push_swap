/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_list_tools.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 23:08:00 by mvisca-g          #+#    #+#             */
/*   Updated: 2023/08/04 12:47:15 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_ps_list	*ps_lstnew(int content);
void		ps_lstadd_back(t_ps_list **head, t_ps_list *node);
void		ps_lstadd_front(t_ps_list **head, t_ps_list *node);
t_ps_list	*ps_lstlast(t_ps_list *lst);
int			ps_lstsize(t_ps_list *head);

t_ps_list	*ps_lstnew(int content)
{
	t_ps_list	*new;

	new = (t_ps_list *) malloc (sizeof(t_ps_list));
	if (new)
	{
		new->content = content;
		new->next = NULL;
	}
	return (new);
}

void	ps_lstadd_back(t_ps_list **head, t_ps_list *node)
{
	t_ps_list	*tmp;

	if (!head)
		return ;
	if (!*head)
	{
		*head = node;
		return ;
	}
	tmp = ps_lstlast(*head);
	tmp->next = node;
}

void	ps_lstadd_front(t_ps_list **head, t_ps_list *node)
{
	node->next = *head;
	*head = node;
}

t_ps_list	*ps_lstlast(t_ps_list *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

int	ps_lstsize(t_ps_list *head)
{
	int		ncount;

	ncount = 0;
	while (head)
	{
		head = head->next;
		ncount++;
	}
	return (ncount);
}
