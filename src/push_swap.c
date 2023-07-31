/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:03:07 by mvisca            #+#    #+#             */
/*   Updated: 2023/07/31 22:59:14 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static t_ps	*ps_init(t_ps *ps)
{
	ps->a = (t_stack *) malloc (sizeof(t_stack));
	ps->b = (t_stack *) malloc (sizeof(t_stack));
	if (!ps->a || !ps->b)
	{
		ps_free(ps);
		return (NULL);
	}
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

static int	ps_norep(t_ps *ps)
{
	t_ps_list	*node;
	t_ps_list	*following;

	node = ps->a->head;
	while (node)
	{
		following = node->next;
		while (following)
		{
			if (node->content == following->content)
				exit (ps_end_error(ps, NULL, FALSE));
			following = following->next;
		}
		node = node->next;
	}
	return (TRUE);
}

int	main(int ac, char **av)
{
	int		i;
	t_ps	*ps;

	ps = (t_ps *) malloc (sizeof(t_ps));
	if (!ps)
		return (1);
	ps = ps_init(ps);
	i = 1;
	while (i < ac)
		ps_parse(av[i++], ps);
	
	ps_update_stack(ps->a);
/*
	print_stack(ps->a, "A");
	print_stacks(ps);
	if (ac > 2)
	{
		ps_sort_stack(ps);
		ps_free(ps);
	}
*/
	return (0);
}


