/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 13:33:47 by mvisca-g          #+#    #+#             */
/*   Updated: 2023/07/04 17:27:16 by mvisca           ###   ########.fr       */
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
    rs,
    rra,
    rrb,
    rrs
};

char	**get_args(int ac, char **av);

int     tab_valid(char **tab);

t_list	**build_stack(char **tab);

void	*free_null(char **tab);
void	free_void(void *content);
void    make_a(enum operand move, t_list **stack_a, t_list **stack_b);
void    *say_error_ret_null(void);

#endif