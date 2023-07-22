/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 13:33:47 by mvisca-g          #+#    #+#             */
/*   Updated: 2023/07/22 14:42:34 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>
# include <limits.h>

# define TRUE 1
# define FALSE 0

typedef enum e_command
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
}	t_com;

struct		s_stack
{
	t_list	*head;
	int		size;
	int		max;
	int		min;
};

typedef struct s_stack	t_stack;

// push_swap_commands.c
void	*make_a(enum e_command move, t_stack *a, t_stack *b);

// push_swap_debug.c
void	print_tab(char **tab);
void	print_stack(t_stack *stack, char *name);
void	print_stacks(t_list *a, t_list *b);
void	print_moves(t_com *moves);
void	test_moves(t_stack **stack_a, t_stack **stack_b);
void	manual_sort(t_stack **a, t_stack **b);

// push_swap_parse.c
char	**args_to_tab(int ac, char **av, char **tab);
t_stack	*tab_to_stack(char **tab, t_stack *stack);

// push_swap_sort.c
void	sort_stack(t_stack *a, t_stack *b);
int		move_cost(t_com *moves);

// push_swap_sort_utils_a.c
t_com	*prep_a(t_stack *a, t_list *current, t_com *test_moves);

// push_swap_sort_utils_b.c
t_com	*prep_b(t_stack *b, int num);

// push_swap_sort_utils_three.c
void	sort_three(t_stack *a, t_stack *b);

// push_swap_sort_b_to_a.c
void    move_b_to_a(t_stack *a, t_stack *b);

// push_swap_utils.c
char	*free_tab(char ***tab);
t_stack	*free_stack(t_stack **stack);
t_stack	*alloc_stack(void);
void	update_stack(t_stack **stack);

// push_swap_validate_args.c
int		tab_valid(char **tab);

#endif