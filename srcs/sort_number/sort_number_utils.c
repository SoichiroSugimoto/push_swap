#include "sort_number.h"

int		get_lstmax(t_list *lst)
{
	int res;

	catch_top(&lst);
	res = ft_atoi(lst->value);
	while(check_nil(lst->value) != 0)
	{
		lst = lst->next;
		if (res < ft_atoi(lst->value))
			res = ft_atoi(lst->value);
	}
	return (res);
}

int		get_lstmin(t_list *lst)
{
	int res;

	catch_top(&lst);
	res = ft_atoi(lst->value);
	while(check_nil(lst->value) != 0)
	{
		lst = lst->next;
		if (res > ft_atoi(lst->value))
			res = ft_atoi(lst->value);
	}
	return (res);
}

// int		get_lstmedian(t_list *lst)
// {
// 	int res;

// 	catch_top(&res);
// }