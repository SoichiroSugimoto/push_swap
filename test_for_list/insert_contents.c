#include "test_for_list.h"
#include <stdio.h>
#include <string.h>

char	*check_num_value(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if (!(48 <= str[i] && str[i] <= 57))
		{
			printf("Error\n");
			exit (0);
		}
		i++;
	}
	return (str);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next && ft_strncmp((lst->next)->value, "nil", 3))
		lst = lst->next;
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
	if (!lst)
	{
		lst = &new;
		return NULL;
	}
	if (!*lst)
	{
		*lst = new;
		return (new);
	}
	return NULL;
}

t_list	*ft_lstnew_2(void *value)
{
	t_list *lst_new;

	if (!(lst_new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	lst_new->value = value;
	return (lst_new);
}

void	ft_lstadd_back_2(t_list **lst, t_list *new)
{
	t_list	*tmp;
	t_list	*nil;

	if (!lst)
	{
		lst = &new;
		return ;
	}
	if (!*lst)
	{
		nil = put_setinel(lst, make_sentinel());
		*lst = nil;
	}
	else
	{
		(*lst) = ft_lstlast(*lst);
		tmp = *lst;
		(*lst)->next = new;
		new->prev = (*lst);
		new->next = nil;
		nil->prev = new;
	}
}

int main(int argc, char *argv[])
{
	int i = 1;
	t_list *list;

	ft_lstadd_back_2(&list, ft_lstnew_2(check_num_value(argv[i])));
	while (i < argc)
	{
		ft_lstadd_back_2(&list, ft_lstnew_2(check_num_value(argv[i])));
		i++;
	}

	print_circulatio_2nd(list);
	print_circulatio(list);
	// print_content(list);
}


// int main(int argc, char *argv[])
// {
// 	int i = 1;
// 	t_list *list;
// 	t_list *nil;

// 	nil = put_setinel(&list, make_sentinel());
// 	while (i < argc)
// 	{
// 		ft_lstadd_back_2(&list, ft_lstnew_2(argv[i], nil), nil);
// 		i++;
// 	}

// 	// print_circulatio(list);
// 	print_content(list);
// }
