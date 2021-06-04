#ifndef USE_OPERATIONS_H
# define USE_OPERATIONS_H

# include <string.h>
# include <stdlib.h>
#include "../test_for_list.h"

void	catch_nil(t_list **lst);
void	catch_top(t_list **lst);
void	catch_2nd_top(t_list **lst);
void	catch_bottom(t_list **lst);
int		count_list(t_list *lst);
void	swap_operation(t_list **lst);

#endif