/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_debug.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:18:34 by mvisca            #+#    #+#             */
/*   Updated: 2023/08/05 00:12:54 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*
void	print_tab(char **tab)
{
	int		i;

	ft_printf ("\n======== Print TAB ==========\n");
	if (!tab)
	{
		ft_printf ("-------- TAB (null)\n");
		return ;
	}
	i = 0;
	while (tab[i])
	{
		ft_printf("tab[%d] %s\n", i, tab[i]);
		i++;
	}
	ft_printf ("======== End TAB ============\n");
}
*/
/*
void	print_stack(t_stack *stack, char *name)
{
	t_ps_list	*aux;
	int			i;

	ft_printf("\n======== Print '%s' ==========\n", name);
	ft_printf("-------- Nodes\n", name);
	aux = stack->head;
	i = 0;
	while (aux)
	{
		ft_printf("Node [%d]\t-> Content: %d\n", (1 + i++), aux->content);
		aux = aux->next;
	}
	stack->size = ps_lstsize(stack->head);
	ft_printf("\n-------- Stats\n", name);
	ft_printf("* Max %d\n", stack->max);
	ft_printf("* Min %d\n", stack->min);
	ft_printf("* Size %d\n", stack->size);
	ft_printf("======== END '%s'\n", name);
}
*/
/*
static void	*print_line(int cont)
{
	int	len;

	len = 0;
	if (cont == 0)
	{
		ft_printf(" 0 ");
		len = 3;
	}
	else
		len = ft_printf(" %d", cont);
	len = 16 - len;
	while (len > 0 && ft_printf(" "))
		len--;
	ft_printf("| ");
	return (NULL);
}
*/
/*
void	print_stacks(t_ps *ps)
{
	t_ps_list	*a;
	t_ps_list	*b;

	a = ps->a->head;
	b = ps->b->head;
	ft_printf("\n ===== a ====== | ====== b ===== \n");
	while (a || b)
	{
		if (a)
		{
			print_line(a->content);
			a = a->next;
		}
		else
			ft_printf("                | ");
		if (b && !print_line(b->content))
			b = b->next;
		else
			ft_printf("                |");
		ft_printf("\n");
	}
	ft_printf(" ===== a ====== | ====== b ===== \n\n");
}
*/
/*
void	test_moves(t_ps *ps)
{
	print_stacks(ps);
	ps_command(sa, ps);
	ps_command(pb, ps);
	ps_command(pb, ps);
	ps_command(pb, ps);
	ps_command(rr, ps);
	ps_command(rrr, ps);
	ps_command(sa, ps);
	ps_command(pa, ps);
	ps_command(pa, ps);
	ps_command(pa, ps);
	print_stacks(ps);
}
*/
/*
void	print_moves(t_com *moves)
{
	int	i;

	i = 0;
	ft_printf("Print moves:\n");
	while (1)
	{
		if (moves[i] == end && ft_printf("end "))
			break ;
		else if (moves[i] == sa)
			ft_printf("sa ");
		else if (moves[i] == sb)
			ft_printf("sa ");
		else if (moves[i] == ss)
			ft_printf("ss ");
		else if (moves[i] == pa)
			ft_printf("pa ");
		else if (moves[i] == pb)
			ft_printf("pb ");
		else if (moves[i] == ra)
			ft_printf("ra ");
		else if (moves[i] == rb)
			ft_printf("rb ");
		else if (moves[i] == rr)
			ft_printf("rr ");
		else if (moves[i] == rra)
			ft_printf("rra ");
		else if (moves[i] == rrb)
			ft_printf("rrb ");
		else if (moves[i] == rrr)
			ft_printf("rrr ");
		i++;
	}
	ft_printf("\nSTOP Print Moves\n");
}
*/
/*
void	manual_sort(t_ps *ps)
{
	char	buffer[3];
	int		readed;
	int		total;

	total = 0;
	buffer[2] = '\0';
	while (1)
	{
		print_stacks(ps);
		ft_printf("Ingrese una opción: [pa, pb, sa, sb, \
		ss, ra, rb, rra, rrb, rrr, end]:\n");
		readed = read(STDIN_FILENO, buffer, 3);
		if (readed == -1)
			return ;
		ft_printf("Su opcion: %s\n", buffer);
		if (ft_strncmp(buffer, "pa", 2) == 0)
			ps_command(pa, ps);
		else if (ft_strncmp(buffer, "pb", 2) == 0)
			ps_command(pb, ps);
		else if (ft_strncmp(buffer, "sa", 2) == 0)
			ps_command(sa, ps);
		else if (ft_strncmp(buffer, "sb", 2) == 0)
			ps_command(sb, ps);
		else if (ft_strncmp(buffer, "ss", 2) == 0)
			ps_command(ss, ps);
		else if (ft_strncmp(buffer, "ra", 2) == 0)
			ps_command(ra, ps);
		else if (ft_strncmp(buffer, "rb", 2) == 0)
			ps_command(rb, ps);
		else if (ft_strncmp(buffer, "rra", 3) == 0)
			ps_command(rra, ps);
		else if (ft_strncmp(buffer, "rrb", 3) == 0)
			ps_command(rrb, ps);
		else if (ft_strncmp(buffer, "rrr", 3) == 0)
			ps_command(rrr, ps);
		else if (ft_strncmp(buffer, "rr", 2) == 0)
			ps_command(rr, ps);
		else if (ft_strncmp(buffer, "end", 3) == 0)
			break ;
		else
			ft_printf("Opcion no válida\n");
		total += 1;
	}
	ft_printf("total: %d\n", total);
}
*/
