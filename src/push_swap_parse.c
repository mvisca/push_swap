/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:26:05 by mvisca-g          #+#    #+#             */
/*   Updated: 2023/07/26 12:26:06 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	ps_no_repeat(t_ps *ps);
static int	ps_args_to_stack(int ac, char **av, t_ps *ps);
static int	ps_validate_digits(char *str);
static int	ps_validate_one_arg(char *str);

int	ps_parse_args(int ac, char **av, t_ps *ps)
{
	if (ac == 1)
		return (FALSE);
	if (ac == 2)
	{
		if (av[1][0] == '\0')
			return (TRUE);
		else if (!ps_validate_one_arg(av[1]))
			ft_printf("Error\n");
		return (TRUE);
	}
	if (ps_args_to_stack(ac, av, ps) == FALSE)
	{
		write(1, "Error\n", 6);
		return (FALSE);
	}
	if (ps_no_repeat(ps) == FALSE)
	{
		write(1, "Error\n", 6);
		return (FALSE);
	}
	ps_update_stack(ps->a);
	return (TRUE);
}

static int	ps_args_to_stack(int ac, char **av, t_ps *ps)
{
	int				i;
	long long int	num;
	char			*str;
	t_ps_list		*new;

	i = 1;
	while (i < ac)
	{
		str = av[i];
		if (!*str)
			return (0);

		if (ps_validate_digits(str) == FALSE)
			return (FALSE);
		num = ft_atol(av[i]);
		if (num < INT_MIN || num > INT_MAX)
			return (FALSE);
		new = ps_lstnew((int) num);
		if (!new)
			return (FALSE);
		ps_lstadd_back(&ps->a->head, new);
		i++;
	}
	return (TRUE);
}

static int	ps_validate_digits(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (FALSE);
		str++;
	}
	return (TRUE);
}

static int	ps_no_repeat(t_ps *ps)
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
				return (FALSE);
			following = following->next;
		}
		current = current->next;
	}
	return (TRUE);
}

static int	ps_validate_one_arg(char *str)
{
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (!ps_validate_digits(str))
		return (FALSE);
	return (TRUE);
}
