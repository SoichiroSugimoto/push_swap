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

void	checker_swap(t_list **lst);
void	checker_push(t_list **lst_a, t_list **lst_b);
void	checker_rotate(t_list **lst);
void	checker_reverse_rotate(t_list **lst);
void	ss_checker(t_list **lst_a, t_list **lst_b);
void	rr_checker(t_list **lst_a, t_list **lst_b);
void	rrr_checker(t_list **lst_a, t_list **lst_b);
void	read_error(int n);
void	not_exist(void);
void	free_for_checker(t_list **lst_a, t_list **lst_b, char **array);

#endif
