/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under6_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:04:08 by sosugimo          #+#    #+#             */
/*   Updated: 2021/12/08 01:13:23 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	num6_sort(t_list **lst_a, t_list **lst_b, t_ps *info)
{
	int	min;
	int	second;
	int	third;

	min = get_lstmin(*lst_a);
	second = get_lstsecond(*lst_a);
	third = get_lstthird(*lst_a);
	while (count_list(*lst_a) > 3)
	{
		catch_top(lst_a);
		if (ft_atoi((*lst_a)->value) == min
			|| ft_atoi((*lst_a)->value) == second
			|| ft_atoi((*lst_a)->value) == third)
			push_b(lst_a, lst_b, info);
		else
			rotate_a(lst_a, info);
	}
	under3_sort(lst_a, info);
	under3_sort_b(lst_b, info);
	swap_b(lst_b, info);
	reverse_rotate_b(lst_b, info);
}

void	num5_sort(t_list **lst_a, t_list **lst_b, t_ps *info)
{
	int	min;
	int	second;

	min = get_lstmin(*lst_a);
	second = get_lstsecond(*lst_a);
	while (count_list(*lst_a) > 3)
	{
		catch_top(lst_a);
		if (ft_atoi((*lst_a)->value) == min
			|| ft_atoi((*lst_a)->value) == second)
			push_b(lst_a, lst_b, info);
		else
			rotate_a(lst_a, info);
	}
	under3_sort(lst_a, info);
	catch_top(lst_b);
	if (ft_atoi((*lst_b)->value) < ft_atoi(((*lst_b)->next)->value))
		swap_b(lst_b, info);
}

void	num4_sort(t_list **lst_a, t_list **lst_b, t_ps *info)
{
	while (count_list(*lst_a) > 3)
	{
		catch_top(lst_a);
		if (ft_atoi((*lst_a)->value) == get_lstmin(*lst_a))
			push_b(lst_a, lst_b, info);
		else
			rotate_a(lst_a, info);
	}
	under3_sort(lst_a, info);
}

void	under6_sort(t_list **lst_a, t_list **lst_b, t_ps *info)
{
	int	cnt;

	cnt = count_list(*lst_a);
	if (cnt == 4)
		num4_sort(lst_a, lst_b, info);
	if (cnt == 5)
		num5_sort(lst_a, lst_b, info);
	if (cnt == 6)
		num6_sort(lst_a, lst_b, info);
	while (count_list(*lst_b) > 0)
		push_a(lst_a, lst_b, info);
}
