/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atodekesu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:36:45 by sosugimo          #+#    #+#             */
/*   Updated: 2021/11/24 16:01:52 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_all_lst(t_list **lst)
{
	catch_top(lst);
	printf(" --------------PRINT_ALL-------------- \n");
	while ((*lst)->next && ft_strncmp(((*lst)->next)->value, "nil", 3))
	{
		printf("lst->value:  %s\n", (*lst)->value);
		*lst = (*lst)->next;
	}
	printf("lst->value:  %s\n", (*lst)->value);
}
