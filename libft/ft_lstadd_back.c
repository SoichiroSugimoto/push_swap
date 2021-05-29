/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 13:51:10 by sosugimo          #+#    #+#             */
/*   Updated: 2021/05/28 13:55:10 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "srcs/push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	while (*lst)
		lst = &((*lst)->next);
	*lst = new;
}