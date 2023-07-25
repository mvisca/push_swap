/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:02:40 by mvisca            #+#    #+#             */
/*   Updated: 2023/07/25 18:48:20 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	ps_args_to_stack(int ac, char **av, t_ps *ps);
static int	ps_validate_digits(char *str);

int	ps_parse_args(int ac, char **av, t_ps *ps)
{
	if (ac == 1)
		return (FALSE);
	if (!ps_args_to_stack(ac, av, ps))
	{
		ft_printf("Error\n");
		return (FALSE);
	}
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

		if (!ps_validate_digits(str))
			return (0);
		num = ft_atol(av[i]);
		if (num < INT_MIN || num > INT_MAX)
			return (0);
		new = ps_lstnew((int) num);
		if (!new)
			return (0);
		ps_lstadd_back(&ps->a->head, new);
		i++;
	}
	return (1);
}

static int	ps_validate_digits(char *str)
{
	int	i;

	i = 0;
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}
