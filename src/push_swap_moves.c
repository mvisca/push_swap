/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:02:30 by mvisca            #+#    #+#             */
/*   Updated: 2023/07/06 14:52:21 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	do_push(t_list **src, t_list **dest)
{
	t_list	*aux;

	aux = *src;
	if (aux)
	{
		*src = (*src)->next;
		ft_lstadd_front(dest, aux);
	}
	return (1);
}

static int	do_swap(t_list **lst)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	first = NULL;
	second = NULL;
	third = NULL;
	if (lst && *lst)
		first = *lst;
	if (first && first->next)
		second = first->next;
	if (first && second && second->next)
		third = second->next;
	if (!third)
		return (1);
	first->next = third;
	second->next = first;
	*lst = second;
	return (1);
}

static int	do_revrot(t_list **lst)
{
	t_list	*new_last;
	t_list	*last;

	if (lst && *lst && ft_lstsize(*lst) > 1)
		last = *lst;
	else
		return (1);
	while (last && last->next)
	{
		new_last = last;
		last = last->next;		
	}
	last->next = *lst;
	*lst = last;
	new_last->next = NULL;
	return (1);
}

static int	do_rot(t_list **lst)
{
	t_list	*first;
	t_list	*last;

	if (lst && *lst && ft_lstsize(*lst) > 1)
		first = *lst;
	else
		return (1);
	last = ft_lstlast(*lst);
	*lst = (*lst)->next;
	last->next = first;
	first->next = NULL;
	return (1);
}

void    make_a(enum operand move, t_list **stack_a, t_list **stack_b)
{
	if (move == pa && ft_printf("pa\n"))
		do_push(stack_b, stack_a);
	else if (move == pb && ft_printf("pb\n"))
		do_push(stack_a, stack_b);
	else if (move == sa && ft_printf("sa\n"))
		do_swap(stack_a);
	else if (move == sb && ft_printf("sb\n"))
		do_swap(stack_b);
	else if (move == ss && ft_printf("ss\n") && do_swap(stack_a))
		do_swap(stack_b);
	else if (move == ra && ft_printf("ra\n"))
		do_rot(stack_a);
	else if (move == rb && ft_printf("rb\n"))
		do_rot(stack_b);
	else if (move == rr && ft_printf("rr\n") && do_rot(stack_a))
		do_rot(stack_b);
	else if (move == rra && ft_printf("rra\n"))
		do_revrot(stack_a);
	else if (move == rrb && ft_printf("rrb\n"))
		do_revrot(stack_b);
	else if (move == rrr && ft_printf("rrr\n") && do_revrot(stack_a))
		do_revrot(stack_b);
}