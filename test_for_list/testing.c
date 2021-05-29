#include "test_for_list.h"
#include <stdio.h>

t_list	*ft_lstnew(void *content)
{
	t_list *lst_new;

	if (!(lst_new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	lst_new->value = content;
	lst_new->next = NULL;
	return (lst_new);
}

int main()
{
	t_list list;
	char *str = "42";
	// int *num;
	// int i = 42;
	// num = &i;

	list = *ft_lstnew(str);
	printf("------> %s\n", list.value);
}