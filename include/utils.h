#ifndef UTILS_H
# define UTILS_H

# include "insert_contents.h"
# include "use_operations.h"
# include "sort_number.h"
# include "../libft/libft.h"
# include <string.h>
# include <stdlib.h>
# include <limits.h>

# define MATCH 0

char		*check_num_value(char *str);
void		check_duplication(int num1, int num2);
void		check_intrange(long long num);
int			check_nil(char *str);
int			count_list(t_list *lst);

#endif
