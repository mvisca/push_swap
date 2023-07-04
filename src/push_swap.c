#include <push_swap.h>

int	main(int ac, char **av)
{
	t_list	**stack_a;
	char	**tab;

	tab = get_args(ac, av);
//	TEST GET ARGS
//	int i = 0; while (tab[i]) { ft_printf("%s\n", tab[i]); i++; }
	stack_a = build_stack(tab);
	if (!tab || !stack_a || !*stack_a)
	{
		free_null(tab);
		return (1);
	}	
//	TEST BUILD STACK
	t_list *lst = *stack_a; 
	while (lst)
	{
		ft_printf("%d\n", *((int *)lst->content));
		lst = lst->next;
	}
	

	return (0);
}

// stack_op(char *mode)
// 	if (mode == "sa")
// 		swap("sa")
//	else if (mode == "sb")
// 		swap("sb")
// 	else if (mode == "ss")
//		swap("sa")
// 		swap("sb")
