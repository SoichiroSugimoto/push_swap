/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_operations_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:04:23 by sosugimo          #+#    #+#             */
/*   Updated: 2021/11/24 16:04:24 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	catch_nil(t_list **lst)
{
	while (ft_strncmp((*lst)->value, "nil", 3))
		*lst = (*lst)->next;
}

void	catch_top(t_list **lst)
{
	catch_nil(lst);
	*lst = (*lst)->next;
}

void	catch_2nd_top(t_list **lst)
{
	catch_top(lst);
	if (!(count_list(*lst) <= 1))
		*lst = (*lst)->next;
}

void	catch_bottom(t_list **lst)
{
	while ((*lst)->next && ft_strncmp(((*lst)->next)->value, "nil", 3))
		*lst = (*lst)->next;
}
