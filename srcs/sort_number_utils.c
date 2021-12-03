/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_number_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:53:13 by sosugimo          #+#    #+#             */
/*   Updated: 2021/12/04 02:04:12 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_lstmax(t_list *lst)
{
	int	res;

	catch_top(&lst);
	res = ft_atoi(lst->value);
	while (check_nil(lst->value) != 0)
	{
		if (res < (int)ft_atoi(lst->value))
			res = (int)ft_atoi(lst->value);
		lst = lst->next;
	}
	return (res);
}

int	get_lstmin(t_list *lst)
{
	int	res;

	catch_top(&lst);
	res = ft_atoi(lst->value);
	while (check_nil(lst->value) != 0)
	{
		if (res > ft_atoi(lst->value))
			res = ft_atoi(lst->value);
		lst = lst->next;
	}
	return (res);
}

int	get_bottom_num(t_list *lst)
{
	int	res;

	catch_bottom(&lst);
	res = ft_atoi(lst->value);
	return (res);
}
