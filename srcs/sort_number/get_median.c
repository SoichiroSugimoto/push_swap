#include "sort_number.h"

void	swap(int *x, int *y)
{
	int	tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

int	partition(int array[], int left, int right)
{
	int	i;
	int	j;
	int	piv;

	i = left;
	j = right;
	piv = left;
	while (i < j)
	{
		check_duplication(array[piv], array[j]);
		while (array[i] < array[piv])
			i++;
		while (array[piv] < array[j])
			j--;
		if (i < j)
			swap(&array[i], &array[j]);
	}
	swap(&array[piv], &array[j]);
	return (j);
}

void	quick_sort (int array[], int left, int right)
{
	int	piv;

	if (left < right)
	{
		piv = partition(array, left, right);
		quick_sort(array, left, piv - 1);
		quick_sort(array, piv + 1, right);
	}
}

void	lst_to_array(t_list *lst, int array[])
{
	int	i;

	i = 0;
	catch_top(&lst);
	while (check_nil(lst->value) != 0)
	{
		array[i] = ft_atoi(lst->value);
		i++;
		lst = lst->next;
	}
}

int	get_median(t_list *lst)
{
	int	vol;
	int	i;
	int	num[count_list(lst)];

	i = 0;
	vol = count_list(lst);
	lst_to_array(lst, num);
	quick_sort(num, 0, vol - 1);
	if (vol % 2 == 0)
		return (num[(vol - 1) / 2]);
	else
		return (num[vol / 2]);
}
