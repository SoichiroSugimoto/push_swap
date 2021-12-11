/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange_output.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:15:28 by sosugimo          #+#    #+#             */
/*   Updated: 2021/12/11 22:25:44 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	*join_char(char *dst, char src)
{
	int		i;
	char	*new;

	if (!dst || !ft_strlen(dst))
	{
		new = (char *)malloc(sizeof(char) * 2);
		malloc_error(new);
		new[0] = src;
		new[1] = '\0';
		return (new);
	}
	new = (char *)malloc(sizeof(char) * (ft_strlen(dst) + 2));
	malloc_error(new);
	i = 0;
	while (dst[i])
	{
		new[i] = dst[i];
		i++;
	}
	if (dst && ft_strlen(dst))
		free(dst);
	new[i++] = src;
	new[i] = '\0';
	return (new);
}

int	arrange_marge_output(char *str, int i)
{
	if ((str[i] == SA && str[i + 1] == SB)
		|| (str[i] == SB && str[i + 1] == SA))
	{
		ft_putstr_fd("ss\n", 1);
		return (2);
	}
	else if ((str[i] == RA && str[i + 1] == RB)
		|| (str[i] == RB && str[i + 1] == RA))
	{
		ft_putstr_fd("rr\n", 1);
		return (2);
	}
	else if ((str[i] == RRA && str[i + 1] == RRB)
		|| (str[i] == RRB && str[i + 1] == RRA))
	{
		ft_putstr_fd("rrr\n", 1);
		return (2);
	}
	return (0);
}

void	arrange_output(char *str, int i)
{
	if (str[i] == SA)
		ft_putstr_fd("sa\n", 1);
	else if (str[i] == SB)
		ft_putstr_fd("sb\n", 1);
	else if (str[i] == PA)
		ft_putstr_fd("pa\n", 1);
	else if (str[i] == PB)
		ft_putstr_fd("pb\n", 1);
	else if (str[i] == RA)
		ft_putstr_fd("ra\n", 1);
	else if (str[i] == RB)
		ft_putstr_fd("rb\n", 1);
	else if (str[i] == RRA)
		ft_putstr_fd("rra\n", 1);
	else if (str[i] == RRB)
		ft_putstr_fd("rrb\n", 1);
}

void	print_output(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i += arrange_marge_output(str, i);
		arrange_output(str, i);
		i++;
	}
	free(str);
}
