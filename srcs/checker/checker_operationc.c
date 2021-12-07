/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_operationc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:49:57 by sosugimo          #+#    #+#             */
/*   Updated: 2021/12/07 22:09:48 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ss_checker(t_list **lst_a, t_list **lst_b)
{
	if (*lst_a && *lst_b)
	{
		swap_operation(lst_a);
		swap_operation(lst_b);
	}
}

void	rr_checker(t_list **lst_a, t_list **lst_b)
{
	if (*lst_a && *lst_b)
	{
		rotate_operation(lst_a);
		rotate_operation(lst_b);
	}
}

void	rrr_checker(t_list **lst_a, t_list **lst_b)
{
	if (*lst_a && *lst_b)
	{
		reverse_rotate_operation(lst_a);
		reverse_rotate_operation(lst_b);
	}
}
