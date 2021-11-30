/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:50:45 by sosugimo          #+#    #+#             */
/*   Updated: 2021/11/29 19:50:45 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*res;

	i = 0;
	res = NULL;
	while (i < (int)ft_strlen(s) + 1)
	{
		if (!s)
			return (NULL);
		if (s[i] == c)
		{
			res = (char *)&s[i];
			break ;
		}
		i++;
	}
	return (res);
}
