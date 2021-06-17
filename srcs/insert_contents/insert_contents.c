#include "insert_contents.h"
#include "../use_operations/use_operations.h"
#include "../sort_number/sort_number.h"
#include "../utils/utils.h"
#include <stdio.h>
#include <string.h>

char	*check_num_value(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if (!((48 <= str[i] && str[i] <= 57) || str[i] == 45))
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

t_list	*ft_lstnew(void *value)
{
	t_list *lst_new;

	if (!(lst_new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	// printf("value  ----> %s\n", value);
	// printf("num :value  ----> %d\n", ft_atoi(value));
	lst_new->value = value;
	lst_new->next = NULL;
	return (lst_new);
}

void	ft_lstadd_nilback(t_list **lst, t_list *new)
{
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
	catch_nil(lst);
	nil = *lst;
	(*lst) = ft_lstlast(*lst);
	(*lst)->next = new;
	new->prev = (*lst);
	new->next = nil;
	nil->prev = new;
}

int main(int argc, char *argv[])
{
	int i = 1;
	t_list *lst_a;
	t_list *lst_b;

	while (i < argc)
	{
		ft_lstadd_nilback(&lst_a, ft_lstnew(check_num_value(argv[i])));
		i++;
	}

	print_circulatio_2nd(lst_a);
	sort_number(&lst_a, &lst_b);
	printf("\n\n");
	print_circulatio_2nd(lst_a);
}
