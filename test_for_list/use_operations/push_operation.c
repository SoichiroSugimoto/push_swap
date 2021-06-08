#include "use_operations.h"
#include <stdio.h>

/////////        pb         //////////////
void	push_b_operation(t_list **lst_a, t_list **lst_b)
{
	t_list *nil_a;
	t_list *top_a;

	//To eliminate top_a from Stack [a]
	catch_top(lst_a);
	top_a = *lst_a;
	catch_nil(lst_a);
	nil_a = *lst_a;
	if (!(count_list(*lst_a) <= 1))
		catch_2nd_top(lst_a);
	(*lst_a)->prev = nil_a;
	nil_a->next = *lst_a;

	//To take top_a from Stack [b]
	top_a->next = NULL;
	top_a->prev = NULL;
	ft_lstadd_nilfront(lst_b, top_a);
	// delete_nil(*lst_a);
}

/////////        pa         //////////////
void	push_a_operation(t_list **lst_a, t_list **lst_b)
{
	t_list *nil_b;
	t_list *top_b;

	catch_top(lst_b);
	top_b = *lst_b;
	catch_nil(lst_b);
	nil_b = *lst_b;
	if (!(count_list(*lst_b) <= 1))
		catch_2nd_top(lst_b);
	(*lst_b)->prev = nil_b;
	nil_b->next = *lst_b;
	top_b->next = NULL;
	top_b->prev = NULL;
	ft_lstadd_nilfront(lst_a, top_b);
	// delete_nil(*lst_b);
}

void	ft_lstadd_nilfront(t_list **lst, t_list *new)
{
	t_list	*nil;
	// t_list	*top;

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
	// top = *lst;
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
