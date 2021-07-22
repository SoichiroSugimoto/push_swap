#include "../include/sort_number.h"
#include <stdio.h>

int	get_lstmax(t_list *lst)
{
	int	res;

	catch_top(&lst);
	res = ft_atoi(lst->value);
	while (check_nil(lst->value) != 0)
	{
		lst = lst->next;
		if (res < ft_atoi(lst->value))
			res = ft_atoi(lst->value);
	}
	return (res);
}

int	get_lstmin(t_list *lst)
{
	int	res;

	catch_top(&lst);
	res = ft_atoi(lst->value);
	while (check_nil(lst->value) != 0)
	{
		if (res > ft_atoi(lst->value))
			res = ft_atoi(lst->value);
		lst = lst->next;
	}
	return (res);
}

int	get_bottom_num(t_list *lst)
{
	int	res;

	catch_bottom(&lst);
	res = ft_atoi(lst->value);
	return (res);
}

int	confirm_sorted(t_list *lst)
{
	catch_top(&lst);
	while (check_nil((lst->next)->value) != 0)
	{
		if (ft_atoi(lst->value) > ft_atoi((lst->next)->value))
			return (0);
		if (ft_atoi(lst->value) == ft_atoi((lst->next)->value))
		{
			printf("ft_atoi(lst->value):          %lld\n", ft_atoi(lst->value));
			printf("ft_atoi((lst->next)->value):  %lld\n", ft_atoi((lst->next)->value));
			ft_putstr_fd("Error: some arguments are duplicated.\n", 1);
			exit (0);
		}
		lst = lst->next;
	}
	return (DONE);
}
