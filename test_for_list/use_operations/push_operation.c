#include "use_operations.h"

/////////        pb         //////////////
void	push_operation(t_list **lst_a, t_list **lst_b)
{
	t_list *nil_a;
	t_list *top_a;
	t_list *nil_b;
	t_list *top_b;


	//To eliminate top_a from Stack [a]
	catch_top(lst_a);
	top_a = *lst_a;
	catch_nil(lst_a);
	nil_a = *lst_a;
	catch_2nd_top(lst_a);
	(*lst_a)->prev = nil_a;
	nil_a->next = *lst_a;

	//To take top_a from Stack [b]
	ft_lstadd_nilback(&lst_b, top_a);
}








/////////        pa         //////////////
/*
void	push_operation(t_list **lst_a, t_list **lst_b)
{
	t_list *nil_b;
	t_list *top_b;
	t_list *nil_a;
	t_list *top_a;

	catch_top(lst_b);
	top_b = *lst_b;
	//To eliminate top_b from Stack b
	catch_nil(lst_b);
	nil_b = *lst_b;
	catch_2nd_top(lst_b);
	(*lst_b)->prev = nil_b;
	nil_b->next = (*lst_b);

	//To take top_b by Stack a
	catch_top(lst_a);
	(*lst_a)->prev = top_b;
	catch_nil(lst_a);
	nil_a = *lst_a;
	top_b->prev = nil_a;
	nil_a->next = top_b;
	top_b->next = top_a;
}
*/