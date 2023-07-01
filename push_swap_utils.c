/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 17:35:37 by mvisca            #+#    #+#             */
/*   Updated: 2023/07/01 18:38:14 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void    *free_null(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
	return (NULL);
}

char	**get_args(int ac, char **av)
{
	char	**tab;
	int		i;

	if (ac < 2)
		return (NULL);
	else if (ac == 2)
		tab = ft_split(av[1], 32);
	else
	{
		tab = (char **)malloc(sizeof(char *) * (ac));
		if (!tab)
			return (NULL);
		i = 0;
		ft_printf("PARSING\n");
		while (i + 1 < ac)
		{
			tab[i] = ft_strdup(av[i + 1]);
			if (!tab[i])
				return (free_null(tab));
			i++;
		}
		tab[i] = NULL;
	}
	return (tab);
}

t_list	*build_stack(char **tab)
{
	tab[0] = NULL;
	return (NULL);
}