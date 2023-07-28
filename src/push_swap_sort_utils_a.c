/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_utils_a.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 11:19:14 by mvisca            #+#    #+#             */
/*   Updated: 2023/07/28 12:49:12 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_com	*prep_a(t_ps *ps, int content, t_com *best_move)
{
	int			rotations;
	int     	size;
	int			i;
	t_com		rot_type;
	t_com		*new_move;
	t_ps_list	*current;

	rotations = 0;
	rot_type = ra;

	current = ps->a->head;
	while (current->content != content)
	{
		current = current->next;
		if (!current)
			current = ps->a->head;
		rotations++;
	}	

	if (rotations > (ps->a->size / 2))
	{
		rot_type = rra;
		rotations = ps->a->size - rotations;
	}

	size = ps_move_cost(best_move);
	new_move = (t_com *) malloc (sizeof(t_com) * (rotations + size + 1));
	if (!new_move)
	{
		free(best_move);
		return (NULL);
	}
	i = 0;
	while (best_move[i] != end)
	{
		new_move[i] = best_move[i];
		i++;
	}
	while (i < rotations + size)
		new_move[i++] = rot_type;
	new_move[i] = end;
	free(best_move);
	return (new_move);
}