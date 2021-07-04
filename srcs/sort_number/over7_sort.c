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

void	over7_sort_2nd(t_list **lst_a, t_list **lst_b)
{
	int med;
	int bottom;

	med = get_median_2nd(*lst_a);
	// printf("       %d\n", med);
	catch_bottom(lst_a);
	bottom = ft_atoi((*lst_a)->value);
	catch_top(lst_a);
	while(check_nil((*lst_a)->value))
	{
		if (ft_atoi((*lst_a)->value) <= med && ft_atoi((*lst_a)->value) <= bottom)
			push_b(lst_a, lst_b);
		*lst_a = (*lst_a)->next;
	}
	while (count_list(*lst_b) >= 4)
	{
		////////////////ここ！！！！！！！！！！
		med = get_median(*lst_b);
		while (check_nil((*lst_b)->value))
		{
			if (ft_atoi((*lst_b)->value) <= med)
				push_a(lst_a, lst_b);
			*lst_b = (*lst_b)->next;
		}
	}
	sort_3num(lst_b);
	push_a(lst_a, lst_b);
	rotate_a(lst_a);
}

void	over7_sort(t_list **lst_a, t_list **lst_b)
{
	int med;
	int	ini_top;
	int i = 0;

	med = get_median(*lst_a);
	printf("     ----------med %d\n", med);
	catch_top(lst_a);
	ini_top = ft_atoi((*lst_a)->value);
	while(i <= 1)
	{
		catch_top(lst_a);
		// printf("[(i: %d)  med  %d / ft_atoi((*lst_a)->value) : %s]\n",i ,med , (*lst_a)->value);
		if (ft_atoi((*lst_a)->value) == ini_top && ini_top <= med)
			ini_top = ft_atoi(((*lst_a)->next)->value);
		if (ft_atoi((*lst_a)->value) <= med)
			push_b(lst_a, lst_b);
		else
			rotate_a(lst_a);
		if (ft_atoi(((*lst_a)->next)->value) == ini_top)
			i++;
	}
	i = 0;
	catch_top(lst_b);
	printf("---------print_2stacks\n");
	print_2stacks(*lst_a, *lst_b);
	printf("-----------------------\n");
	// exit(1);
	int n = 0;
	catch_top(lst_b);
	ini_top = ft_atoi((*lst_a)->value);
	while (count_list(*lst_b) > 3)
	{
		med = get_median(*lst_b);
		printf("    med = %d\n", med);
		while (i <= 1)
		{
			// printf("here!!!!!!!!!!!\n");
			catch_top(lst_b);
			if (ft_atoi((*lst_a)->value) == ini_top && ini_top > med)
				ini_top = ft_atoi(((*lst_a)->next)->value);
			printf("ini_top = %d\n", ini_top);
			if (ft_atoi((*lst_b)->value) > med)
			{
				// printf("   pa------- [%d] %d\n", i, ft_atoi((*lst_b)->value));
				push_a(lst_a, lst_b);
				i++;
			}
			else
				rotate_b(lst_b);
			if (ft_atoi(((*lst_a)->next)->value) == ini_top)
				i++;
		}
		printf("bbbbbbbbbbbbbbbb-----------\n");
		print_circulatio_2nd(*lst_b);
		n++;
		if (n == 3)
			exit(1);
	}
	printf("\n--------[a]----------\n");
	print_circulatio_2nd(*lst_a);
	printf("----------\n");
	sort_3num(lst_b);
	push_a(lst_a, lst_b);
	rotate_a(lst_a);
	// while (get_median_2nd(*lst_a) != 0 && check_sorted(*lst_a, *lst_b) != 0)
	// 	over7_sort_2nd(lst_a, lst_b);
	// printf("Hi!!!!!!!!\n");
}