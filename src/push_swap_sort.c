/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 10:18:02 by mvisca            #+#    #+#             */
/*   Updated: 2023/07/26 11:41:43 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	ps_sorted(t_ps *ps);
static void	ps_min_to_top(t_ps *ps);

void	ps_sort_stack(t_ps *ps)
{
	if (!ps_sorted(ps))
	{
		if (ps->a->size == 2)
			sort_two(ps);
		else if (ps->a->size == 3)
			sort_three(ps);
		else
			sort_long(ps);
		ps_min_to_top(ps);
		print_stacks(ps);
	}
}

static int	ps_sorted(t_ps *ps)
{
	t_ps_list	*current;
	t_ps_list	*following;

	current = ps->a->head;
	following = current->next;
	while (current)
	{
		if (current->content > following->content)
			return (FALSE);
		following = current->next;
		current = current->next;
	}
	return (TRUE);
}

static void	ps_min_to_top(t_ps *ps)
{
	int			rotations;
	t_ps_list	*current;
	t_ps_list	*next;
	t_com		rot_type;

	current = ps->a->head;
	next = current->next;
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
