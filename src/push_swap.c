/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:03:07 by mvisca            #+#    #+#             */
/*   Updated: 2023/07/25 19:16:23 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static t_ps	*ps_init(void);

int	main(int ac, char **av)
{
	t_ps	*ps;

	ps = ps_init();
	if (!ps)
		return (1);
	if (!ps_parse_args(ac, av, ps))
	{
		ps_free(ps);
		return (1);
	}
	
	print_stacks(ps);
	ps_free(ps);
	return (0);
}

static t_ps	*ps_init(void)
{
	t_ps	*ps;

	ps = (t_ps *) malloc (sizeof(t_ps));
	if (!ps)
		return (NULL);
	ps->a = (t_stack *) malloc (sizeof(t_stack));
	ps->b = (t_stack *) malloc (sizeof(t_stack));
	if (!ps->a || !ps->b)
		return (NULL);
	ps->a->head = NULL;
	ps->b->head = NULL;
	ps->a->size = 0;
	ps->b->size = 0;
	ps->a->min = INT_MAX;
	ps->b->min = INT_MAX;
	ps->a->max = INT_MIN;
	ps->b->max = INT_MIN;
	return (ps);
}

//	#### DEBUG TESTS #####
	// manual_sort(&a, &b);
	// print_tab(tab);
	// print_stack(a, "STACK A");
	// print_stacks(a->head, b->head);
	// test_moves(&a, &b);
	// update_stack(&a);
	// print_stack(a, "STACK A");
	// print_stack(b, "STACK B");
	// print_stack(b, "STACK BBBB");
	// update_stack(&b);
//	#### DEBUG TESTS #####