/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:41:16 by sosugimo          #+#    #+#             */
/*   Updated: 2021/11/30 12:57:00 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	confirm_sorted(t_list *lst)
{
	catch_top(&lst);
	while (check_nil((lst->next)->value) != 0)
	{
		if (ft_atoi(lst->value) > ft_atoi((lst->next)->value))
			return (0);
		if (ft_atoi(lst->value) == ft_atoi((lst->next)->value))
		{
			ft_putstr_fd("Error: some arguments are duplicated.\n", 1);
			exit (0);
		}
		lst = lst->next;
	}
	return (DONE);
}

int	check_sorted(t_list *lst_a, t_list *lst_b)
{
	int	top;
	int	bottom;

	catch_top(&lst_a);
	top = ft_atoi(lst_a->value);
	catch_bottom(&lst_a);
	bottom = ft_atoi(lst_a->value);
	if (top != get_lstmin(lst_a) || bottom != get_lstmax(lst_a))
		return (0);
	if (confirm_sorted(lst_a) == 1 && lst_b == NULL)
		return (DONE);
	if (confirm_sorted(lst_a) == 1 && count_list(lst_b) == 0)
		return (DONE);
	return (0);
}
