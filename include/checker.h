#ifndef CHECKER_H
# define CHECKER_H

# include "insert_contents.h"
# include "use_operations.h"
# include "sort_number.h"
# include "utils.h"
# include "../libft/libft.h"
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

void	ss_checker(t_list **lst_a, t_list **lst_b);
void	rr_checker(t_list **lst_a, t_list **lst_b);
void	rrr_checker(t_list **lst_a, t_list **lst_b);
void	read_error(int n);
void	not_exist(void);

#endif