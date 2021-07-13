#include "../include/sort_number.h"
#include <stdio.h>
#include <stdlib.h>

int	confirm_sort_3num(t_list *lst)
{
	int	first;
	int	second;
	int	third;

	catch_top(&lst);
	first = ft_atoi(lst->value);
	second = ft_atoi((lst->next)->value);
	third = ft_atoi(((lst->next)->next)->value);
	if (first < second && second < third)
		return (1);
	return (0);
}

void	sort_3num(t_list **lst)
{
	catch_top(lst);
	if (ft_atoi((*lst)->value) == get_lstmax(*lst))
		rotate_a(lst);
	catch_2nd_top(lst);
	if (ft_atoi((*lst)->value) == get_lstmax(*lst))
		reverse_rotate_a(lst);
	if (confirm_sort_3num(*lst) != 1)
		swap_a(lst);
}

void	sort_2num(t_list **lst)
{
	catch_top(lst);
	if (ft_atoi((*lst)->value) == get_lstmax(*lst))
		swap_a(lst);
}

void	under3_sort(t_list **lst)
{
	if (count_list(*lst) == 3)
		sort_3num(lst);
	else if (count_list(*lst) == 2)
		sort_2num(lst);
}
