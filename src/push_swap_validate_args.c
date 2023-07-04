#include <push_swap.h>

static int	only_digits(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (str[i])
		return (FALSE);
	return (TRUE);
}

static int	is_int(char *str)
{
	long int	li;

	li = ft_atol(str);
	if (li < INT_MIN || li > INT_MAX)
		return (FALSE);
	return (TRUE);
}

static int	no_repeat(char **tab)
{
	int	i;
	int	j;
	
	i = 0;
	while (tab[i])
	{
		j = i + 1;
		while (tab[j])
		{
			if (ft_atol(tab[i]) == ft_atol(tab[j]))
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}  

int	tab_valid(char **tab)
{
	int	i;

	if (!tab)
	{
		ft_printf("No tab. (remove this line - validate args\n");
		return (FALSE);
	}
	i = 0;
	while (tab[i])
	{
		if (!only_digits(tab[i]) || !is_int(tab[i]))
		{
			ft_printf("only_digits = %d, is_int = %d (remove this line - validate args\n", only_digits(tab[i]), is_int(tab[i]));
			return (FALSE);
		}
		i++;
	}
//	ft_printf("OK test only && int\n");
	if (!no_repeat(tab))
	{
		ft_printf("no_repeat = %d (remove this line - validate args\n", no_repeat(tab));
		return (FALSE);
	}
//	ft_printf("OK test no repeat\n");
	return (TRUE);
}