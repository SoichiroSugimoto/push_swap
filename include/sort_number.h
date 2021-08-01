#ifndef SORT_NUMBER_H
# define SORT_NUMBER_H

# include <string.h>
# include <stdlib.h>
# include "insert_contents.h"
# include "use_operations.h"
# include "utils.h"
# include "../libft/libft.h"

# define DONE 1

int		get_lstmin(t_list *lst);
int		get_lstmax(t_list *lst);
int		get_bottom_num(t_list *lst);
int		confirm_sorted(t_list *lst);
int		confirm_sort_3num(t_list *lst);
int		check_sorted(t_list *lst_a, t_list *lst_b);
void	sort_3num(t_list **lst);
void	sort_2num(t_list **lst);
void	under3_sort(t_list **lst);
void	sort_3num_b(t_list **lst);
void	sort_2num_b(t_list **lst);
void	under3_sort_b(t_list **lst);
void	under6_sort(t_list **lst_a, t_list **lst_b);
void	swap(int *x, int *y);
int		partition(int array[], int left, int right);
void	quick_sort (int array[], int left, int right);
void	lst_to_array(t_list *lst, int array[]);
int		get_median(t_list *lst);
int		get_median_2nd(t_list *lst);
int		not_sorted(t_list *lst);
void	sort_number(t_list **lst_a, t_list **lst_b);
int		get_rest_num(t_list *lst);
void	pa_n_ra(t_list **lst_a, t_list **lst_b);
void	pb_for_leave(t_list **lst_a, t_list **lst_b);
void	over7_sort(t_list **lst_a, t_list **lst_b);
void	over7_sort_2nd(t_list **lst_a, t_list **lst_b);
int		get_rest_num_2nd(t_list *lst);
int		get_rest_num_3rd(t_list *lst);

#endif