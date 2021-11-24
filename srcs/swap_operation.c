/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:03:30 by sosugimo          #+#    #+#             */
/*   Updated: 2021/11/24 16:03:31 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap_a(t_list **lst, t_ps *info)
{
	if (*lst != NULL)
	{
		swap_operation(lst);
		info->result = join_char(info->result, SA);
	}
}

void	swap_b(t_list **lst, t_ps *info)
{
	if (*lst != NULL)
	{
		swap_operation(lst);
		info->result = join_char(info->result, SB);
	}
}

void	ss(t_list **lst_a, t_list **lst_b)
{
	swap_operation(lst_a);
	swap_operation(lst_b);
	ft_putstr_fd("ss\n", 1);
}

void	swap_operation(t_list **lst)
{
	char	*tmp;
	char	*tmp2;

	if (count_list(*lst) > 1)
	{
		catch_top(lst);
		tmp = (*lst)->value;
		catch_2nd_top(lst);
		tmp2 = (*lst)->value;
		(*lst)->value = tmp;
		catch_top(lst);
		(*lst)->value = tmp2;
	}
}
