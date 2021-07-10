#include "sort_number.h"
#include <stdio.h>

void	swap(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

int		partition(int array[], int left, int right)
{
	int i;
	int j;
	int piv;

	i = left;
	j = right;
	piv = left;
	while(i < j)
	{
		// check_duplication(array[piv], array[i]);
		check_duplication(array[piv], array[j]);
		while(array[i] < array[piv])
			i++;
		while(array[piv] < array[j])
			j--;
		if (i < j)
			swap(&array[i], &array[j]);
	}
	swap(&array[piv], &array[j]);
	return (j);
}

void	quick_sort (int array[], int left, int right)
{
	int piv;
	if (left < right)
	{
		piv = partition(array, left, right);
		quick_sort(array, left, piv-1);
		quick_sort(array, piv+1, right);
	}
}

void	lst_to_array(t_list *lst, int array[])
{
	int i;

	i = 0;
	catch_top(&lst);
	while (check_nil(lst->value) != 0)
	{
		array[i] = ft_atoi(lst->value);
		i++;
		lst = lst->next;
	}
}

// void	print_array(int num[], int vol)
// {
// 	int i = 0;

// 	printf("print_array\n");
// 	while (i <= vol - 1)
// 	{
// 		printf("[%d] %d\n", i, num[i]);
// 		i++;
// 	}
// 	printf("----------\n");
// }

int		get_median(t_list *lst)
{
	int vol;
	int i;
	int num[count_list(lst)];

	i = 0;
	vol = count_list(lst);
	lst_to_array(lst, num);
	quick_sort(num, 0, vol - 1);
	// print_array(num, vol);
	// printf("vol: %d\n", vol);
	if (vol % 2 == 0)
		return (num[(vol - 1) / 2]);
	else
		return (num[vol / 2]);
}

// int 	main(int argc, char *argv[])
// {
// 	int i = 0;
// 	int num[argc - 1];
// 	printf("---%d\n", argc - 1);
// 	printf("bbbbbbbb\n\n");
// 	printf("last  %d\n", atoi(argv[argc - 1]));
// 	while(i <= argc - 2)
// 	{
// 		num[i] = atoi(argv[i + 1]);
// 		printf("[%d]  %d\n", i, num[i]);
// 		i++;
// 	}
// 	printf("aaaaaaaaaa\n\n");
// 	quick_sort(num, 0, argc - 2);
// 	i = 0;
// 	printf("median = %d\n\n", get_median(num, argc - 1));
// 	while(i <= argc - 2)
// 	{
// 		printf("[%d]  %d\n", i, num[i]);
// 		i++;
// 	}
// }