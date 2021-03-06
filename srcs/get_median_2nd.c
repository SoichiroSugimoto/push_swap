/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_median_2nd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:50:08 by sosugimo          #+#    #+#             */
/*   Updated: 2021/12/11 22:26:47 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	not_sorted(t_list *lst)
{
	int	min;
	int	res;

	res = 0;
	min = get_lstmin(lst);
	catch_top(&lst);
	while (ft_atoi(lst->value) > min)
	{
		lst = lst->next;
		res++;
	}
	return (res);
}

void	lst_to_array_2nd(t_list *lst, int array[])
{
	int	i;
	int	min;

	i = 0;
	min = not_sorted(lst);
	catch_top(&lst);
	while (i <= not_sorted(lst))
	{
		array[i] = ft_atoi(lst->value);
		i++;
		lst = lst->next;
	}
}

int	get_median_2nd(t_list *lst)
{
	int	*num;
	int	n;
	int	res;

	n = not_sorted(lst);
	num = (int *)malloc(sizeof(int) * (n + 1));
	malloc_error(num);
	lst_to_array_2nd(lst, num);
	quick_sort(num, 0, n);
	if (n % 2 == 0)
		res = num[n / 2];
	else
		res = num[(n + 1) / 2];
	free(num);
	return (res);
}
