/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:03:19 by sosugimo          #+#    #+#             */
/*   Updated: 2021/11/29 21:15:54 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_number(t_list **lst_a, t_list **lst_b)
{
	int		num;
	t_ps	*info;

	info = (t_ps *)malloc(sizeof(t_ps));
	malloc_error(info);
	init_struct_ps(*lst_a, info);
	num = count_list(*lst_a);
	if (num <= 3)
		under3_sort(lst_a, info);
	else if (4 <= num && num <= 6)
		under6_sort(lst_a, lst_b, info);
	else
		over7_sort(lst_a, lst_b, info);
	print_output(info->result);
	free(info);
}
