#include "use_operations.h"
#include <stdio.h>

void	push_b(t_list **lst_a, t_list **lst_b)
{
	push_operation(lst_a, lst_b);
	ft_putstr_fd("pb\n", 1);
}

void	push_a(t_list **lst_a, t_list **lst_b)
{
	push_operation(lst_b, lst_a);
	ft_putstr_fd("pa\n", 1);
}

void	push_operation(t_list **lst_a, t_list **lst_b)
{
	t_list *nil_a;
	t_list *top_a;

	catch_top(lst_a);
	top_a = *lst_a;
	catch_nil(lst_a);
	nil_a = *lst_a;
	if (!(count_list(*lst_a) <= 1))
		catch_2nd_top(lst_a);
	(*lst_a)->prev = nil_a;
	nil_a->next = *lst_a;
	top_a->next = NULL;
	top_a->prev = NULL;
	ft_lstadd_nilfront(lst_b, top_a);
}

void	ft_lstadd_nilfront(t_list **lst, t_list *new)
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
	catch_top(lst);
	(*lst)->prev = new;
	new->prev = nil;
	new->next = *lst;
	nil->next = new;
}

void	delete_nil(t_list *lst)
{
	if (count_list(lst) == 1)
		free(&lst);
}
