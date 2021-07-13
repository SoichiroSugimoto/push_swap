#include "../include/insert_contents.h"
#include "../include/use_operations.h"
#include "../include/sort_number.h"
#include "../include/utils.h"
#include "../libft/libft.h"
#include <stdio.h>
#include <string.h>

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next && ft_strncmp((lst->next)->value, "nil", 3))
		lst = lst->next;
	return (lst);
}

t_list	*make_sentinel(void)
{
	t_list	*lst_new;

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
		return (NULL);
	}
	if (!*lst)
	{
		*lst = new;
		return (new);
	}
	return (NULL);
}

t_list	*ft_lstnew(void *value)
{
	t_list	*lst_new;

	if (!(lst_new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
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