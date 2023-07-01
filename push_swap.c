#include <push_swap.h>



int	main(int ac, char **av)
{
	t_list	*a;
	char	**tab;

	tab = get_args(ac, av);
	if (!tab)
		return (1);
	
	// TEST GET ARGS
	//	int i = 0; while (tab[i]) { ft_printf("%s\n", tab[i]); i++; }
	
	a = build_stack(tab);
	if (!a) // sintentizar " ( !a && !free_null(tab) ) "
	{
		free_null(tab);
		return (1);
	}



	return (0);
}