/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:02:40 by mvisca            #+#    #+#             */
/*   Updated: 2023/07/06 12:14:41 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

char	**get_args(int ac, char **av)
{
	char	**tab;
	int		i;

	if (ac < 2)
		return (NULL);
	else if (ac == 2)
		return (ft_split(av[1], 32));
	tab = (char **)malloc(sizeof(char *) * (ac));
	if (!tab)
		return (NULL);
	i = 0;
	while (i + 1 < ac)
	{
		tab[i] = ft_strdup(av[i + 1]);
		if (!tab[i++])
			return (free_tab(tab));
	}
	tab[i] = NULL;
	return (tab);
}

t_list	**build_stack(char **tab)
{
	t_list	**stack_a;
	t_list	*new;
	t_list	*aux;
	int		i;
	int		num;

	if ((!tab || !tab_valid(tab)) && ft_printf("Error"))
		return (NULL);
	stack_a = (t_list **) malloc (sizeof(t_list *) * 1);
	if (!stack_a && ft_printf("Error"))
		return (NULL);
	i = 0;
	while (tab[i])
	{
		num = (int) ft_atol(tab[i]);
		new = ft_lstnew(&num);
		if (!new && lstclear_null(stack_a, &free_cont))
			return (NULL);
		ft_lstadd_back(stack_a, new);
		i++;
	}
//	TEST STACK
	ft_printf("stack built\n"); i = 0; aux = *stack_a; 
while (aux) { ft_printf("node %d, content %d\n", i++, aux->content); aux = aux->next; }; return (stack_a); }

