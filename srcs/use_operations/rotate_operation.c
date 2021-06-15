#include "use_operations.h"

void	rotate_a(t_list **lst)
{
	rotate_operation(lst);
	ft_putstr_fd("ra\n", 1);
}

void	rotate_b(t_list **lst)
{
	rotate_operation(lst);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_list **lst_a, t_list **lst_b)
{
	rotate_operation(lst_a);
	rotate_operation(lst_b);
	ft_putstr_fd("rr\n", 1);
}

void	rotate_operation(t_list **lst)
{
	t_list *nil;

	catch_nil(lst);
	nil = *lst;
	catch_top(lst);
	nil->value = (*lst)->value;
	(*lst)->value = "nil";
}