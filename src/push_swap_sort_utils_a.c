/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_utils_a.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 11:19:14 by mvisca            #+#    #+#             */
/*   Updated: 2023/08/03 13:35:50 by mvisca           ###   ########.fr       */
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
/*
static void	ps_optimize_move(t_com **move, t_com ma, t_com mb, t_com mr)
{
	int	i;
	int	j;

	i = 0;
	while ((*move)[i] != end && (*move)[i + 1] != end)
	{
		j = i + 1;
		while ((*move)[j] != end)
		{
			if ((*move)[i] == ma && (*move)[j] == mb)
			{
				(*move)[i] = mr;
				(*move)[j] = skip;
			}
			j++;
		}	
		i++;
	}
}
*/

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
		rotations++;
	}
	if (rotations > (ps->a->size / 2))
	{
		rot_type = rra;
		rotations = ps->a->size - rotations;
	}
	new_move = ps_join_move(rotations, rot_type, best_move);
//	ps_optimize_move(&new_move, ra, rb, rr);
//	ps_optimize_move(&new_move, rra, rrb, rrr);
//	print_moves(new_move);
	return (new_move);
}
