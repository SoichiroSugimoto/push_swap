/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:04:38 by sosugimo          #+#    #+#             */
/*   Updated: 2021/12/03 23:51:21 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_nil(char *str)
{
	if (ft_strlen(str) > 3)
		return (1);
	if (!(ft_strncmp(str, "nil", 3)))
		return (0);
	return (1);
}

int	count_list(t_list *lst)
{
	int	res;

	res = 0;
	while (lst->next && ft_strncmp(lst->value, "nil", 3))
		lst = lst->next;
	lst = lst->next;
	while (lst->next && ft_strncmp(lst->value, "nil", 3))
	{
		lst = lst->next;
		res++;
	}
	return (res);
}

char	*check_num_value(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!((48 <= str[i] && str[i] <= 57)
				|| (str[i] == 45 && i == 0 && ft_strlen(str) > 1)))
		{
			ft_putstr_fd("Error\n", 1);
			exit (0);
		}
		i++;
	}
	return (str);
}

void	check_duplication(int num1, int num2)
{
	if (num1 == num2)
	{
		ft_putstr_fd("Error\n", 1);
		exit (0);
	}
}

void	check_intrange(long long num)
{
	if (num > INT_MAX || num < INT_MIN)
	{
		ft_putstr_fd("Error\n", 1);
		exit (0);
	}
}
