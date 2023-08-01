/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:21:09 by mvisca-g          #+#    #+#             */
/*   Updated: 2023/08/01 14:37:11 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	ps_isnum(char *str)
{
	if (*str == '\0')
		return (FALSE);
	if (*str == '-' || *str == '+')
		str++;
	if (!*str)
		return (FALSE);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (FALSE);
		str++;
	}
	return (TRUE);
}

int	ps_parse(char *str, t_ps *ps)
{
	int				i;
	long long int	num;
	t_ps_list		*node;
	char			**tab;

	if (*str == 0)
		return (ps_end_error(ps, NULL, TRUE));
	i = 0;
	tab = ft_split(str, 32);
	if (!tab || tab[i] == NULL)
		return (ps_end_error(ps, &tab, TRUE));
	if (tab[i][0] == 0 || !ps_isnum(tab[i]))
		return (ps_end_error(ps, &tab, TRUE));
	num = ft_atol(tab[i]);
	if (num < INT_MIN || num > INT_MAX)
		return (ps_end_error(ps, &tab, TRUE));
	node = ps_lstnew(num);
	if (!node)
		return (ps_end_error(ps, &tab, FALSE));
	ps_lstadd_back(&ps->a->head, node);
	i++;
	ps_free_tab(&tab);
	return (FALSE);
}
