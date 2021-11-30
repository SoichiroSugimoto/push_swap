/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atodekesu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:36:45 by sosugimo          #+#    #+#             */
/*   Updated: 2021/11/30 09:43:44 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_all_lst(t_list **lst)
{
	catch_top(lst);
	printf(" --------------PRINT_LST-------------- \n");
	while ((*lst)->next && ft_strncmp(((*lst)->next)->value, "nil", 3))
	{
		printf("lst->value:  %s\n", (*lst)->value);
		*lst = (*lst)->next;
	}
	printf("lst->value:  %s\n", (*lst)->value);
}

void	print_both(t_list **lst_a, t_list **lst_b)
{
	printf(" --------------PRINT_BOTH-------------- \n");
	printf("[A]\n");
	catch_top(lst_a);
	while ((*lst_a)->next && ft_strncmp(((*lst_a)->next)->value, "nil", 3))
	{
		printf("lst_a->value:  %s\n", (*lst_a)->value);
		*lst_a = (*lst_a)->next;
	}
	printf("lst_a->value:  %s\n\n\n", (*lst_a)->value);
	printf("[B]\n");
	catch_top(lst_b);
	while ((*lst_b)->next && ft_strncmp(((*lst_b)->next)->value, "nil", 3))
	{
		printf("lst_b->value:  %s\n", (*lst_b)->value);
		*lst_b = (*lst_b)->next;
	}
	printf("lst_b->value:  %s\n", (*lst_b)->value);
}
