#include <push_swap.h>
#include <libft.h>

int main(void)
{
    t_list  **test;
    t_list  *node;

    test = (t_list **) malloc (sizeof(t_list) * 1);
    node = (t_list *) malloc (sizeof(t_list) * 1);
    *test = node;
    node->content = 43;
    node->next = NULL;
    ft_printf ("############################## %d\n", (*test)->content);
    print_stack(test, "nodo desde el main");   
    ft_lstclear(test, &free_cont);
    return (0);
}