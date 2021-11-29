/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 00:11:21 by sosugimo          #+#    #+#             */
/*   Updated: 2021/11/29 13:54:29 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_median_new(t_list *lst)
{
	int	vol;
	int	i;
	int	*num;
	int	res;

	i = 0;
	vol = count_list(lst);
	num = (int *)malloc(sizeof(int) * vol);
	malloc_error(num);
	lst_to_array(lst, num);
	quick_sort(num, 0, vol - 1);
	res = num[vol / 2];
	free(num);
	return (res);
}

void	set_meds_array(int med, t_ps *info)
{
	int	*tmp;
	int	i;

	i = 0;
	printf("**************** set_meds_array:  %d ****************\n", med);
	if (info->num_of_meds == 0)
	{
		info->meds_array = (int *)malloc(sizeof(int) * 1);
		info->meds_array[0] = med;
		info->num_of_meds++;
	}
	else
	{
		tmp = info->meds_array;
		info->meds_array = (int *)malloc(sizeof(int) * (info->num_of_meds + 1));
		while (tmp[i])
		{
			info->meds_array[i] = tmp[i];
			i++;
		}
		info->meds_array[i] = med;
		info->num_of_meds++;
		free(tmp);
	}
	quick_sort(info->meds_array, 0, info->num_of_meds - 1);
}

void	pa_med_first(t_list **lst_a, t_list **lst_b, int med, t_ps *info)
{
	int	cnt;

	cnt = count_list(*lst_b);
	catch_top(lst_b);
	printf("med (in [b]):  %d\n", med);
	if (cnt == 4)
		med = get_lstmin(*lst_b);
	while (ft_atoi((*lst_b)->value) != med)
	{
		catch_top(lst_b);
		if (ft_atoi((*lst_b)->value) == med)
			break ;
		rotate_b(lst_b, info);
	}
	catch_top(lst_b);
	push_a(lst_a, lst_b, info);
	if (cnt == 4)
		rotate_a(lst_a, info);
}

void	pa_toleave_three(t_list **lst_a, t_list **lst_b, t_ps *info)
{
	int	cnt;
	int	med;

	while (count_list(*lst_b) >= 4)
	{
		cnt = count_list(*lst_b);
		med = get_median_new(*lst_b);
		pa_med_first(lst_a, lst_b, med, info);
		set_meds_array(med, info);
		catch_top(lst_b);
		if (cnt % 2 == 1)
			cnt--;
		while (count_list(*lst_b) > cnt / 2 && cnt >= 6)
		{
			printf("aaaaaaaaaaaaaaa\n");
			catch_top(lst_b);
			if (ft_atoi((*lst_b)->value) >= med)
				push_a(lst_a, lst_b, info);
			else
				rotate_b(lst_b, info);
		}
		while (count_list(*lst_b) > 3 && 3 <= cnt && cnt < 6)
		{
			printf("bbbbbbbbbbbbbbbbb\n");
			catch_top(lst_b);
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

int	get_proper_med(t_list **lst_a, t_ps *info)
{
	int	i;
	int	bottom;

	i = 0;
	catch_bottom(lst_a);
	bottom = ft_atoi((*lst_a)->value);
	while (info->meds_array[i] <= bottom)
	{
		if (i >= info->num_of_meds)
			return (info->min);
		i++;
	}
	return (info->meds_array[i]);
}

void	pb_till_minmeds(t_list **lst_a, t_list **lst_b, t_ps *info)
{
	int	med;

	med = get_proper_med(lst_a, info);
	printf("●　●　●　●　●　●　●get_proper_med(lst_a, info):   %d\n", med);
	catch_top(lst_a);
	while (ft_atoi((*lst_a)->value) != med)
	{
		catch_top(lst_a);
		push_b(lst_a, lst_b, info);
	}
	if (med != info->min)
	{
		catch_top(lst_a);
		push_b(lst_a, lst_b, info);
	}
}

int	cnt_to_minmed(t_list **lst_a, t_ps *info)
{
	int	cnt;
	int	med;

	cnt = 0;
	med = get_proper_med(lst_a, info);
	catch_top(lst_a);
	while (ft_atoi((*lst_a)->value) != med)
	{
		*lst_a = (*lst_a)->next;
		cnt++;
	}
	return (cnt);
}

void	first_div(t_list **lst_a, t_list **lst_b, t_ps *info)
{
	int	med;
	int	cnt;

	med = get_median_new(*lst_a);
	set_meds_array(med, info);
	cnt = info->net_lst;
	if (cnt % 2 == 1)
		cnt--;
	catch_top(lst_a);
	while (count_list(*lst_a) > cnt / 2)
	{
		catch_top(lst_a);
		if (ft_atoi((*lst_a)->value) <= med)
			push_b(lst_a, lst_b, info);
		else
			rotate_a(lst_a, info);
	}
}

void	new_sort(t_list **lst_a, t_list **lst_b, t_ps *info)
{
	int i = 0;
	first_div(lst_a, lst_b, info);
	pa_toleave_three(lst_a, lst_b, info);
	sortb_n_set(lst_a, lst_b, info);
	printf("------------------------------------------------------------\n");
	while (check_sorted(*lst_a, *lst_b) != 1)
	{
		if (cnt_to_minmed(lst_a, info) == 0)
		{
			printf("         ■ ■　■　■　■　■　■　■　■　■ \n");
			rotate_a(lst_a, info);
		}
		pb_till_minmeds(lst_a, lst_b, info);
		printf("                 ------------------(1) - %d------------------\n", i);
		print_all_lst(lst_a);
		print_all_lst(lst_b);
		pa_toleave_three(lst_a, lst_b, info);
		printf("                 ------------------(2) - %d------------------\n", i);
		print_all_lst(lst_a);
		print_all_lst(lst_b);
		sortb_n_set(lst_a, lst_b, info);
		printf("                 ------------------(3) - %d------------------\n", i);
		print_all_lst(lst_a);
		print_all_lst(lst_b);
		// exit(0);
		if (i == 2)
			break ;
		i++;
	}
	// free(info->sorted_array);
	print_all_lst(lst_a);
	print_all_lst(lst_b);
	exit(0);
}
