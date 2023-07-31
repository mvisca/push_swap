/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:21:09 by mvisca-g          #+#    #+#             */
/*   Updated: 2023/07/31 22:44:43 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	ps_free_stack2(t_stack **stack)
{
	t_ps_list	*current;
	t_ps_list	*next;

	if (*stack)
	{
		current = (*stack)->head;
		while (current)
		{
			next = current->next;
			free(current);
			current = next;
		}
	}
}

static void	ps_free_tab(char **tab)
{
	int	i;

	if (tab)
	{
		i = 0;
		while (tab[i])
		{
			free(tab[i]);
			tab[i] = NULL;
			i++;
		}
	}
}

static int	ps_end_error(t_ps *ps, char **tab, int msg)
{
	if (msg)
		write (2, "Error\n", 6);
	ps_free_tab(tab);
	free(tab);
	ps_free_stack2(&ps->a);
	free(ps->a);
	ps_free_stack2(&ps->b);
	free(ps->b);
	ps = NULL;
	return (FALSE);
}

static int	ps_isnum(char *str)
{
	if (*str == '\0')
		return (FALSE);
	if (*str == '-' || *str == '+')
		str++;
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
		exit (ps_end_error(ps, NULL, TRUE));
	i = 0;
	tab = ft_split(str, 32);
	while (tab[i] != NULL)
	{
		if (tab[i][0] == 0 || !ps_isnum(tab[i]))
			exit (ps_end_error(ps, tab, TRUE));
		num = ft_atol(tab[i]);
		if (num < INT_MIN || num > INT_MAX)
			exit (ps_end_error(ps, tab, TRUE));
		node = ps_lstnew(num);
		if (!node)
			exit (ps_end_error(ps, tab, FALSE));
		ps_lstadd_back(&ps->a->head, node);
		i++;
	}
	ps_free_tab(tab);
	return (FALSE);
}
