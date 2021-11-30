/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   over7_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 00:11:21 by sosugimo          #+#    #+#             */
/*   Updated: 2021/11/30 11:21:24 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	over7_sort(t_list **lst_a, t_list **lst_b, t_ps *info)
{
	first_divi(lst_a, lst_b, info);
	pa_toleave_three(lst_a, lst_b, info);
	sortb_n_set(lst_a, lst_b, info);
	while (check_sorted(*lst_a, *lst_b) != 1)
	{
		if (cnt_to_minmed(lst_a, info) == 0)
			rotate_a(lst_a, info);
		pb_till_minmeds(lst_a, lst_b, info);
		pa_toleave_three(lst_a, lst_b, info);
		sortb_n_set(lst_a, lst_b, info);
	}
	free(info->meds_array);
	free(info->sorted_array);
}
