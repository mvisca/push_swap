/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:02:30 by mvisca            #+#    #+#             */
/*   Updated: 2023/08/05 00:14:08 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	do_swap(t_stack *stack);
static int	do_revrot(t_stack *stack);
static int	do_rot(t_stack *stack);
static int	do_push(t_stack *src, t_stack *dest);

void	*ps_command(t_com move, t_ps *ps)
{
	if (move == pa && ft_printf("pa\n"))
		do_push(ps->b, ps->a);
	else if (move == pb && ft_printf("pb\n"))
		do_push(ps->a, ps->b);
	else if (move == sa && ft_printf("sa\n"))
		do_swap(ps->a);
	else if (move == sb && ft_printf("sb\n"))
		do_swap(ps->b);
	else if (move == ss && ft_printf("ss\n") && do_swap(ps->a))
		do_swap(ps->b);
	else if (move == ra && ft_printf("ra\n"))
		do_rot(ps->a);
	else if (move == rb && ft_printf("rb\n"))
		do_rot(ps->b);
	else if (move == rr && ft_printf("rr\n") && do_rot(ps->a))
		do_rot(ps->b);
	else if (move == rra && ft_printf("rra\n"))
		do_revrot(ps->a);
	else if (move == rrb && ft_printf("rrb\n"))
		do_revrot(ps->b);
	else if (move == rrr && ft_printf("rrr\n") && do_revrot(ps->a))
		do_revrot(ps->b);
	return (NULL);
}

static int	do_swap(t_stack *stack)
{
	t_ps_list	*first;
	t_ps_list	*second;
	t_ps_list	*third;

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
	t_ps_list	*before_last;
	t_ps_list	*last;

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
	t_ps_list	*last;

	if (stack->size < 1)
		return (1);
	last = ps_lstlast(stack->head);
	last->next = stack->head;
	stack->head = stack->head->next;
	last->next->next = NULL;
	return (1);
}

static int	do_push(t_stack *src, t_stack *dest)
{
	t_ps_list	*aux;

	aux = src->head;
	if (aux)
	{
		src->head = src->head->next;
		ps_lstadd_front(&(dest->head), aux);
	}
	ps_update_stack(src);
	ps_update_stack(dest);
	return (1);
}
