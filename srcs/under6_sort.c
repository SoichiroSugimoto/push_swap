#include "../include/sort_number.h"
#include <stdio.h>
#include <stdlib.h>

void	under6_sort(t_list **lst_a, t_list **lst_b)
{
	while (count_list(*lst_a) > 3)
	{
		catch_top(lst_a);
		if (ft_atoi((*lst_a)->value) == get_lstmin(*lst_a))
			push_b(lst_a, lst_b);
		rotate_a(lst_a);
	}
	under3_sort(lst_a);
	while (count_list(*lst_b) > 0)
		push_a(lst_a, lst_b);
}
