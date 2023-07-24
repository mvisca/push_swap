/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:02:40 by mvisca            #+#    #+#             */
/*   Updated: 2023/07/24 17:00:40 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static char	**copy_tab(int ac, char **av, char **tab)
{
	int	i;
	
	tab = (char **)malloc(sizeof(char *) * (ac));
	if (!tab)
		return (NULL);
	i = 0;
	while (i + 1 < ac)
	{
		tab[i] = ft_strdup(av[i + 1]);
		if (!tab[i++])
		{
			free_tab(&tab);
			return (NULL);
		}
	}
	tab[i] = 0;
	return (tab);
}

static t_list	*build_node(char *str)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = malloc(sizeof(int));
	if (!new->content)
	{
		free(new);
		return (NULL);
	}
	*(new->content) = (int)ft_atol(str);
	new->next = NULL;
	return (new);
}

t_stack	*tab_to_stack(char **tab, t_stack *stack)
{
	int		i;
	t_list	*new;

	i = 0;
	while (tab[i])
	{
		new = build_node(tab[i]);
		if (!new)
			return (NULL);
		ft_lstadd_back(&(stack->head), new);
		i++;
	}
	update_stack(&stack);
	return (stack);
}

char	**args_to_tab(int ac, char **av, char **tab)
{
	if (ac == 1)
		return (NULL);
	else if (ac == 2)
	{
		tab = ft_split(av[1], 32);
		if (!tab || !tab[1])
		{
			if (only_digits(tab[0]))
				is_int(tab[0]);
			free_tab(&tab);
			return (NULL);
		}
		return (tab);
	}
	tab = copy_tab(ac, av, tab);
	if (!tab)
		return (NULL);
	return (tab);
}