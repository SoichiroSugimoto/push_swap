/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   over7_sort_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:28:55 by sosugimo          #+#    #+#             */
/*   Updated: 2021/11/30 11:40:46 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	prepare_toleave(t_list **lst_a, t_list **lst_b, t_ps *info)
{
	int	med;
	int	cnt;

	cnt = count_list(*lst_b);
	med = get_median_new(*lst_b);
	if (cnt > 5)
	{
		pa_med_first(lst_a, lst_b, med, info);
		set_meds_array(med, &(info->meds_array), info);
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

void	set_meds_array(int med, int **meds_array, t_ps *info)
{
	int	*tmp;
	int	i;

	i = 0;
	if (info->num_of_meds == 0)
	{
		*meds_array = (int *)malloc(sizeof(int) * 1);
		(*meds_array)[0] = med;
		info->num_of_meds++;
	}
	else
	{
		tmp = *meds_array;
		*meds_array = (int *)malloc(sizeof(int) * (info->num_of_meds + 1));
		while (i < info->num_of_meds)
		{
			(*meds_array)[i] = tmp[i];
			i++;
		}
		(*meds_array)[i] = med;
		info->num_of_meds++;
		free(tmp);
		quick_sort(*meds_array, 0, info->num_of_meds - 1);
	}
}

void	pa_med_first(t_list **lst_a, t_list **lst_b, int med, t_ps *info)
{
	int	cnt;
	int	judge;

	cnt = count_list(*lst_b);
	catch_top(lst_b);
	if (cnt == 4)
		med = get_lstmin(*lst_b);
	judge = judge_closest_way(*lst_b, med);
	while (judge == 1 && ft_atoi((*lst_b)->value) != med)
	{
		catch_top(lst_b);
		if (ft_atoi((*lst_b)->value) == med)
			break ;
		rotate_b(lst_b, info);
	}
	while (judge == 0 && ft_atoi((*lst_b)->value) != med)
	{
		catch_top(lst_b);
		if (ft_atoi((*lst_b)->value) == med)
			break ;
		reverse_rotate_b(lst_b, info);
	}
	push_a(lst_a, lst_b, info);
	if (cnt == 4)
		rotate_a(lst_a, info);
}

int	get_proper_med(t_list **lst_a, t_ps *info)
{
	int	i;
	int	bottom;

	i = 0;
	catch_bottom(lst_a);
	bottom = ft_atoi((*lst_a)->value);
	while (info->meds_array[i] <= bottom)
	{
		if (i >= info->num_of_meds - 1)
			return (info->min);
		i++;
	}
	return (info->meds_array[i]);
}
