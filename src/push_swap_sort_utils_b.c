/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_utils_b.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:19:16 by mvisca            #+#    #+#             */
/*   Updated: 2023/07/28 13:41:02 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	insert_max_min(t_stack *b);

t_com	*prep_b(t_ps *ps, int num, int i)
{
	int			rotations;
	t_com		rot_type;
	t_com		*next_move;
	t_ps_list	*first;
	t_ps_list	*last;

	rotations = 0;
	rot_type = rb;
	first = ps->b->head;
	last = ps_lstlast(ps->b->head);
	if (num > ps->b->max || num < ps->b->min)
		rotations = insert_max_min(ps->b);
	else
	{
		while (first && !(num > first->content && num < last->content))
		{
			rotations++;
			last = first;
			first = first->next;
		}
	}
	if (rotations > (ps->b->size + 1) / 2)
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

static int	insert_max_min(t_stack *b)
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
