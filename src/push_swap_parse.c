/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:21:09 by mvisca-g          #+#    #+#             */
/*   Updated: 2023/08/10 12:39:37 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	ps_norep(t_ps *ps);
static int	ps_isnum(char *str);

int	ps_parse(char *str, t_ps *ps)
{
	long long int	num;
	t_ps_list		*node;
	char			**tab;
	int				i;

	i = 0;
	tab = ft_split(str, 32);
	if (*str == 0 || !tab || *tab == NULL)
		return (ps_end_error(ps, &tab, TRUE));
	if (*tab[0] == 0 || !ps_isnum(*tab))
		return (ps_end_error(ps, &tab, TRUE));
	while (tab[i])
	{
		num = ft_atol(tab[i++]);
		if (num < INT_MIN || num > INT_MAX)
			return (ps_end_error(ps, &tab, TRUE));
		node = ps_lstnew(num);
		if (!node)
			return (ps_end_error(ps, &tab, FALSE));
		ps_lstadd_back(&ps->a->head, node);
	}
	ps_norep(ps);
	ps_free_tab(&tab);
	return (FALSE);
}

static int	ps_norep(t_ps *ps)
{
	t_ps_list	*current;
	t_ps_list	*following;

	current = ps->a->head;
	while (current)
	{
		following = current->next;
		while (following)
		{
			if (current->content == following->content)
				exit (ps_end_error(ps, NULL, TRUE));
			following = following->next;
		}
		current = current->next;
	}
	return (TRUE);
}

static int	ps_isnum(char *str)
{
	if (*str == '\0')
		return (FALSE);
	if ((*str == '+' || *str == '-'))
		str++;
	if (!*str)
		return (FALSE);
	while (*str)
	{
		if ((*str < '0' || *str > '9'))
			return (FALSE);
		str++;
	}
	return (TRUE);
}
