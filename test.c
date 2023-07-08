#include <push_swap.h>

int main(int ac, char **av)
{
    char    **tab;
    int     i;

    tab = ft_split(av[1], 32);
    i = 0;
    while (tab && tab[i])
    {
        ft_printf("%s\n", tab[i]);
        free(tab[i]);
        i++;
    }
    free(tab);
    return (0);
}