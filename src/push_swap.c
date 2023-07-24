/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:03:07 by mvisca            #+#    #+#             */
/*   Updated: 2023/07/24 19:16:28 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static char	**parse_args(int ac, char **av, t_ps *ps);
static t_stack	*bulid_stack(t_ps *ps);

int	main(int ac, char **av)
{
	t_ps	*ps;
	
	ps = (t_ps *) malloc (sizeof(t_ps));
	if (ac == 1 || !ps)
		return (0);
	ps->tab = parse_args(ac, av, ps);
	if (!ps->tab && !free_ps(ps))
		return (1);
	bulid_stack(ps);
	if (!ps->a && !free_ps(ps))
		return (1);
	ps->b = alloc_stack();
	if (!ps->b && free_ps(ps))
		return (1);	
	sort_stack(ps);
	free_ps(ps);
	return (0);
}

static char	**parse_args(int ac, char **av, t_ps *ps)
{
	ps->tab = args_to_tab(ac, av, NULL);
	if (!ps->tab)
		return (NULL);
	if (!tab_valid(ps->tab))
	{
		free_ps(ps);
		return (NULL);
	}
	return (ps->tab);
}

static t_stack	*bulid_stack(t_ps *ps)
{
	ps->a = alloc_stack();
	if (!ps->a)
		return (NULL);
	tab_to_stack(ps->tab, ps->a);
	return (ps->a);
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
