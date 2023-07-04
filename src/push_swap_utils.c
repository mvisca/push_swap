#include <push_swap.h>

void	free_void(void *content)
{
	free(content);
	content = NULL;
	return ;
}

void    *free_null(char **tab)
{
	int i;

	i = 0;
	while (tab && tab[i])
	{
		free(tab[i]);
		tab[i++] = NULL;
	}
	free(tab);
	tab = NULL;
	return (NULL);
}

void	*say_error_ret_null(void)
{
	ft_printf("Error.");
	return (NULL);
}