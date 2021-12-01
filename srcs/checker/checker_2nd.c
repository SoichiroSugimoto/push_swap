/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_2nd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:49:48 by sosugimo          #+#    #+#             */
/*   Updated: 2021/12/01 20:04:21 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	read_error(int n)
{
	if (n == -1 || n > 4)
	{
		ft_putstr_fd("Error\n", 1);
		exit(0);
	}
}

void	not_exist(void)
{
	ft_putstr_fd("Error\n", 1);
	exit(0);
}
