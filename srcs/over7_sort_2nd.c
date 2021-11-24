/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   over7_sort_2nd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:51:34 by sosugimo          #+#    #+#             */
/*   Updated: 2021/11/24 16:02:31 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	pb_ntimes(t_list **lst_a, t_list **lst_b, int n, t_ps *info)
{
	catch_top(lst_a);
	while (0 < n && n <= 3)
	{
		push_b(lst_a, lst_b, info);
		n--;
	}
}

void	rra_ntimes(t_list **lst_a, int n, t_ps *info)
{
	while (n)
	{
		reverse_rotate_a(lst_a, info);
		n--;
	}
}

void	pb_for_leave_2nd(t_list **lst_a, t_list **lst_b, t_ps *info)
{
	int	med;
	int	rest_num;

	while (count_list(*lst_b) > 3)
	{
		med = get_median(*lst_b);
		rest_num = get_rest_num_3rd(*lst_b);
		while (count_list(*lst_b) > rest_num)
		{
			catch_top(lst_b);
			if (ft_atoi((*lst_b)->value) > med)
				push_a(lst_a, lst_b, info);
			else
				rotate_b(lst_b, info);
		}
	}
}

void	over7_sort_2nd_2(t_list **lst_a, t_list **lst_b, int n, t_ps *info)
{
	rra_ntimes(lst_a, n, info);
	pb_for_leave_2nd(lst_a, lst_b, info);
	under3_sort_b(lst_b, info);
	pa_n_ra(lst_a, lst_b, info);
}

void	over7_sort_2nd(t_list **lst_a, t_list **lst_b, t_ps *info)
{
	int	cnt;
	int	med;
	int	rest_num;
	int	bottom;

	cnt = 0;
	rest_num = get_rest_num_2nd(*lst_a);
	med = get_median_2nd(*lst_a);
	bottom = get_bottom_num(*lst_a);
	pb_ntimes(lst_a, lst_b, not_sorted(*lst_a), info);
	while (not_sorted(*lst_a) + cnt > rest_num)
	{
		catch_top(lst_a);
		if (ft_atoi((*lst_a)->value) <= med \
		&& ft_atoi((*lst_a)->value) > bottom)
			push_b(lst_a, lst_b, info);
		else
		{
			rotate_a(lst_a, info);
			cnt++;
		}
	}
	over7_sort_2nd_2(lst_a, lst_b, cnt, info);
}
