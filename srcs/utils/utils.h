#ifndef UTILS_H
# define UTILS_H

#include "../insert_contents/insert_contents.h"
#include "../use_operations/use_operations.h"
#include "../sort_number/sort_number.h"
# include <string.h>
# include <stdlib.h>

# define MATCH 0

int		check_nil(char *str);
int		count_list(t_list *lst);
int		ft_atoi(const char *str);
void	ft_putstr_fd(char *s, int fd);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
