/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_debug.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 13:01:20 by mvisca            #+#    #+#             */
/*   Updated: 2023/07/08 17:10:37 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void    print_tab(char **tab)
{
	int i;
	
	i = 0;
	while (tab[i])
	{
		ft_printf("tab[%d] %s\n", i, tab[i]);
		i++;
	}
}

void	print_stack(t_stack *stack, char *name)
{
	t_list	*aux;
	int 	i;

	ft_printf("\n=== Print   '%s' ===\n", name); 
	aux = stack->head;
	while (aux)
	{ 
		ft_printf("node %d, content %d\n", i++, *(aux->content));
		aux = aux->next; 
	}
	ft_printf("max %d\nmin %d\nsize %d\n", stack->max, stack->min, stack->size);
	ft_printf("=== Printed '%s' ===\n\n", name); 
}

static void  *print_line(int cont)
{
	int len;

	len = 0;
	if (cont)
		len = ft_printf("%d", cont);
	len = 14 - len;
	while (len > 0 && ft_printf(" "))
		len--;
	ft_printf("| ");
	return (NULL);
}

void	print_stacks(t_list **a, t_list **b)
{
	ft_printf("\n===== a ===== | ===== b ===== \n");
	while (*a || *b)
	{
		if (*a && !print_line((*(*a)->content)))
			*a = (*a)->next;
		else
			ft_printf("              | ");
		if (*b && !print_line((*(*b)->content)))
			*b = (*b)->next;
		else
			ft_printf("              |");
		ft_printf("\n");
	}
	ft_printf("===== a ===== | ===== b ===== \n\n");
}

void	test_moves(t_list **stack_a, t_list **stack_b)
{
	print_stacks(stack_a, stack_b);
	make_a(pa, stack_a, stack_b);
	make_a(sb, stack_a, stack_b);
	make_a(rb, stack_a, stack_b);
	make_a(rrb, stack_a, stack_b);
	make_a(pb, stack_a, stack_b);
	make_a(pb, stack_a, stack_b);
	make_a(pb, stack_a, stack_b);
	make_a(pb, stack_a, stack_b);
	make_a(pb, stack_a, stack_b);
	make_a(pb, stack_a, stack_b);
	make_a(pb, stack_a, stack_b);
	make_a(pb, stack_a, stack_b);
	make_a(pb, stack_a, stack_b);
	make_a(pb, stack_a, stack_b);
	print_stacks(stack_a, stack_b);
	make_a(pa, stack_a, stack_b);
	make_a(pa, stack_a, stack_b);
	make_a(pa, stack_a, stack_b);
	print_stacks(stack_a, stack_b);
	make_a(rr, stack_a, stack_b);
	print_stacks(stack_a, stack_b);
	make_a(ra, stack_a, stack_b);
	make_a(rrb, stack_a, stack_b);
	print_stacks(stack_a, stack_b);
	make_a(pb, stack_a, stack_b);
	make_a(pb, stack_a, stack_b);
	make_a(pb, stack_a, stack_b);
	print_stacks(stack_a, stack_b);
	make_a(sa, stack_a, stack_b);
	make_a(sb, stack_a, stack_b);
	print_stacks(stack_a, stack_b);
}
