/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 11:57:50 by sosugimo          #+#    #+#             */
/*   Updated: 2021/08/01 16:11:06 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# define FAILED -1
# define OK 1
# define TRUE 1
# define FALSE 0
# define INT_MAX_DIGIT 10
# define MATCH 0

long long	ft_atoi(const char *str);
void		ft_putstr_fd(char *s, int fd);
int			ft_strlen(const char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
char		*ft_strchr(const char *s, int c);
int			get_next_line(int fd, char **line);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
bool		ft_malloc(void **str, size_t sz, size_t len);
char		*ft_strdup(const char *s1);
size_t		ft_strlcat(char *dst, char *src, size_t dstsize);

// ft_substr, safe_free, ft_strjoin, ft_malloc
// ft_strlcpy, ft_strdup
#endif
