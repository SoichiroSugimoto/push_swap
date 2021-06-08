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
void	rotate_operation(t_list **lst);
void	reverse_rotate_operation(t_list **lst);
void	ft_lstadd_nilfront(t_list **lst, t_list *new);
void	delete_nil(t_list *lst);
void	push_b_operation(t_list **lst_a, t_list **lst_b);
void	push_a_operation(t_list **lst_a, t_list **lst_b);

#endif