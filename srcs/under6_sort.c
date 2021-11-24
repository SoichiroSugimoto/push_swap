/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under6_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:04:08 by sosugimo          #+#    #+#             */
/*   Updated: 2021/11/24 16:04:10 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	under6_sort(t_list **lst_a, t_list **lst_b, t_ps *info)
{
	while (count_list(*lst_a) > 3)
	{
		catch_top(lst_a);
		if (ft_atoi((*lst_a)->value) == get_lstmin(*lst_a))
			push_b(lst_a, lst_b, info);
		rotate_a(lst_a, info);
	}
	under3_sort(lst_a, info);
	while (count_list(*lst_b) > 0)
		push_a(lst_a, lst_b, info);
}
