/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_utils_a.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 11:19:14 by mvisca            #+#    #+#             */
/*   Updated: 2023/08/01 19:37:05 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>


static t_com	*ps_join_move(int rotations, t_com rot_type, t_com *best_move)
{
	int		i;
	int		size;
	t_com	*new_move;

	size = ps_cost_to_move(best_move);
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

t_com	*prep_a(t_ps *ps, int content, t_com *best_move)
{
	int			rotations;
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
	new_move = ps_join_move(rotations, rot_type, best_move);
	return (new_move);
}
