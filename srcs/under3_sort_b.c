/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under3_sort_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:03:45 by sosugimo          #+#    #+#             */
/*   Updated: 2021/11/28 19:55:40 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_3num_b(t_list **lst, t_ps *info)
{
	catch_top(lst);
	if (ft_atoi((*lst)->value) == get_lstmax(*lst))
		rotate_b(lst, info);
	catch_2nd_top(lst);
	if (ft_atoi((*lst)->value) == get_lstmax(*lst))
		reverse_rotate_b(lst, info);
	if (confirm_sort_3num(*lst) != 1)
		swap_b(lst, info);
}

void	sort_2num_b(t_list **lst, t_ps *info)
{
	catch_top(lst);
	if (ft_atoi((*lst)->value) == get_lstmax(*lst))
		swap_b(lst, info);
}

int	under3_sort_b(t_list **lst, t_ps *info)
{
	int	cnt;

	cnt = count_list(*lst);
	if (count_list(*lst) == 3)
		sort_3num_b(lst, info);
	else if (count_list(*lst) == 2)
		sort_2num_b(lst, info);
	return (cnt);
}
