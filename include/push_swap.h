/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 13:33:47 by mvisca-g          #+#    #+#             */
/*   Updated: 2023/07/07 10:31:39 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>
# include <limits.h>

# define TRUE 1
# define FALSE 0

enum    command
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

// push_swap_debug.c
void    print_tab(char **tab);
void	print_stack(t_list **stack, char *str);
void	print_stacks(t_list **a, t_list **b);
void    test_moves(t_list **stack_a, t_list **stack_b);

// push_swap_commands.c
void    make_a(enum command move, t_list **stack_a, t_list **stack_b);

// push_swap_parse.c
char	**get_args(int ac, char **av);
t_list	**build_stack(char **tab);

// push_swap_sort.c
void    sort_stack(t_list **a, t_list **b);

// push_swap_utils.c
void	*free_ptr(void *content);
void	*free_tab(char **tab);
void    *free_lst(t_list **lst, void *(*del)(void *));

// push_swap_validate_args.c
int     tab_valid(char **tab);

#endif