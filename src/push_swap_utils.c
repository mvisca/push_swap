/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:02:50 by mvisca            #+#    #+#             */
/*   Updated: 2023/07/06 13:02:00 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	free_cont(void *content)
{
	free(content);
	content = NULL;
	return ;
}

void    *free_tab(char **tab)
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

void	*lstclear_null(t_list **lst, void(*del)(void *))
{
	ft_lstclear(lst, del);
	return (NULL);	
}