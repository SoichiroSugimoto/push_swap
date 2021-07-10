#ifndef SORT_NUMBER_H
# define SORT_NUMBER_H

# include <string.h>
# include <stdlib.h>
# include "../insert_contents/insert_contents.h"
# include "../use_operations/use_operations.h"
# include "../utils/utils.h"
# include "../deal_with_error/deal_with_error.h"

#define DONE 1

int		get_lstmin(t_list *lst);
int		get_lstmax(t_list *lst);
int		get_bottom_num(t_list *lst);
int		confirm_sorted(t_list *lst);
int		confirm_sort_3num(t_list *lst);
void	sort_3num(t_list **lst);
void	sort_2num(t_list **lst);
void	under3_sort(t_list **lst);
void	under6_sort(t_list **lst_a, t_list **lst_b);
void	swap(int *x, int *y);
int		partition(int array[], int left, int right);
void	quick_sort (int array[], int left, int right);
void	lst_to_array(t_list *lst, int array[]);
int		get_median(t_list *lst);
int		get_median_2nd(t_list *lst);
int		not_sorted(t_list *lst);
void	sort_number(t_list **lst_a, t_list **lst_b);
void	over7_sort(t_list **lst_a, t_list **lst_b);

#endif