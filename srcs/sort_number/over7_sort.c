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
	if (top != get_lstmin(lst_a) || bottom != get_lstmax(lst_a))
		return (0);
	if (confirm_sorted(lst_a) == 1 && count_list(lst_b) == 0)
		return (DONE);
	return (0);
}

int		get_rest_num(t_list *lst)
{
	int res;

	if (count_list(lst) % 2 == 0)
		res = count_list(lst) / 2;
	else
		res = (count_list(lst) + 1) / 2;
	return (res);
}

int		get_rest_num_2nd(t_list *lst)
{
	int res;

	if (not_sorted(lst) % 2 == 0)
		res = not_sorted(lst) / 2;
	else
		res = (not_sorted(lst) + 1) / 2;
	return (res);
}

void	over7_sort_2nd(t_list **lst_a, t_list **lst_b)
{
	int cnt;
	int med;
	int rest_num;
	int bottom;
	int pos;
	int lst_cnt;

	cnt = 0;
	// (1)move 1st half of [a] to [b] according to median
	rest_num = get_rest_num_2nd(*lst_a);
	med = get_median_2nd(*lst_a);
	bottom = get_bottom_num(*lst_a);
	pos = not_sorted(*lst_a);
	catch_top(lst_a);
	while (0 < pos && pos <= 3)
	{
		push_b(lst_a, lst_b);
		pos--;
	}
	// not_sorted(*lst_a)の値はbottomに大きく依存しているので、raによって大幅な変動が行われる。
	while (not_sorted(*lst_a) + cnt > rest_num)
	{
		catch_top(lst_a);
		if (ft_atoi((*lst_a)->value) <= med && ft_atoi((*lst_a)->value) > bottom)
		{
			push_b(lst_a, lst_b);
		}
		else
		{
			rotate_a(lst_a);
			cnt++;
		}
	}

	// (2)operate rra to 'cnt' times to rebuild [a]
	while (cnt)
	{
		reverse_rotate_a(lst_a);
		cnt--;
	}

	// (3)move components of [b] to [a] by the time when rest of [b] becomes 3 or less <<<<SAME AT ALL>>>>
	while (count_list(*lst_b) > 3)
	{
		med = get_median(*lst_b);
		rest_num = get_rest_num(*lst_b);
		while (count_list(*lst_b) > rest_num)
		{
			catch_top(lst_b);
			if (ft_atoi((*lst_b)->value) > med)
				push_a(lst_a, lst_b);
			else
				rotate_b(lst_b);
		}
	}

	// (4)sort number under 3
	under3_sort(lst_b);

	// (5)push_a & rotate_a
	lst_cnt = count_list(*lst_b);
	while (lst_cnt)
	{
		push_a(lst_a, lst_b);
		rotate_a(lst_a);
		lst_cnt--;
	}
}

void	over7_sort(t_list **lst_a, t_list **lst_b)
{
	int med;
	int judge;
	int lst_cnt;
	int rest_num;


	// (1)move 1st half of [a] to [b] according to median
	rest_num = get_rest_num(*lst_a);
	med = get_median(*lst_a);
	catch_top(lst_a);
	while (count_list(*lst_a) > rest_num)
	{
		catch_top(lst_a);
		if (ft_atoi((*lst_a)->value) <= med)
			push_b(lst_a, lst_b);
		else
			rotate_a(lst_a);
	}

	// (2)move components of [b] to [a] by the time when rest of [b] becomes 3 or less
	while (count_list(*lst_b) > 3)
	{
		med = get_median(*lst_b);
		rest_num = get_rest_num(*lst_b);
		while (count_list(*lst_b) > rest_num)
		{
			catch_top(lst_b);
			if (ft_atoi((*lst_b)->value) > med)
				push_a(lst_a, lst_b);
			else
				rotate_b(lst_b);
		}
	}

	// (3)sort number under 3
	under3_sort(lst_b);

	// (4)push_a & rotate_a
	lst_cnt = count_list(*lst_b);
	while (lst_cnt)
	{
		push_a(lst_a, lst_b);
		rotate_a(lst_a);
		lst_cnt--;
	}
	while(check_sorted(*lst_a, *lst_b) != 1)
		over7_sort_2nd(lst_a, lst_b);
}