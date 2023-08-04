/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_utils_b.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:19:16 by mvisca            #+#    #+#             */
/*   Updated: 2023/08/04 13:01:52 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	ps_gap_to_top(t_ps *ps, int num);

t_com	*prep_b(t_ps *ps, int num)
{
	t_com		*next_move;
	t_com		rot_type;
	int			i;
	int			rotations;

	i = 0;
	rot_type = rb;
	if (num > ps->b->max || num < ps->b->min)
		rotations = ps_max_to_top(ps);
	else
		rotations = ps_gap_to_top(ps, num);
	if (rotations > (ps->b->size / 2))
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
	int			rotations;
	t_ps_list	*first;
	t_ps_list	*last;

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
