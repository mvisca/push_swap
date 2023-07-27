/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_utils_b.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:19:16 by mvisca            #+#    #+#             */
/*   Updated: 2023/07/26 19:47:17 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	insert_max_min(t_stack *b);
static int	insert_mid(t_stack *b, int num);

t_com	*prep_b(t_stack *b, int num)
{
	int		rotations;
	t_com	rot_type;
	t_com	*next_move;
	int		i;

	rot_type = rb;
	if (num > b->max || num < b->min)
		rotations = insert_max_min(b);
	else
		rotations = insert_mid(b, num);
	if (rotations < 0)
	{
		rot_type = rrb;
		rotations *= -1;
	}
	next_move = (t_com *) malloc (sizeof(t_com) * (rotations + 1));
	i = 0;
	while (i < rotations)
		next_move[i++] = rot_type;
	next_move[i] = end;
	return (next_move);
}

static int	insert_max_min(t_stack *b)
{
	t_ps_list	*current;	
	int		rotations;
	
	rotations = 0;
	current = b->head;
	while (current && current->content != b->max)
	{
		rotations++;
		current = current->next;
	}
	if (rotations > b->size / 2)
	{
		rotations = b->size - rotations;
		rotations *= -1;
	}
	return (rotations);
}

static int	insert_mid(t_stack *b, int num)
{
	t_ps_list	*current;
	int			rotations;

	current = b->head;
	rotations = 0;

	while (current->content != b->max)
	{
		rotations++;
		current = current->next;
	}
	if (rotations > b->size / 2)
	{
		rotations = b->size - rotations;
		rotations *= -1;	
	}
	while (num < current->content)
	{
		rotations++;
		if (current->next)
			current = current->next;
		else
			current = b->head;
	}
	return (rotations);
}
