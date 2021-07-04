#include "sort_number.h"
#include <stdio.h>

int		check_sorted(t_list *lst_a, t_list *lst_b)
{
	int res;
	int top;
	int bottom;

	catch_top(&lst_a);
	top = ft_atoi(lst_a->value);
	catch_bottom(&lst_a);
	bottom = ft_atoi(lst_a->value);
	if (!(top == get_lstmin(lst_a) && bottom == get_lstmax(lst_b)))
		return (1);
	if (confirm_sorted(lst_a) == 0 && count_list(lst_b) == 0)
		return (DONE);
	return (1);
}

int		get_end_num_point(t_list *lst_a)
{
	int res;

	if (count_list(lst_a) % 2 == 0)
		res = count_list(lst_a) / 2;
	else
		res = (count_list(lst_a) - 1) / 2;
	return (res);
}

void	over7_sort(t_list **lst_a, t_list **lst_b)
{
	int med;
	int judge;
	int end_num_point;

	end_num_point = get_end_num_point(*lst_a);
	med = get_median(*lst_a);
	catch_top(lst_a);
	while (count_list(*lst_a) > end_num_point)
	{
		catch_top(lst_a);
		if (ft_atoi((*lst_a)->value) < med)
			push_b(lst_a, lst_b);
		else
			rotate_a(lst_a);
	}
	print_2stacks(*lst_a, *lst_b);////////////////////////////////
}