#include "sort_number.h"

int	get_rest_num_2nd(t_list *lst)
{
	int	res;

	if (not_sorted(lst) % 2 == 0)
		res = not_sorted(lst) / 2;
	else
		res = (not_sorted(lst) + 1) / 2;
	return (res);
}

void	pb_ntimes(t_list **lst_a, t_list **lst_b, int n)
{
	catch_top(lst_a);
	while (0 < n && n <= 3)
	{
		push_b(lst_a, lst_b);
		n--;
	}
}

void	rra_ntimes(t_list **lst_a, t_list **lst_b, int n)
{
	while (n)
	{
		reverse_rotate_a(lst_a);
		n--;
	}
}

void	over7_sort_2nd_2(t_list **lst_a, t_list **lst_b, int n)
{
	rra_ntimes(lst_a, lst_b, n);
	pb_for_leave(lst_a, lst_b);
	under3_sort(lst_b);
	pa_n_ra(lst_a, lst_b);
}

void	over7_sort_2nd(t_list **lst_a, t_list **lst_b)
{
	int	cnt;
	int	med;
	int	rest_num;
	int	bottom;

	cnt = 0;
	rest_num = get_rest_num_2nd(*lst_a);
	med = get_median_2nd(*lst_a);
	bottom = get_bottom_num(*lst_a);
	pb_ntimes(lst_a, lst_b, not_sorted(*lst_a));
	while (not_sorted(*lst_a) + cnt > rest_num)
	{
		catch_top(lst_a);
		if (ft_atoi((*lst_a)->value) <= med \
		&& ft_atoi((*lst_a)->value) > bottom)
			push_b(lst_a, lst_b);
		else
		{
			rotate_a(lst_a);
			cnt++;
		}
	}
	over7_sort_2nd_2(lst_a, lst_b, cnt);
}
