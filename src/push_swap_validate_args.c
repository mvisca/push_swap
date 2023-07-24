/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_validate_args.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:03:00 by mvisca            #+#    #+#             */
/*   Updated: 2023/07/24 15:50:35 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	only_digits(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (str[i])
	{
		ft_printf("Error\n");
		return (FALSE);
	}
	return (TRUE);
}

int	is_int(char *str)
{
	long int	li;

	li = ft_atol(str);
	if (li < INT_MIN || li > INT_MAX)
	{
		ft_printf("Error\n");
		return (FALSE);
	}
	return (TRUE);
}

static int	no_repeat(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = i + 1;
		while (tab[j])
		{
			if (ft_atol(tab[i]) == ft_atol(tab[j]))
			{
				ft_printf("Error\n");
				return (FALSE);
			}
			j++;
		}
		i++;
	}
	return (TRUE);
}

int	tab_valid(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (!only_digits(tab[i]))
			return (FALSE);
		if (!is_int(tab[i]))
			return (FALSE);
		i++;
	}
	if (!no_repeat(tab))
	{
		ft_printf("Error\n");
		return (FALSE);
	}
	return (TRUE);
}
