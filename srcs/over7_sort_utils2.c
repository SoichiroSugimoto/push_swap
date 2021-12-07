/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   over7_sort_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:28:55 by sosugimo          #+#    #+#             */
/*   Updated: 2021/12/07 17:21:58 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	pa_toleave_half(t_list **lst_a, t_list **lst_b, t_ps *info)
{
	int	cnt;
	int	med;
	int	i;

	cnt = count_list(*lst_b);
	med = get_median_new(*lst_b);
	i = 0;
	while (count_list(*lst_b) > cnt / 2 && cnt >= 6)
	{
		catch_top(lst_b);
		if (ft_atoi((*lst_b)->value) >= med && i == 0)
		{
			set_marks_array(ft_atoi((*lst_b)->value),
				&(info->pb_marks), info);
			i++;
		}
		if (ft_atoi((*lst_b)->value) >= med)
			push_a(lst_a, lst_b, info);
		else
			rotate_b(lst_b, info);
	}
}

int	get_median_new(t_list *lst)
{
	int	vol;
	int	*num;
	int	res;

	vol = count_list(lst);
	num = (int *)malloc(sizeof(int) * vol);
	malloc_error(num);
	lst_to_array(lst, num);
	quick_sort(num, 0, vol - 1);
	res = num[vol / 2];
	free(num);
	return (res);
}

int	marks_dup_check(int med, int *array, int cnt)
{
	int	i;

	i = 0;
	while (i < cnt)
	{
		if (array[i] == med)
			return (0);
		i++;
	}
	return (1);
}

void	set_marks_array(int mark, int **pb_marks, t_ps *info)
{
	int	*tmp;
	int	i;

	i = 0;
	if (info->numof_pb_marks == 0)
	{
		*pb_marks = (int *)malloc(sizeof(int) * 1);
		(*pb_marks)[0] = mark;
		info->numof_pb_marks++;
	}
	else if (marks_dup_check(mark, *pb_marks, info->numof_pb_marks) == 1)
	{
		tmp = *pb_marks;
		*pb_marks = (int *)malloc(sizeof(int) * (info->numof_pb_marks + 1));
		while (i < info->numof_pb_marks)
		{
			(*pb_marks)[i] = tmp[i];
			i++;
		}
		(*pb_marks)[i] = mark;
		info->numof_pb_marks++;
		free(tmp);
		quick_sort(*pb_marks, 0, info->numof_pb_marks - 1);
	}
}

int	get_proper_mark(t_list **lst_a, t_ps *info)
{
	int	i;
	int	bottom;

	i = 0;
	catch_bottom(lst_a);
	bottom = ft_atoi((*lst_a)->value);
	if (info->numof_pb_marks == 0)
		return (info->min);
	while (info->pb_marks[i] <= bottom)
	{
		if (i >= info->numof_pb_marks - 1)
			return (info->min);
		i++;
	}
	return (info->pb_marks[i]);
}
