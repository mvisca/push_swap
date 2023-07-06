/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:03:07 by mvisca            #+#    #+#             */
/*   Updated: 2023/07/06 11:53:41 by mvisca           ###   ########.fr       */
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
	{
		ft_printf ("Nada hecho\n");
		return (1);
	}	
//	TEST GET ARGS -> TAB	// 	int i = 0; while (tab[i]) { ft_printf("Arg[%d] %s\n", i, tab[i]); i++; }
	stack_a = build_stack(tab);
	if (!stack_a && !free_null(tab))
		return (1);
	stack_b = (t_list **) malloc(sizeof(t_list *) * 1);
	if (!stack_b && !free_null(tab) && !lstclear_null(stack_a, &free_void))
		return (1);
//	TEST BUILD STACK
	t_list *lst = *stack_a; while (lst)	{ ft_printf("%d\n", lst->content); lst = lst->next; }
	return (0);
}

// stack_op(char *mode)
// 	if (mode == "sa")
// 		swap("sa")
//	else if (mode == "sb")
// 		swap("sb")
// 	else if (mode == "ss")
//		swap("sa")
// 		swap("sb")
