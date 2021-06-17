#ifndef SORT_NUMBER_H
# define SORT_NUMBER_H

# include <string.h>
# include <stdlib.h>
#include "../insert_contents/insert_contents.h"
#include "../use_operations/use_operations.h"
# include "../utils/utils.h"

// int		ft_atoi(const char *str);
int		get_lstmin(t_list *lst);
int		get_lstmedian(t_list *lst);
int		get_lstmax(t_list *lst);
int		confirm_sort_3num(t_list *lst);
void	sort_3num(t_list **lst);
void	sort_2num(t_list **lst);
void	under3_sort(t_list **lst);
void	under6_sort(t_list **lst_a, t_list **lst_b);
void	sort_number(t_list **lst_a, t_list **lst_b);

#endif