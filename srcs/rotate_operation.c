/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:52:50 by sosugimo          #+#    #+#             */
/*   Updated: 2021/11/24 16:03:05 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate_a(t_list **lst, t_ps *info)
{
	if (*lst != NULL)
	{
		rotate_operation(lst);
		info->result = join_char(info->result, RA);
	}
}

void	rotate_b(t_list **lst, t_ps *info)
{
	if (*lst != NULL)
	{
		rotate_operation(lst);
		info->result = join_char(info->result, RB);
	}
}

void	rr(t_list **lst_a, t_list **lst_b)
{
	rotate_operation(lst_a);
	rotate_operation(lst_b);
	ft_putstr_fd("rr\n", 1);
}

void	rotate_operation(t_list **lst)
{
	t_list	*nil;

	catch_nil(lst);
	nil = *lst;
	catch_top(lst);
	nil->value = (*lst)->value;
	(*lst)->value = "nil";
}
