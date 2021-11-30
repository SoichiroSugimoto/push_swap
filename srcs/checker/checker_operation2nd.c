/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_operation2nd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:49:52 by sosugimo          #+#    #+#             */
/*   Updated: 2021/11/29 19:49:53 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	checker_swap(t_list **lst)
{
	if (*lst != NULL)
		swap_operation(lst);
}

void	checker_push(t_list **lst_a, t_list **lst_b)
{
	if (*lst_a != NULL)
		push_operation(lst_a, lst_b);
}

void	checker_rotate(t_list **lst)
{
	if (*lst != NULL)
		rotate_operation(lst);
}

void	checker_reverse_rotate(t_list **lst)
{
	if (*lst != NULL)
		reverse_rotate_operation(lst);
}
