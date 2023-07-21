/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_utils_b.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:19:16 by mvisca            #+#    #+#             */
/*   Updated: 2023/07/21 17:12:04 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*
static void	update_max_min(t_stack *b, int num)
{
	if (num > b->max)
		b->max = num;
	if (num < b->min)
		b->min = num;
}
*/

static int	insert_max_min(t_stack *b, int num)
{
	t_list	*first;	
	int		rotations;
	
	(void)num;
	rotations = 0;
	first = b->head;
	while (first && *(first->content) != b->max)
	{
		first = first->next;
		rotations++;
	}
	return (rotations);
}

static int	insert_mid(t_stack *b, int num)
{
	t_list	*first;
	t_list	*last;
	int		rotations;

	rotations = 0;
	last = b->head; // head es ultimo porque le rb
	first = last->next; // next es primero porque despues rb qued arriba
	// num tiene que ser mayor que firts y menor que last6
	while (first && !(num < *(last->content) && num > *(first->content)))
	{
		rotations++;
		last = last->next;
		first = last->next;
	}
	return (rotations +1);
}

t_com	*prep_b(t_stack *b, int num)
{
	int		rotations;
	t_com	rot_type;
	t_com	*next_move;

	rot_type = rb;
	if (num > b->max || num < b->min)
		rotations = insert_max_min(b, num);
	else
		rotations = insert_mid(b, num);
	if (rotations > (b->size / 2))
	{
		rot_type = rrb;
		rotations = b->size - rotations;
	}
	next_move = (t_com *) malloc (sizeof(t_com) * (rotations + 1));
	next_move[rotations--] = end;
	while (rotations > 0)
		next_move[--rotations] = rot_type;
	return (next_move);
}