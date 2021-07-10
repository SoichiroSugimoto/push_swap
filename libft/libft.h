/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 11:57:50 by sosugimo          #+#    #+#             */
/*   Updated: 2021/07/11 03:13:33 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

# define MATCH 0

long long	ft_atoi(const char *str);
void		ft_putstr_fd(char *s, int fd);
int			ft_strlen(const char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
