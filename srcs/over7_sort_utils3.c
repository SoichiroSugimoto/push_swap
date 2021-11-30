/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   over7_sort_utils3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 11:24:00 by sosugimo          #+#    #+#             */
/*   Updated: 2021/11/30 11:36:11 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	judge_closest_way(t_list *lst_b, int med)
{
	int	vol;
	int	*num;
	int	i;

	i = 0;
	vol = count_list(lst_b);
	num = (int *)malloc(sizeof(int) * vol);
	malloc_error(num);
	lst_to_array(lst_b, num);
	quick_sort(num, 0, vol - 1);
	while (num[i] != med)
		i++;
	free(num);
	if (i > vol / 2)
		return (1);
	return (0);
}
