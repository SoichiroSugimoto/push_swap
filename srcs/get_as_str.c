/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_as_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:49:40 by sosugimo          #+#    #+#             */
/*   Updated: 2021/11/24 16:01:59 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	array_cnt(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		while (str[i] && str[i] != ' ')
			i++;
		while (str[i] && str[i] == ' ')
			i++;
		res++;
	}
	return (res);
}

void	malloc_error_double(char	**str)
{
	char	*txt;

	txt = "Error: malloc error\n";
	if (str == NULL)
	{
		ft_putstr_fd(txt, 1);
		exit (0);
	}
}

char	**split_str_num(char *str)
{
	int		n;
	int		i;
	int		len;
	char	**array;

	n = 0;
	i = 0;
	n = array_cnt(str);
	array = (char **)malloc(sizeof(char *) * (n + 1));
	malloc_error_double(array);
	while (n >= i + 1 && str)
	{
		len = 0;
		while (*str == ' ')
			str++;
		while (str[len] != ' ')
			len++;
		array[i] = (char *)malloc(sizeof(char) * (len + 1));
		malloc_error(array[i]);
		ft_strlcpy2(array[i], str, len);
		str += len;
		i++;
	}
	array[i] = NULL;
	return (array);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	if (array != NULL)
	{
		while (array[i])
		{
			free(array[i]);
			i++;
		}
		free(array[i]);
		free(array);
	}
}

char	**get_as_str(char *str, t_list **lst_a)
{
	char	**array;
	int		i;

	i = 0;
	array = split_str_num(str);
	while (i < array_cnt(str))
	{
		if (ft_strlen(array[i]) >= 10)
			check_intrange(ft_atoi(array[i]));
		ft_lstadd_nilback(lst_a, ft_lstnew(check_num_value(array[i])));
		i++;
	}
	return (array);
}
