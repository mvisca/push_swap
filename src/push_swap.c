/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:03:07 by mvisca            #+#    #+#             */
/*   Updated: 2023/07/07 10:59:03 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	main(int ac, char **av)
{
	t_list	**stack_a;
	t_list	**stack_b;
	char	**tab;

	tab = get_args(ac, av);
	if (!tab)
		return (1);
	stack_a = build_stack(tab);	
	if (!stack_a)
		return (1);
	print_stack(stack_a, "stack A");
	stack_b = (t_list **) malloc(sizeof(t_list *) * 1);
	if (!stack_b && free_lst(stack_a))
		return (1);
	*stack_b = NULL;
	sort_stack(stack_a, stack_b);
	test_moves(stack_a, stack_b);
	stack_a = free_lst(stack_a);
	stack_b = free_lst(stack_b);
	return (0);
}
