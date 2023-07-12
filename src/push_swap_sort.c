/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 10:18:02 by mvisca            #+#    #+#             */
/*   Updated: 2023/07/12 17:35:15 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	sort_three(t_stack *a, t_stack *b)
{
	int	first;
	int	third;

	first = *(a->head->content);
	third = *(a->head->next->next->content);
	if (first == a->min && third == a->max)
		return ;
	else if (first == a->min)
	{
		make_a(sa, a, b);
		make_a(ra, a, b);
	}
	else if (first == a->max && third == a->min)
	{
		make_a(sa, a, b);
		make_a(rra, a, b);
	}
	else if (first == a->max)
		make_a(ra, a, b);
	else if (third == a->max)
		make_a(sa, a, b);
	else if (third == a->min)
		make_a(rra, a, b);
}

static t_com	*prep_b(t_stack *b, int num)
{
	t_com	*test;

	(void)num;	
	(void)b;
	test = (t_com *) malloc (sizeof(t_com) * 3);
	if (!test)
		return (NULL);
	test[0] = rb;
	test[1] = sb;
	test[2] = end;
	return (test);
}

static t_com	*prep_a_and_push(t_stack *a, t_com *test_moves)
{
	t_com	*test;
	int		i;

	(void)a;
	if (!test_moves)
		return (NULL);
	test = (t_com *) malloc (sizeof(test_moves) + (sizeof(t_com) * 3));
	if (!test)
		return (NULL);
	i = -1;
	while (test_moves[++i] != end)
		test[i] = test_moves[i];
	test[i++] = ra;
	test[i++] = sa;
	test[i++] = pb;
	test[i] = end;
	free(test_moves);
	return (test);
}

static t_com	*get_cheapest(t_com *cheapest_move, t_com *test_move)
{
	if (sizeof(cheapest_move) > sizeof(test_move))
	{
		free(cheapest_move);
		cheapest_move = test_move;
	}
	else
		free(test_move);
	return (cheapest_move);
}

static t_com	*cheapest_move(t_stack *a, t_stack *b)
{
	t_com	*test_move;
	t_com	*cheapest_move;
	t_list	*current;

	cheapest_move = prep_b(b, *(a->head->content));
	cheapest_move = prep_a_and_push(a, cheapest_move);
	current = a->head->next;
	while (current)
	{
		test_move = prep_b(b, *(current->content));
		test_move = prep_a_and_push(a, test_move);
		cheapest_move = get_cheapest(cheapest_move, test_move);
		current = current->next;
	}
	return (cheapest_move);
}

void	sort_stack(t_stack *a, t_stack *b)
{
	int 	two;
	int		i;
	t_com	*next_move;

	two = 2;
	while (a->size > 3 && two--)
		make_a(pb, a, b);
	i = 0;
	while (a->size > 3)
	{
		next_move = cheapest_move(a, b);
		while (next_move[i] != end)
			make_a(next_move[i++], a, b);
	}
	sort_three(a, b);
	while (b->size > 0)
			make_a(pa, a, b);
	while (*(a->head->content) > a->min)
	{
		make_a(rra, a, b);
		update_stack(&a);
	}
}
