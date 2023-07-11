/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 13:33:47 by mvisca-g          #+#    #+#             */
/*   Updated: 2023/07/11 13:01:07 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>
# include <limits.h>

# define TRUE 1
# define FALSE 0

enum	e_command
{
	end,
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

struct		s_stack
{
	t_list	*head;
	int		size;
	int		max;
	int		min;
};

typedef struct s_stack	t_stack;

// push_swap_commands.c
void	make_a(enum e_command move, t_stack *a, t_stack *b);

// push_swap_debug.c
void	print_tab(char **tab);
void	print_stack(t_stack *stack, char *name);
void	print_stacks(t_list *a, t_list *b);
void	test_moves(t_stack **stack_a, t_stack **stack_b);
void	manual_sort(t_stack **a, t_stack **b);

// push_swap_parse.c
char	**args_to_tab(int ac, char **av, char **tab);
t_stack	*tab_to_stack(char **tab, t_stack *stack);

// push_swap_sort.c
void	sort_stack(t_stack *a, t_stack *b);

// push_swap_utils.c
char	*free_tab(char ***tab);
t_stack	*free_stack(t_stack **stack);
t_stack	*alloc_stack(void);
void	update_stack(t_stack **stack);

// push_swap_validate_args.c
int		tab_valid(char **tab);

#endif