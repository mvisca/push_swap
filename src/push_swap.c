/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:03:07 by mvisca            #+#    #+#             */
/*   Updated: 2023/07/08 19:03:20 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	main(int ac, char **av)
{
	char	**tab;
	t_stack	*a;
	t_stack	*b;

	tab = NULL;
	a = NULL;
	b = NULL;
	tab = args_to_tab(ac, av, tab);
	if ((!tab || !tab_valid(tab)) && ft_printf("Error") && !free_tab(&tab))
		return (1);
	alloc_stack(&a);
	if (!a)
		return (1);
	alloc_stack(&b);
	if (!b && !free_stack(a))
		return (1);
	tab_to_stack(tab, a);

//	#### DEBUG TESTS #####
//	print_tab(tab);
//	print_stack(a, "STACK A");
//	print_stacks(a->head, b->head);
	test_moves(a, b);
//	#### DEBUG TESTS #####

//	sort_stack(a, b);

	free_tab(&tab);
	free_stack(a);
	free_stack(b);
	return (0);
}