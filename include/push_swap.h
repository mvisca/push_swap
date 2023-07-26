/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 13:33:47 by mvisca-g          #+#    #+#             */
/*   Updated: 2023/07/26 12:12:42 by mvisca-g         ###   ########.fr       */
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

typedef struct s_ps_list
{
	int					content;
	struct s_ps_list	*next;
}	t_ps_list;

typedef struct s_stack
{
	t_ps_list	*head;
	int			size;
	int			max;
	int			min;
}	t_stack;

typedef struct s_ps
{
	t_stack	*a;
	t_stack	*b;
}	t_ps;

// push_swap_commands.c
void		*ps_command(t_com move, t_ps *ps);

// push_swap_debug.c
void		print_tab(t_ps *ps);
void		print_stack(t_stack *stack, char *name);
void		print_stacks(t_ps *ps);
void		print_moves(t_com *moves);
void		test_moves(t_ps *ps);
void		manual_sort(t_ps *ps);

// push_swap_list_tools.c
void		ps_lstadd_front(t_ps_list **head, t_ps_list *node);
void		ps_lstadd_back(t_ps_list **head, t_ps_list *node);
int			ps_lstsize(t_ps_list *head);
t_ps_list	*ps_lstnew(int content);
t_ps_list	*ps_lstlast(t_ps_list *lst);

// push_swap_mem_utils.c
void		*ps_free(t_ps *ps);
void		ps_update_stack(t_stack *stack);

// push_swap_parse.c
int			ps_parse_args(int ac, char **av, t_ps *ps);

// push_swap_sort_utils_a.c
t_com		*prep_a(t_stack *a, t_ps_list *current, t_com *test_moves);

// push_swap_sort_utils_b.c
t_com		*prep_b(t_stack *b, int num);

// push_swap_sort_long.c
void		sort_long(t_ps *ps);

// push_swap_sort_utils_three.c
void		sort_three(t_ps *ps);

// push_swap_sort_utils_two.c
void		sort_two(t_ps *ps);

/*
// push_swap_validate_args.c
int			is_int(char *str);
int			only_digits(char *str);
int			tab_valid(char **tab);
*/

// push_swap_sort.c
void		ps_sort_stack(t_ps *ps);
int			move_cost(t_com *moves);
//int			ps_sorted(t_ps *ps);

#endif