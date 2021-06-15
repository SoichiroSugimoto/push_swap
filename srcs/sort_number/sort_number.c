#include "sort_number.h"

void	sort_number(t_list **lst_a, t_list **lst_b)
{
	int num;

	num = count_list(*lst_a);
	if (num <= 3)
		under3_sort(lst_a);
}