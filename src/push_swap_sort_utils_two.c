/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_utils_two.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:28:49 by mvisca            #+#    #+#             */
/*   Updated: 2023/07/24 19:07:45 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void    sort_two(t_ps *ps)
{
    if (*(ps->a->head->content) > *(ps->a->head->next->content))
        ps_command(sa, ps);
}