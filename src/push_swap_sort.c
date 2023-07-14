/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 10:18:02 by mvisca            #+#    #+#             */
/*   Updated: 2023/07/14 15:40:09 by mvisca           ###   ########.fr       */
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
	int		rotations;
	t_com	rot_type;
	t_com	*next_move;
	t_list	*current;

	current = b->head;
	rotations = 0;
	rot_type = rb;
	ft_printf("recibido por prep b = %d\n", num);
	if (num < b->min || num > b->max)
	{
		while (current && *(current->content) != b->max)
		{
			rotations++;
			if (*(current->content) > b->max)
				b->max = *(current->content);
			if (*(current->content) < b->min)
				b->min = *(current->content);
			current = current->next;
		}
		ft_printf("  in b (num < min || num > max) exit posicionar rotanto\n");
	} 
	else
	{
		while (current && !(num > *(current->next->content)) && !(num < *(current->content)))
		{
			rotations++;
			if (*(current->content) > b->max)
				b->max = *(current->content);
			if (*(current->content) < b->min)
				b->min = *(current->content);
			current = current->next;
		}
			
		ft_printf("  in b (num entr min y max) exit posicionar rotanto\n");
		if (rotations)
			rotations++;
	}
	if (rotations > (b->size / 2))
	{
		rot_type = rrb;
		rotations = b->size - rotations;
	}
	next_move = (t_com *) malloc (sizeof(t_com) * (rotations + 1));
	next_move[rotations] = end;
	ft_printf("sanitize .. rotations %d\n", rotations);
	while (--rotations > 0)
		next_move[rotations--] = rot_type;
	return (next_move);
}

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
		return (NULL);
	next_move[rotations + size] = end;
	ft_printf("PUESTO END EN NEXTMOVEA\n");
	while (rotations > 0)
		next_move[--rotations + size] = rot_type;
	ft_printf("size en prep a %d\n", size);
	while (size > 0)
	{
		next_move[size] = test_moves[size];
		size--;
		ft_printf("in size > 0\n");
	}
	free(test_moves);
	return (next_move);
}

static t_com	*cheapest_move(t_stack *a, t_stack *b)
{
	t_com	*test_move;
	t_com	*cheapest_move;
	t_list	*current;

	cheapest_move = prep_b(b, *(a->head->content));
	cheapest_move = prep_a(a, a->head, cheapest_move);
	current = a->head->next;
	ft_printf("Enter current = %d\n", *(current->content));
	while (current)
	{
		ft_printf("Enter prep current %d\n", *(current->content));
		test_move = prep_b(b, *(current->content));
		ft_printf("  exit b\n");
		test_move = prep_a(a, current, test_move);
		ft_printf("  exit a\n");
		if (sizeof(test_move) < sizeof(cheapest_move))
		{
			free(cheapest_move);
			cheapest_move = test_move;
			test_move = NULL;
		}
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
	ft_printf("Inicial\n");
	print_stacks(a->head, b->head);
	while (a->size > 3 && two--)
		make_a(pb, a, b);
	ft_printf("Push 2\n");
	print_stacks(a->head, b->head);
	while (a->size > 3)
	{
		i = 0;
		next_move = cheapest_move(a, b);
		print_moves(next_move);
		while (next_move[i] != end)
			make_a(next_move[i++], a, b);
		make_a(pb, a, b);
	}
	ft_printf("Make moves to b\n");
	print_stacks(a->head, b->head);
	sort_three(a, b);
	ft_printf("Sort 3\n");
	print_stacks(a->head, b->head);
	while (b->size > 0)
	{
		make_a(pa, a, b);
	}
	ft_printf("Push to a\n");
	print_stacks(a->head, b->head);
	while (*(a->head->content) != a->min)
		make_a(rra, a, b);
	ft_printf("Ordenado\n");
	print_stacks(a->head, b->head);
}
