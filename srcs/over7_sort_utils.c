/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   over7_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:27:30 by sosugimo          #+#    #+#             */
/*   Updated: 2021/12/05 12:20:47 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	pa_toleave_three(t_list **lst_a, t_list **lst_b, t_ps *info)
{
	int	cnt;
	int	med;
	int	i;

	while (count_list(*lst_b) >= 4)
	{
		cnt = count_list(*lst_b);
		med = get_median_new(*lst_b);
		i = 0;
		pa_toleave_half(lst_a, lst_b, info);
		while (count_list(*lst_b) > 3 && 3 <= cnt && cnt < 6)
		{
			catch_top(lst_b);
			if (ft_atoi((*lst_b)->value) >= med && i == 0)
			{
				set_marks_array(ft_atoi((*lst_b)->value),
					&(info->pb_marks), info);
				i++;
			}
			if (ft_atoi((*lst_b)->value) > med)
				push_a(lst_a, lst_b, info);
			else
				rotate_b(lst_b, info);
		}
	}
}

void	sortb_n_set(t_list **lst_a, t_list **lst_b, t_ps *info)
{
	under3_sort_b(lst_b, info);
	while (count_list(*lst_b) > 0)
	{
		push_a(lst_a, lst_b, info);
		rotate_a(lst_a, info);
	}
}

void	pb_till_mark(t_list **lst_a, t_list **lst_b, t_ps *info)
{
	int	mark;

	mark = get_proper_mark(lst_a, info);
	catch_top(lst_a);
	while (ft_atoi((*lst_a)->value) != mark)
	{
		catch_top(lst_a);
		fix_pbmarks_array(info, &(info->pb_marks), ft_atoi((*lst_a)->value));
		push_b(lst_a, lst_b, info);
	}
	if (mark != info->min)
	{
		catch_top(lst_a);
		fix_pbmarks_array(info, &(info->pb_marks), ft_atoi((*lst_a)->value));
		push_b(lst_a, lst_b, info);
	}
}

int	cnt_to_marks(t_list **lst_a, t_ps *info)
{
	int	cnt;
	int	mark;

	cnt = 0;
	mark = get_proper_mark(lst_a, info);
	catch_top(lst_a);
	while (ft_atoi((*lst_a)->value) != mark)
	{
		*lst_a = (*lst_a)->next;
		cnt++;
	}
	return (cnt);
}

void	first_divi(t_list **lst_a, t_list **lst_b, t_ps *info)
{
	int	med;
	int	cnt;

	med = get_median_new(*lst_a);
	cnt = info->net_lst;
	catch_top(lst_a);
	while (count_list(*lst_a) >= cnt / 2 && cnt % 2 == 0)
	{
		catch_top(lst_a);
		if (ft_atoi((*lst_a)->value) <= med)
			push_b(lst_a, lst_b, info);
		else
			rotate_a(lst_a, info);
	}
	while (count_list(*lst_a) > cnt / 2 && cnt % 2 == 1)
	{
		catch_top(lst_a);
		if (ft_atoi((*lst_a)->value) <= med)
			push_b(lst_a, lst_b, info);
		else
			rotate_a(lst_a, info);
	}
}
