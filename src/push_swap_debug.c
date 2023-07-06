/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_debug.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 13:01:20 by mvisca            #+#    #+#             */
/*   Updated: 2023/07/06 13:43:22 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void    print_args(char **tab)
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

	ft_printf("\n=== Print '%s' ===\n", str); 
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
		if (ab && !print_line(ab->content))
			ab = ab->next;
		ft_printf("\n");
	}
	ft_printf("===== a ===== | ===== b ===== \n");
}