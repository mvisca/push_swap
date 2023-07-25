/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_utils_a.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 11:19:14 by mvisca            #+#    #+#             */
/*   Updated: 2023/07/25 16:06:49 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_com	*prep_a(t_stack *a, t_ps_list *node, t_com *test_moves)
{
	int			rotations;
	int     	size;
	int  	   i;
	t_com		rot_type;
	t_com		*next_move;
	t_ps_list	*current;

	rotations = 0;
	rot_type = ra;

	current = a->head;
	while (current->content != node->content)
	{
		current = current->next;
		if (!current)
			current = a->head;
		rotations++;
	}	

	if (rotations > (a->size / 2))
	{
		rot_type = rra;
		rotations = a->size - rotations;
	}

	size = move_cost(test_moves);
	next_move = (t_com *) malloc (sizeof(t_com) * (rotations + size + 1));
	if (!next_move)
	{
		free(test_moves);
		return (NULL);
	}
	i = 0;
	while (test_moves[i] != end)
	{
		next_move[i] = test_moves[i];
		i++;
	}
	while (i < rotations + size)
		next_move[i++] = rot_type;
	next_move[i] = end;
	free(test_moves);
	return (next_move);
}