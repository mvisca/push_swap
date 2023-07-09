/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:03:07 by mvisca            #+#    #+#             */
/*   Updated: 2023/07/09 16:11:04 by mvisca           ###   ########.fr       */
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
	if (!tab && ft_printf("Error"))
		return (1);
	if (!tab_valid(tab) && ft_printf("Error"))
	{
		free_tab(&tab);
		return (1);
	}
	a = alloc_stack();
	if (!a)
		return (1);
	b = alloc_stack();
	if (!b && !free_stack(&a))
		return (1);
	tab_to_stack(tab, a);

//	#### DEBUG TESTS #####
	
	//	print_tab(tab);
	// print_stack(a, "STACK A");
	// print_stacks(a->head, b->head);

	test_moves(&a, &b);
	// update_stack(&a);
	print_stack(a, "STACK A");
	print_stack(b, "STACK B");
	// print_stack(b, "STACK BBBB");
	// update_stack(&b);
//	#### DEBUG TESTS #####

//	sort_stack(a, b);
	free_tab(&tab);
	free_stack(&a);
	free_stack(&b);
	return (0);
}