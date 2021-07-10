#include "utils.h"

int	check_nil(char *str)
{
	if (!(strcmp(str, "nil")))
		return (MATCH);
	return (1);
}

int	count_list(t_list *lst)
{
	int	res;

	res = 0;
	while (lst->next && ft_strncmp(lst->value, "nil", 3))
		lst = lst->next;
	lst = lst->next;
	while (lst->next && ft_strncmp(lst->value, "nil", 3))
	{
		lst = lst->next;
		res++;
	}
	return (res);
}
