/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:50:02 by sosugimo          #+#    #+#             */
/*   Updated: 2021/11/29 19:50:02 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	free_for_checker(t_list **lst_a, t_list **lst_b, char **array)
{
	if (*lst_a != NULL)
		lst_all_free(lst_a);
	if (*lst_b != NULL)
		lst_all_free(lst_b);
	free_array(array);
}

void	safe_free2(char **st)
{
	free(*st);
	*st = NULL;
}
