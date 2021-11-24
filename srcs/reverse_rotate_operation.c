/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:52:20 by sosugimo          #+#    #+#             */
/*   Updated: 2021/11/24 16:02:52 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	reverse_rotate_a(t_list **lst, t_ps *info)
{
	if (*lst != NULL)
	{
		reverse_rotate_operation(lst);
		info->result = join_char(info->result, RRA);
	}
}

void	reverse_rotate_b(t_list **lst, t_ps *info)
{
	if (*lst != NULL)
	{
		reverse_rotate_operation(lst);
		info->result = join_char(info->result, RRB);
	}
}

void	rrr(t_list **lst_a, t_list **lst_b)
{
	reverse_rotate_operation(lst_a);
	reverse_rotate_operation(lst_b);
	ft_putstr_fd("rrr\n", 1);
}

void	reverse_rotate_operation(t_list **lst)
{
	t_list	*nil;

	catch_nil(lst);
	nil = *lst;
	catch_bottom(lst);
	nil->value = (*lst)->value;
	(*lst)->value = "nil";
}
