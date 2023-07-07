/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_debug.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 13:01:20 by mvisca            #+#    #+#             */
/*   Updated: 2023/07/07 10:56:27 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void    print_tab(char **tab)
{
	int i;
	
	i = 0;
	while (tab[i])
	{
		ft_printf("Arg[%d] %s\n", i, tab[i]);
		i++;
	}
}

void	print_stack(t_list **stack, char *str)
{
	t_list	*aux;
	int 	i;

	ft_printf("\n=== Print   '%s' ===\n", str); 
	i = 0;
	aux = *stack; 
	while (aux) 
	{ 
		ft_printf("node %d, content %d\n", i++, aux->content);
		aux = aux->next; 
	}
	ft_printf("=== Printed '%s' ===\n", str); 
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
	t_list	*aa;
	t_list	*ab;

	aa = NULL;
	ab = NULL;
	if (a && *a)
		aa = *a;
	if (b && *b)
		ab = *b;
	ft_printf("\n===== a ===== | ===== b ===== \n");
	while (aa || ab)
	{
		if (aa && !print_line(aa->content))
			aa = aa->next;
		else
			ft_printf("              | ");
		if (ab && !print_line(ab->content))
			ab = ab->next;
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
