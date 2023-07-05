/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:02:50 by mvisca            #+#    #+#             */
/*   Updated: 2023/07/04 17:02:51 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	ft_printf("Error (from utils)\n");
	return (NULL);
}