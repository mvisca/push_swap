/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:03:07 by mvisca            #+#    #+#             */
/*   Updated: 2023/07/08 16:48:54 by mvisca           ###   ########.fr       */
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
	ft_printf("PUT TAB\n");
	print_tab(tab);
	alloc_stack(&a);
	if (!a)
		return (1);
	alloc_stack(&b);
	if (!b && !free_stack(a))
		return (1);
	tab_to_stack(tab, a);
//	sort_stack(a, b);
	test_moves(&(a->head), &(b->head));
	free_tab(&tab);
	free_stack(a);
	free_stack(b);
	return (0);
}