#include "test_for_list.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
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
}

t_list	*ft_lstnew(void *content)
{
	t_list *lst_new;

	if (!(lst_new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	lst_new->value = content;
	lst_new->next = NULL;
	return (lst_new);
}

int main(int argc, char *argv[])
{
	int i = 1;
	t_list *list;

	while (i <= argc)
	{
		ft_lstadd_back(&list,ft_lstnew(argv[i]));
		i++;
	}

	print_content(list);
}
