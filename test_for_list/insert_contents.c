#include "test_for_list.h"
#include <stdio.h>
#include <string.h>

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next && ft_strncmp(lst->value, "nil", 3))
		lst = lst->next;
	return (lst);
}

t_list	*ft_pre_lstlast(t_list *lst)
{
	t_list *tmp;
	int i;
	int j;

	i = 0;
	j = 0;
	tmp = lst;
	if (!lst)
		return (NULL);
	while (tmp->next && ft_strncmp(tmp->value, "nil", 3))
	{
		tmp = tmp->next;
		i++;
	}
	// printf("tmp: (%d) -----%s---- \n", i, tmp->value);
	while (i - 3 >= j)
	{
		lst = lst->next;
		j++;
	}
	// printf("prev: (%d) -----%s---- \n\n", i, lst->value);
	return (lst);
}

t_list	*make_sentinel()
{
	t_list *lst_new;

	if (!(lst_new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	lst_new->value = "nil";
	lst_new->next = lst_new;
	lst_new->prev = lst_new;
	return (lst_new);
}

t_list	*put_setinel(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!lst)
	{
		lst = &new;
		return NULL;
	}
	if (!*lst)
	{
		*lst = new;
		return NULL;
	}
	tmp = ft_lstlast(*lst);
	tmp->next = tmp;
	tmp->prev = tmp;
	return (tmp);
}

void	ft_lstadd_back_2(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!lst)
	{
		lst = &new;
		return ;
	}
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = ft_lstlast(*lst);
	tmp->next = new;
	if (ft_strncmp(tmp->value, "nil", 3))
		tmp->prev = ft_pre_lstlast(*lst);
	printf("prev  %s / tmp  %s / next  %s \n", (tmp->prev)->value, tmp->value, (tmp->next)->value);
}

t_list	*ft_lstnew_2(void *value, t_list *nil)
{
	t_list *lst_new;

	if (!(lst_new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	lst_new->value = value;
	lst_new->next = nil;
	// lst_new->prev = NULL;
	return (lst_new);
}

int main(int argc, char *argv[])
{
	int i = 1;
	t_list *list;
	t_list *nil;

	nil = put_setinel(&list, make_sentinel());
	// ft_lstadd_back_2(&list, ft_lstnew_2("INITIAL"));
	while (i <= argc)
	{
		// printf("OK\n");
		ft_lstadd_back_2(&list, ft_lstnew_2(argv[i], nil));
		i++;
	}

	print_content(list);
}
