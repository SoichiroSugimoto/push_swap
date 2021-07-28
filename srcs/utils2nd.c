#include "../include/utils.h"

void	malloc_error(void *point)
{
	char	*txt;

	txt = "Error: malloc error\n";
	if (point == NULL)
	{
		ft_putstr_fd(txt, 1);
		exit (0);
	}
}

void	free_b_nil(t_list **lst)
{
	if (*lst != NULL)
	{
		catch_nil(lst);
		if (*lst != NULL)
			free(*lst);
	}
}

void	lst_all_free(t_list **lst_a)
{
	t_list	*tmp;

	catch_top(lst_a);
	while (check_nil((*lst_a)->value) != 0)
	{
		tmp = *lst_a;
		*lst_a = (*lst_a)->next;
		free(tmp);
		tmp = NULL;
	}
	free(*lst_a);
}

void	init_lst(t_list **lst_a, t_list **lst_b)
{
	*lst_a = NULL;
	*lst_b = NULL;
}
