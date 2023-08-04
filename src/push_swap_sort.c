/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 10:18:02 by mvisca            #+#    #+#             */
/*   Updated: 2023/08/04 13:02:41 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ps_sort_stack(t_ps *ps);
int		ps_sorted(t_ps *ps);
int		ps_cost_to_move(t_com *moves);
int		ps_max_to_top(t_ps *ps);
void	ps_min_to_top(t_ps *ps);

void	ps_sort_stack(t_ps *ps)
{
	if (!ps_sorted(ps))
	{
		if (ps->a->size == 2)
			ps_sort_two(ps);
		else if (ps->a->size == 3)
			ps_sort_three(ps);
		else if (ps->a->size < 6)
			ps_sort_five(ps);
		else
			ps_sort_long(ps);
		ps_min_to_top(ps);
	}
}

int	ps_sorted(t_ps *ps)
{
	t_ps_list	*current;
	t_ps_list	*following;

	current = ps->a->head;
	if (current)
		following = current->next;
	while (current && following)
	{
		if (current->content > following->content)
			return (FALSE);
		current = current->next;
		following = current->next;
	}
	return (TRUE);
}

int	ps_cost_to_move(t_com *moves)
{
	int	i;

	i = 0;
	while (moves[i] != end)
		i++;
	return (i);
}

void	ps_min_to_top(t_ps *ps)
{
	int			rotations;
	t_ps_list	*current;
	t_com		rot_type;

	current = ps->a->head;
	rot_type = ra;
	rotations = 0;
	while (current->content != ps->a->min)
	{
		current = current->next;
		rotations++;
	}
	if (rotations > ps->a->size / 2)
	{
		rot_type = rra;
		rotations = ps->a->size - rotations;
	}
	while (rotations--)
		ps_command(rot_type, ps);
}

int	ps_max_to_top(t_ps *ps)
{
	int			rotations;
	t_ps_list	*head;

	rotations = 0;
	head = ps->b->head;
	while (head && head->content != ps->b->max)
	{
		rotations++;
		head = head->next;
	}
	return (rotations);
}
