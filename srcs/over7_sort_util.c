/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   over7_sort_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:51:47 by sosugimo          #+#    #+#             */
/*   Updated: 2021/11/24 16:02:37 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_rest_num_2nd(t_list *lst)
{
	int	res;

	if (not_sorted(lst) % 2 == 0)
		res = not_sorted(lst) / 2;
	else
		res = (not_sorted(lst) - 1) / 2;
	return (res);
}

int	get_rest_num_3rd(t_list *lst)
{
	int	res;

	if (count_list(lst) % 2 == 0)
		res = count_list(lst) / 2;
	else
		res = (count_list(lst) + 1) / 2;
	return (res);
}
