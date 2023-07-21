/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 10:18:02 by mvisca            #+#    #+#             */
/*   Updated: 2023/07/21 16:35:38 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static t_com	*prep_a(t_stack *a, t_list *node, t_com *test_moves)
{
	int				rotations;
	unsigned long	size;
	t_com			rot_type;
	t_com			*next_move;
	t_list			*current;
	
	rotations = 0;
	rot_type = ra;
	current = a->head;
	while (*(current->content) != *(node->content))
	{
		current = current->next;
		rotations++;
	}	
	if (rotations > (a->size / 2))
	{
		rot_type = rra;
		rotations = a->size - rotations;
	}
	size = 0;
	while (test_moves[size] != end)
		size++;
	next_move = (t_com *) malloc (sizeof(t_com) * (rotations + size + 1));
	if (!next_move)
	{
		free(test_moves);
		return (NULL);
	}
	next_move[rotations + size] = end;
	while (rotations > 0)
		next_move[--rotations + size] = rot_type;
	while (size > 0)
	{
		next_move[size] = test_moves[size];
		size--;
	}
	free(test_moves);
	return (next_move);
}

static int	move_cost(t_com *moves)
{
	int	i;

	i = 0;
	while (moves[i] != end)
		i++;
	return (i);
}

static t_com	*cheapest_move(t_stack *a, t_stack *b)
{
	t_com	*test_move;
	t_com	*cheapest_move;
	t_list	*current;

	cheapest_move = prep_b(b, *(a->head->content)); // calcula las rotaciones de b
	cheapest_move = prep_a(a, a->head, cheapest_move);
	current = a->head->next;
	while (current)
	{
		test_move = prep_b(b, *(current->content));
		test_move = prep_a(a, current, test_move);
		if (move_cost(test_move) < move_cost(cheapest_move))
		{
			free(cheapest_move);
			cheapest_move = test_move;
			test_move = NULL;
		}
		else
			free(test_move);
		print_moves(cheapest_move);
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
		// paso dos primeros elemento al stack b
	while (a->size > 3) // hasta que solo quedan tres oelementos en stack a
	{
		next_move = cheapest_move(a, b); // devuelve el array con la secuencia de commands menor
		// next_move = optimize_move(next_move);
		i = 0;
		while (next_move[i] != end)
			make_a(next_move[i++], a, b);
		free(next_move);
		make_a(pb, a, b);
	}
	sort_three(a, b);
//	while (b->size > 0)
//	{
//		make_a(pa, a, b);
//	}
//	while (*(a->head->content) != a->min)
//		make_a(rra, a, b);
	ft_printf("Ordenado\n");
	print_stacks(a->head, b->head);
}
