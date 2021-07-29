#include "../include/use_operations.h"

void	swap_a(t_list **lst)
{
	if (*lst != NULL)
	{
		swap_operation(lst);
		ft_putstr_fd("sa\n", 1);
	}
}

void	swap_b(t_list **lst)
{
	if (*lst != NULL)
	{
		swap_operation(lst);
		ft_putstr_fd("sb\n", 1);
	}
}

void	ss(t_list **lst_a, t_list **lst_b)
{
	swap_operation(lst_a);
	swap_operation(lst_b);
	ft_putstr_fd("ss\n", 1);
}

void	swap_operation(t_list **lst)
{
	char	*tmp;
	char	*tmp2;

	if (count_list(*lst) > 1)
	{
		catch_top(lst);
		tmp = (*lst)->value;
		catch_2nd_top(lst);
		tmp2 = (*lst)->value;
		(*lst)->value = tmp;
		catch_top(lst);
		(*lst)->value = tmp2;
	}
}
