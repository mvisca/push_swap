/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:03:07 by mvisca            #+#    #+#             */
/*   Updated: 2023/07/04 18:12:48 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	main(int ac, char **av)
{
	t_list	**stack_a;
	t_list	**stack_b;
	char	**tab;

	tab = get_args(ac, av);
//	TEST GET ARGS		//	int i = 0; while (tab[i]) { ft_printf("%s\n", tab[i]); i++; }
	stack_a = build_stack(tab);
	stack_b = (t_list **) malloc(sizeof(t_list *) * 1);
	if (!tab || !stack_a || !*stack_a || !stack_b || !*stack_b)
	{
		free_null(tab);
		ft_lstclear(stack_a, &free_void);
		ft_lstclear(stack_b, &free_void);
		return (1);
	}
//	TEST BUILD STACK	//	t_list *lst = *stack_a; while (lst)	{ ft_printf("%d\n", *((int *)lst->content)); lst = lst->next; }
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
