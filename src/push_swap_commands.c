/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:02:30 by mvisca            #+#    #+#             */
/*   Updated: 2023/07/09 16:10:10 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	do_push(t_stack *src, t_stack *dest)
{
	t_list	*aux;

	aux = src->head;
	if (aux)
	{
		src->head = src->head->next;
		ft_lstadd_front(&(dest->head), aux);
	}
	update_stack(&src);
	update_stack(&dest);
	return (1);
}

static int	do_swap(t_stack *stack)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	if (!stack->head || !stack->head->next)
		return (1);
	first = stack->head;
	second = first->next;
	third = second->next;
	stack->head = second;
	stack->head->next = first;
	stack->head->next->next = third;
	return (1);
}

static int	do_revrot(t_stack *stack)
{
	t_list	*before_last;
	t_list	*last;

	if (stack->size < 2)
		return (1);
	before_last = stack->head;
	last = before_last->next;
	while (last->next)
	{
		before_last = last;
		last = last->next;		
	}
	last->next = stack->head;
	stack->head = last;
	before_last->next = NULL;
	return (1);
}

static int	do_rot(t_stack *stack)
{
	t_list	*last;

	if (stack->size < 1)
		return (1);
	last = ft_lstlast(stack->head);
	last->next = stack->head;
	stack->head = stack->head->next;
	last->next->next = NULL;
	return (1);
}

void    make_a(enum command move, t_stack *a, t_stack *b)
{
	if (move == pa && ft_printf("pa\n"))
		do_push(b, a);
	else if (move == pb && ft_printf("pb\n"))
		do_push(a, b);
	else if (move == sa && ft_printf("sa\n"))
		do_swap(a);
	else if (move == sb && ft_printf("sb\n"))
		do_swap(b);
	else if (move == ss && ft_printf("ss\n") && do_swap(a))
		do_swap(b);
	else if (move == ra && ft_printf("ra\n"))
		do_rot(a);
	else if (move == rb && ft_printf("rb\n"))
		do_rot(b);
	else if (move == rr && ft_printf("rr\n") && do_rot(a))
		do_rot(b);
	else if (move == rra && ft_printf("rra\n"))
		do_revrot(a);
	else if (move == rrb && ft_printf("rrb\n"))
		do_revrot(b);
	else if (move == rrr && ft_printf("rrr\n") && do_revrot(a))
		do_revrot(b);
}