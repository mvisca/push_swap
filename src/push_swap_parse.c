#include <push_swap.h>

char	**get_args(int ac, char **av)
{
	char	**tab;
	int		i;

	if (ac < 2)
		return (NULL);
	else if (ac == 2)
		return (ft_split(av[1], 32));
	tab = (char **)malloc(sizeof(char *) * (ac));
	if (!tab)
		return (NULL);
	i = 0;
	while (i + 1 < ac)
	{
		tab[i] = ft_strdup(av[i + 1]);
		if (!tab[i++])
			return (free_null(tab));
	}
	tab[i] = NULL;
	return (tab);
}

t_list	**build_stack(char **tab)
{
	t_list	**stack_a;
	t_list	*new;
	int		*int_ptr;
	int		i;

	if (!tab || !tab_valid(tab))
		return (say_error_ret_null());
	stack_a = (t_list **) malloc (sizeof(t_list *) * 1);
	if (!stack_a)
		return (say_error_ret_null());
	i = 0;
	while (tab[i])
	{
		int_ptr = (int *) malloc (sizeof(int) * 1);
		if (!int_ptr)
		{
			ft_lstclear(stack_a, &free_void);
			return (NULL);
		}
		*int_ptr = (int) ft_atol(tab[i]);
		ft_printf("int_ptr = %d\n", *int_ptr);
		new = ft_lstnew(int_ptr);
//		ft_printf("ft_atol(tab[i]) = %d\n", ft_atol(tab[i]));
		ft_lstadd_back(stack_a, new);
// DEBUG
		ft_printf("NODE %d\nNODE->CONTENT (recover) = %d\n", i, *((int *)new->content));
		i++;
	}
	return (stack_a);
}

