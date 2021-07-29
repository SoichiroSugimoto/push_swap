#include "../include/sort_number.h"
#include <stdlib.h>

void	sort_3num_b(t_list **lst)
{
	catch_top(lst);
	if (ft_atoi((*lst)->value) == get_lstmax(*lst))
		rotate_b(lst);
	catch_2nd_top(lst);
	if (ft_atoi((*lst)->value) == get_lstmax(*lst))
		reverse_rotate_b(lst);
	if (confirm_sort_3num(*lst) != 1)
		swap_b(lst);
}

void	sort_2num_b(t_list **lst)
{
	catch_top(lst);
	if (ft_atoi((*lst)->value) == get_lstmax(*lst))
		swap_b(lst);
}

void	under3_sort_b(t_list **lst)
{
	if (count_list(*lst) == 3)
		sort_3num_b(lst);
	else if (count_list(*lst) == 2)
		sort_2num_b(lst);
}
