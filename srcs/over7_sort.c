#include "../include/sort_number.h"

int	check_sorted(t_list *lst_a, t_list *lst_b)
{
	int	top;
	int	bottom;

	catch_top(&lst_a);
	top = ft_atoi(lst_a->value);
	catch_bottom(&lst_a);
	bottom = ft_atoi(lst_a->value);
	if (top != get_lstmin(lst_a) || bottom != get_lstmax(lst_a))
		return (0);
	if (confirm_sorted(lst_a) == 1 && lst_b == NULL)
		return (DONE);
	if (confirm_sorted(lst_a) == 1 && count_list(lst_b) == 0)
		return (DONE);
	return (0);
}

int	get_rest_num(t_list *lst)
{
	int	res;

	if (count_list(lst) % 2 == 0)
		res = count_list(lst) / 2;
	else
		res = (count_list(lst) - 1) / 2;
	return (res);
}

void	pa_n_ra(t_list **lst_a, t_list **lst_b)
{
	int	lst_cnt;

	lst_cnt = count_list(*lst_b);
	while (lst_cnt)
	{
		push_a(lst_a, lst_b);
		rotate_a(lst_a);
		lst_cnt--;
	}
}

void	pb_for_leave(t_list **lst_a, t_list **lst_b)
{
	int	med;
	int	rest_num;

	while (count_list(*lst_b) > 3)
	{
		med = get_median(*lst_b);
		rest_num = get_rest_num(*lst_b);
		if (count_list(*lst_b) % 2 == 0)
			rest_num--;
		while (count_list(*lst_b) > rest_num + 1)
		{
			catch_top(lst_b);
			if (ft_atoi((*lst_b)->value) > med)
				push_a(lst_a, lst_b);
			else
				rotate_b(lst_b);
		}
	}
}

void	over7_sort(t_list **lst_a, t_list **lst_b)
{
	int	med;
	int	rest_num;

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
	pb_for_leave(lst_a, lst_b);
	under3_sort_b(lst_b);
	pa_n_ra(lst_a, lst_b);
	while (check_sorted(*lst_a, *lst_b) != 1)
		over7_sort_2nd(lst_a, lst_b);
}
