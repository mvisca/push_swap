/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:02:50 by mvisca            #+#    #+#             */
/*   Updated: 2023/07/06 21:08:23 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	*free_ptr(void *ptr)
{
	free(ptr);
	ptr = NULL;
	return (NULL);
}

void    *free_tab(char **tab)
{
	int i;

	if (tab)
	{
		i = 0;
		while (tab[i])
		{
			free(tab[i]);
			tab[i] = NULL;
			i++;
		}
		free(tab);
		tab = NULL;
	}
	return (NULL);
}

void	*free_lst(t_list **lst, void *(*del)(void *))
{
	ft_lstclear(lst, del);
	return (NULL);
}
