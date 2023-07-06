/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 13:33:47 by mvisca-g          #+#    #+#             */
/*   Updated: 2023/07/06 13:36:54 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>
# include <limits.h>

# define TRUE 1
# define FALSE 0

enum    operand
{ 
    sa,
    sb,
    ss,
    pa,
    pb,
    ra,
    rb,
    rr,
    rra,
    rrb,
    rrr
};

char	**get_args(int ac, char **av);

int     tab_valid(char **tab);

t_list	**build_stack(char **tab);

void    make_a(enum operand move, t_list **stack_a, t_list **stack_b);

// push_swap_utils.c
void	free_cont(void *content);
void	*free_tab(char **tab);
void    *lstclear_null(t_list **lst, void(*del)(void *));

// push_swap_debug.c
void    print_args(char **tab);
void	print_stack(t_list **stack, char *str);
void	print_stacks(t_list **a, t_list **b);

#endif