/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_utils_b2a.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 11:06:15 by mvisca            #+#    #+#             */
/*   Updated: 2023/08/05 00:13:45 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	ps_b2a_curr_min_max_curr(int curr, t_ps *ps);
static void	ps_b2a_min_curr_max(int curr, t_ps *ps);
static void	ps_do_rotations(int rotations, t_com rot_type, t_ps *ps);

void	ps_move_b_to_a(t_ps *ps)
{
	t_ps_list	*curr;
	int			stop;

	stop = 0;
	while (ps->b->size && !stop)
	{
		curr = ps->b->head;
		stop = 0;
		if (curr->content > ps->a->max || curr->content < ps->a->min)
			ps_b2a_curr_min_max_curr(curr->content, ps);
		else
			ps_b2a_min_curr_max(curr->content, ps);
	}
}

static void	ps_b2a_curr_min_max_curr(int curr, t_ps *ps)
{
	(void)curr;
	ps_min_to_top(ps);
	ps_command(pa, ps);
}

static void	ps_b2a_min_curr_max(int curr, t_ps *ps)
{
	int			rotations;
	t_com		rot_type;
	t_ps_list	*first;
	t_ps_list	*last;

	rotations = 0;
	rot_type = ra;
	first = ps->a->head;
	last = ps_lstlast(ps->a->head);
	while (!(curr > last->content && curr < first->content))
	{
		rotations++;
		last = first;
		first = first->next;
	}
	if (rotations > (ps->a->size / 2))
	{
		rotations = ps->a->size - rotations;
		rot_type = rra;
	}
	ps_do_rotations(rotations, rot_type, ps);
	ps_command(pa, ps);
}

static void	ps_do_rotations(int rotations, t_com rot_type, t_ps *ps)
{
	while (rotations--)
		ps_command(rot_type, ps);
}
