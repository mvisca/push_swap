/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:02:40 by mvisca            #+#    #+#             */
/*   Updated: 2023/07/06 11:41:05 by mvisca           ###   ########.fr       */
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
			return (free_null(tab));
	}
	tab[i] = NULL;
	return (tab);
}

t_list	**build_stack(char **tab)
{
	t_list	**stack_a;
	t_list	*new;
	t_list	*aux;
	int		*int_ptr;
	int		i;

	if (!tab || !tab_valid(tab))
		return (say_error_ret_null());
	stack_a = (t_list **) malloc (sizeof(t_list *) * 1);
	if (!stack_a)
		return (say_error_ret_null());
	i = 0;
	while (tab[i])
	{
		int_ptr = (int *) malloc (sizeof(int) * 1);
		if (!int_ptr)
		{
			ft_lstclear(stack_a, &free_void);
			return (NULL);
		}
		*int_ptr = (int) ft_atol(tab[i]);
		new = ft_lstnew(int_ptr);
		if (!new)
		{
			ft_lstclear(stack_a, &free_void);
			return (NULL);
		}
		aux = *stack_a;
		ft_lstadd_back(&aux, new);
		i++;
	}
	ft_printf("stack built\n");
	i = 0;
	while (aux)
	{
		ft_printf("node %d, content %d", i++, aux->content);
		aux = aux->next;
	};
	return (stack_a);
}

