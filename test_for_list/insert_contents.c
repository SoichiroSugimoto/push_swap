#include "test_for_list.h"
#include <stdio.h>
#include <string.h>

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next && ft_strncmp((lst->next)->value, "nil", 3))
		lst = lst->next;
	// printf("[%s]\n", lst->value);///////////////////////////////////
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
	while (tmp->next && ft_strncmp((tmp->next)->value, "nil", 3))
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
	if (!lst)
	{
		lst = &new;
		printf("----------1-----------\n");
		return NULL;
	}
	if (!*lst)
	{
		*lst = new;
		// printf("----------2-----------\n");
		// printf("setinel prev [[[[%s]]]]]\n", (new->prev)->value);
		// printf("setinel tmp  [[[[%s]]]]]\n", new->value);
		// printf("setinel next [[[[%s]]]]]\n", (new->next)->value);
		return (new);
	}
	return NULL;
}

// void	print_print(t_list *list)
// {
// 	while (list->next && ft_strncmp((list->next)->value, "nil", 3))
// 	{
// 		printf("%s /", list->value);
// 		list = list->next;
// 	}
// 	printf("\n");
// }

t_list	*ft_lstnew_2(void *value, t_list *nil)
{
	t_list *lst_new;

	if (!(lst_new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	lst_new->value = value;
	printf("[%s]  ", lst_new->value);
	lst_new->next = nil;
	// lst_new->prev = NULL;
	// printf("%s\n", (lst_new->next)->value);
	return (lst_new);
}

void	ft_lstadd_back_2(t_list **lst, t_list *new, t_list *nil)
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
	// printf("lst [%s] ", (*lst)->value);
	(*lst) = ft_lstlast(*lst);
	(*lst)->next = new;
	if (ft_strncmp((*lst)->value, "nil", 3))
		(*lst)->prev = ft_pre_lstlast(*lst);
	nil->prev = new;
	// printf("prev  %s / tmp  %s / next  %s \n", (tmp->prev)->value, tmp->value, (tmp->next)->value);
	/*
	printf("tmp %s ", tmp->value);/////////////////////////
	printf("----------%s\n", (*lst)->value);
	*/
	// printf("  <<<<prev  %s / lst  %s / next  %s \n", ((*lst)->prev)->value, (*lst)->value, ((*lst)->next)->value);
}

int main(int argc, char *argv[])
{
	int i = 1;
	t_list *list;
	t_list *nil;

	nil = put_setinel(&list, make_sentinel());
	while (i < argc)
	{
		// printf("OK\n");
		// printf("[tmp %s]", list->value);/////////////////////////
		ft_lstadd_back_2(&list, ft_lstnew_2(argv[i], nil), nil);
		i++;
		printf("prev %s / tmp %s / next %s\n", (list->prev)->value, list->value, (list->next)->value);
	}

	print_circulatio(list);
	// print_content(list);
}
