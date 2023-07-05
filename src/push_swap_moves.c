/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:02:30 by mvisca            #+#    #+#             */
/*   Updated: 2023/07/04 18:16:20 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int static	do_push(t_list **src, t_list **dest)
{
	t_list	*aux;

	aux = *src;
	*src = *(src->next);
	ft_lstadd_front(dest, aux);
	return (1);
}

int static	do_swap(t_list **lst)
{
	t_list	*first;
	t_list	*second;
	t_lsit	*third;

	first = *lst;
	second = first->next;
	third = second->next;
	first->next = third;
	second->next = first;
	*lst = second;
	return (1);
}

int static	do_rot(t_list **lst)
{
	t_list	*new_last;
	t_list	*last;

	last = *lst;
	while (last && last->next)
	{
		new_last = last;
		last = last->next;		
	}
	last->next = *lst;
	*lst = last;
	new_last->next = NULL;
}

int static	do_revrot(t_list **lst)
{
	t_list	*first;
	t_list	*last;

	first = *lst;
	last = ft_lstlast(*lst);
	*lst = *lst->next;
	last->next = first;
	first->next = NULL;
}

void    make_a(enum operand move, t_list **stack_a, t_list **stack_b)
{
	if (move == pa && do_push(stack_a, stack_b))
		;
	else if (move == pb && do_push(stack_b, stack_a))
		;
	else if (move == sa && do_swap(stack_a))
		;
	else if (move == sb && do_swap(stack_b))
		;
	else if (move == ss && do_swap(stack_a) && do_swap(stack_b))
		;
	else if (move == ra && do_rot(stack_a))
		;
	else if (move == rb && do_rot(stack_b))
		;
	else if (move == rr && do_rot(stack_a) && do_rot(stack_b))
		;
	else if (move == rra && do_revrot(stack_a))
		;
	else if (move == rrb && do_revrot(stack_b))
		;
	else if (move == rrr && do_revrot(stack_a) && do_revrot(stack_b))
		;
}