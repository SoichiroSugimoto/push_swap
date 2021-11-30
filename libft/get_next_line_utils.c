/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:51:08 by sosugimo          #+#    #+#             */
/*   Updated: 2021/11/29 19:51:08 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	all_error_free(char **s1, char **s2)
{
	free(*s1);
	*s1 = NULL;
	free(*s2);
	*s2 = NULL;
	return (ERROR);
}

int	error_free(char **buf)
{
	free(*buf);
	*buf = NULL;
	return (ERROR);
}
