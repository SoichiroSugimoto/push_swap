/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under3_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:03:55 by sosugimo          #+#    #+#             */
/*   Updated: 2021/11/24 16:03:56 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	confirm_sort_3num(t_list *lst)
{
	int	first;
	int	second;
	int	third;

	catch_top(&lst);
	first = ft_atoi(lst->value);
	second = ft_atoi((lst->next)->value);
	third = ft_atoi(((lst->next)->next)->value);
	if (first < second && second < third)
		return (1);
	return (0);
}

void	sort_3num(t_list **lst, t_ps *info)
{
	catch_top(lst);
	if (ft_atoi((*lst)->value) == get_lstmax(*lst))
		rotate_a(lst, info);
	catch_2nd_top(lst);
	if (ft_atoi((*lst)->value) == get_lstmax(*lst))
		reverse_rotate_a(lst, info);
	if (confirm_sort_3num(*lst) != 1)
		swap_a(lst, info);
}

void	sort_2num(t_list **lst, t_ps *info)
{
	catch_top(lst);
	if (ft_atoi((*lst)->value) == get_lstmax(*lst))
		swap_a(lst, info);
}

void	under3_sort(t_list **lst, t_ps *info)
{
	if (count_list(*lst) == 3)
		sort_3num(lst, info);
	else if (count_list(*lst) == 2)
		sort_2num(lst, info);
}
