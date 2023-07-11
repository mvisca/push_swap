/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 10:18:02 by mvisca            #+#    #+#             */
/*   Updated: 2023/07/11 17:35:52 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	sort_three(t_stack *a, t_stack *b)
{
	int	first;
	int	third;

	first = *(a->head->content);
	third = *(a->head->next->next->content);
	
	if (first == a->min && third < a->max) 		// 1 3 2
	{
		make_a(sa, a, b);
		make_a(rr, a, b);
	}
	else if (first == a->max && third == a->min) // 3 2 1
	{
		make_a(sa, a, b);
		make_a(rrr, a, b);
	}
	else if (first == a->max) 					// 3 1 2
		make_a(rr, a, b);
	else if (third == a->max) 					// 2 1 3
		make_a(sa, a, b);
	else if (third == a->min) 					// 2 3 1
		make_a(rrr, a, b);
	return ; 									// 1 2 3
	
}

static e_com	*prep_b(t_stack *b, int num)
{
/*	t_list	*current;
	t_list	*last;
	e_com	*test_moves;
	int		count;

	count = 0;
	current = b->head;
	while (current)
	{
		if (num < *(current->content) && num > *(current->next->content))


	}
	*/
	e_com	*test;

	(void)num;	
	(void)b;
	test = (e_com *) malloc (sizeof(e_com) * 3);
	if (!test)
		return (NULL);
	test[0] = rb;
	test[1] = sb;
	test[2] = end;
	return (test);
}

static e_com	*prep_a_and_push(t_stack *a, e_com *test_moves)
{
	e_com	*test;
	int		i;

	(void)a;
	if (!test_moves)
		return (NULL);
	test = (e_com *) malloc (sizeof(test_moves) + (sizeof(e_com) * 3));
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

static e_com	*get_cheapest(e_com *cheapest_move, e_com *test_move)
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

static e_com	*cheapest_move(t_stack *a, t_stack *b)
{
	e_com	*test_move;
	e_com	*cheapest_move;
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
	e_com	*next_move;

	print_stacks(a->head, b->head);
	two = 2;
	while (a->size > 3 && two--)
	{
		make_a(pb, a, b);
		print_stacks(a->head, b->head);
	}
	i = 0;
	while (a->size > 3)
	{
		next_move = cheapest_move(a, b);
		while (next_move[i] != end)
		{
			make_a(next_move[i++], a, b);
			print_stacks(a->head, b->head);
		}
	}
	sort_three(a, b);
	while (b->size > 0)
	{
			make_a(pa, a, b);
			print_stacks(a->head, b->head);
	}	
	print_stacks(a->head, b->head);
}
