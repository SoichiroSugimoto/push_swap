/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_struct_ps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 00:12:30 by sosugimo          #+#    #+#             */
/*   Updated: 2021/12/05 12:12:58 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	catch_lstmax(t_list **lst, t_ps *info)
{
	catch_top(lst);
	while (ft_atoi((*lst)->value) != info->max)
		*lst = (*lst)->next;
}

int	get_cnt_sorted(t_list **lst_a, t_ps *info)
{
	int	i;

	i = 0;
	catch_lstmax(lst_a, info);
	while (ft_atoi((*lst_a)->value) == info->sorted_array[i])
	{
		*lst_a = (*lst_a)->next;
		i++;
	}
	if (i == 1)
	{
		catch_bottom(lst_a);
		if (ft_atoi((*lst_a)->value) != info->min)
			i = 0;
	}
	info->cnt_sorted = i;
	return (i);
}

void	init_struct_ps(t_list *lst_a, t_ps *info)
{
	int	vol;

	vol = count_list(lst_a);
	info->sorted_array = (int *)malloc(sizeof(int) * vol);
	malloc_error(info->sorted_array);
	lst_to_array(lst_a, info->sorted_array);
	quick_sort(info->sorted_array, 0, vol - 1);
	info->net_lst = vol;
	info->max = info->sorted_array[vol - 1];
	info->min = info->sorted_array[0];
	info->cnt_sorted = 0;
	info->result = NULL;
	info->median = info->sorted_array[vol / 2];
	info->numof_pb_marks = 0;
}
