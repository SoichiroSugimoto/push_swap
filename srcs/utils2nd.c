/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2nd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:04:55 by sosugimo          #+#    #+#             */
/*   Updated: 2021/12/01 20:08:40 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	malloc_error(void *point)
{
	if (point == NULL)
	{
		ft_putstr_fd("Error\n", 1);
		exit (0);
	}
}

void	free_b_nil(t_list **lst)
{
	if (*lst != NULL)
	{
		catch_nil(lst);
		if (*lst != NULL)
			free(*lst);
	}
}

void	lst_all_free(t_list **lst_a)
{
	t_list	*tmp;

	catch_top(lst_a);
	while (check_nil((*lst_a)->value) != 0)
	{
		tmp = *lst_a;
		*lst_a = (*lst_a)->next;
		free(tmp);
		tmp = NULL;
	}
	free(*lst_a);
}

void	init_lst(t_list **lst_a, t_list **lst_b)
{
	*lst_a = NULL;
	*lst_b = NULL;
}

int	ft_strlcpy2(char *dst, const char *src, int dstsize)
{
	int	i;

	i = 0;
	if (!src || !dst)
		return (0);
	if (!dstsize)
		return (ft_strlen(src));
	while (i + 1 <= dstsize && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
