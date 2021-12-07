/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_number_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 00:16:01 by sosugimo          #+#    #+#             */
/*   Updated: 2021/12/08 00:45:36 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_lstthird(t_list *lst)
{
	int	res;
	int	min;
	int	second;

	min = get_lstmin(lst);
	second = get_lstsecond(lst);
	catch_top(&lst);
	res = ft_atoi(lst->value);
	while (res == min || res == second)
	{
		lst = lst->next;
		res = (int)ft_atoi(lst->value);
	}
	while (check_nil(lst->value) != 0)
	{
		if (res > (int)ft_atoi(lst->value)
			&& min != (int)ft_atoi(lst->value)
			&& second != (int)ft_atoi(lst->value))
			res = (int)ft_atoi(lst->value);
		lst = lst->next;
	}
	return (res);
}

void	rver_sort_3num_b(t_list **lst, t_ps *info)
{
	catch_top(lst);
	if (ft_atoi((*lst)->value) == get_lstmin(*lst))
		rotate_b(lst, info);
	catch_2nd_top(lst);
	if (ft_atoi((*lst)->value) == get_lstmin(*lst))
		reverse_rotate_b(lst, info);
	if (confirm_sort_3num(*lst) != 1)
		swap_b(lst, info);
}
