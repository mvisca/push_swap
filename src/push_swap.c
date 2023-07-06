/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:03:07 by mvisca            #+#    #+#             */
/*   Updated: 2023/07/06 13:32:53 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	main(int ac, char **av)
{
	t_list	**stack_a;
	t_list	**stack_b;
	char	**tab;

	tab = get_args(ac, av);
	if (!tab && ft_printf ("Nada hecho\n"))
		return (1);
	stack_a = build_stack(tab);
	if (!stack_a && !free_tab(tab))
		return (1);
	stack_b = (t_list **) malloc(sizeof(t_list *) * 1);
	if (!stack_b && !free_tab(tab) && !lstclear_null(stack_a, &free_cont))
		return (1);
	*stack_b = NULL;
	print_stacks(stack_a, stack_b);
	return (0);
}
