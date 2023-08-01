/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_utils_b.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:19:16 by mvisca            #+#    #+#             */
/*   Updated: 2023/08/01 19:16:37 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	ps_max_to_top(t_stack *b);
static int	ps_gap_to_top(t_ps *ps, int num);

t_com	*prep_b(t_ps *ps, int num)
{
	int			rotations;
	int			i;
	t_com		rot_type;
	t_com		*next_move;

	i = 0;
	rot_type = rb;
	if (num > ps->b->max || num < ps->b->min)
		rotations = ps_max_to_top(ps->b);
	else
		rotations = ps_gap_to_top(ps, num);
	if (rotations > (ps->b->size) / 2)
	{
		rot_type = rrb;
		rotations = ps->b->size - rotations;
	}
	next_move = (t_com *) malloc (sizeof(t_com) * (rotations + 1));
	while (i < rotations)
		next_move[i++] = rot_type;
	next_move[i] = end;
	return (next_move);
}

static int	ps_gap_to_top(t_ps *ps, int num)
{
	t_ps_list	*first;
	t_ps_list	*last;
	int			rotations;

	rotations = 0;
	first = ps->b->head;
	last = ps_lstlast(ps->b->head);
	while (first && !(num > first->content && num < last->content))
	{
		rotations++;
		last = first;
		first = first->next;
	}
	return (rotations);
}

static int	ps_max_to_top(t_stack *b)
{
	int			rotations;
	t_ps_list	*head;

	rotations = 0;
	head = b->head;
	while (head && head->content != b->max)
	{
		rotations++;
		head = head->next;
	}
	return (rotations);
}
