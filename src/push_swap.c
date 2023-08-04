/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:03:07 by mvisca            #+#    #+#             */
/*   Updated: 2023/08/04 13:32:12 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static t_ps	*ps_init(t_ps *ps);

int	main(int ac, char **av)
{
	int		i;
	t_ps	ps;

	ps_init(&ps);
	i = 1;
	while (i < ac)
		ps_parse(av[i++], &ps);
	if (ps.a == NULL)
		ps_end_error(&ps, NULL, TRUE);
	ps_update_stack(ps.a);
	if (!ps_sorted(&ps))
		ps_sort_stack(&ps);
	if (!ps_sorted(&ps))
		ft_printf("\nFAIL\n");
	ps_end_error(&ps, NULL, FALSE);
	return (0);
}

static t_ps	*ps_init(t_ps *ps)
{
	ps->a = (t_stack *) malloc (sizeof(t_stack));
	ps->b = (t_stack *) malloc (sizeof(t_stack));
	if (!ps->a || !ps->b)
		ps_end_error(ps, NULL, FALSE);
	ps->a->head = NULL;
	ps->b->head = NULL;
	ps->a->size = 0;
	ps->b->size = 0;
	ps->a->min = INT_MAX;
	ps->b->min = INT_MAX;
	ps->a->max = INT_MIN;
	ps->b->max = INT_MIN;
	return (ps);
}
