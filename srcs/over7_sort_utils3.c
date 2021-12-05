/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   over7_sort_utils3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 20:41:12 by sosugimo          #+#    #+#             */
/*   Updated: 2021/12/05 12:12:29 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	cnt_tofix_intarray(t_ps *info, int num)
{
	int		i;
	int		cnt;

	i = 0;
	cnt = info->numof_pb_marks;
	while (i < cnt)
	{
		if (info->pb_marks[i] == num)
			return (1);
		i++;
	}
	return (0);
}

void	fix_pbmarks_array(t_ps *info, int **marks_array, int num)
{
	int	*tmp;
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (info->numof_pb_marks > 0)
		info->numof_pb_marks -= cnt_tofix_intarray(info, num);
	tmp = *marks_array;
	*marks_array = (int *)malloc(sizeof(int) * info->numof_pb_marks);
	while (j < info->numof_pb_marks)
	{
		if (tmp[i] != num)
		{
			(*marks_array)[j] = tmp[i];
			j++;
		}
		i++;
	}
	free(tmp);
}
