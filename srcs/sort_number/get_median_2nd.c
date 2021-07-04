#include "sort_number.h"
#include <stdio.h>

int		min_posit(t_list *lst)
{
	int min;
	int res;

	res = 0;
	catch_top(&lst);
	while (ft_atoi(lst->value) != min)
	{
		lst = lst->next;
		res++;
	}
	return (res);
}

void	lst_to_array_2nd(t_list *lst, int array[])
{
	int i;
	int min;

	i = 0;
	min = min_posit(lst);
	catch_top(&lst);
	while (i <= min_posit(lst))
	{
		array[i] = ft_atoi(lst->value);
		i++;
		lst = lst->next;
	}
}

int		get_median_2nd(t_list *lst)
{
	int min;
	int res;
	// int num[min_posit(lst) + 1];
	int n;

	n = min_posit(lst);
	int num[n];
	lst_to_array(lst, num);
	quick_sort(num, 0, n);
	/////////////////////////////
	if (n == 0)
	{
		printf("n == 0\n");
		return (0);
	}
	if (n % 2 == 0)
		return (num[n / 2]);
	else
		return (num[(n + 1) / 2]);
}
