/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:03:07 by mvisca            #+#    #+#             */
/*   Updated: 2023/07/21 15:54:24 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static char	**build_tab(int ac, char **av)
{
	char	**tab;

	tab = NULL;
	tab = args_to_tab(ac, av, tab);
	if (!tab)
	{
		ft_printf("Error");
		return (NULL);
	}
	if (!tab_valid(tab))
	{
		ft_printf("Error");
		free_tab(&tab);
		return (NULL);
	}
	return (tab);
}

static t_stack	*bulid_stack(char **tab)
{
	t_stack	*a;

	a = alloc_stack();
	if (!a)
		return (NULL);
	tab_to_stack(tab, a);
	if (!a)
	{
		free_tab(&tab);
		free_stack(&a);
	}
	return (a);
}

int	main(int ac, char **av)
{
	char	**tab;
	t_stack	*a;
	t_stack	*b;

	tab = build_tab(ac, av);
	if (!tab)
		return (1);
	a = bulid_stack(tab);
	if (!a)
		return (1);
	b = alloc_stack();
	if (!b)
		return (1);
	sort_stack(a, b);
	// manual_sort(&a, &b);
	free_tab(&tab);
	free_stack(&a);
	if (b)
		free_stack(&b);
	return (0);
}

//	#### DEBUG TESTS #####
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
