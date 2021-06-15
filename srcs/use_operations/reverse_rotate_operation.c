#include "use_operations.h"

void	reverse_rotate_a(t_list **lst)
{
	reverse_rotate_operation(lst);
	ft_putstr_fd("rra\n", 1);
}

void	reverse_rotate_b(t_list **lst)
{
	reverse_rotate_operation(lst);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_list **lst_a, t_list **lst_b)
{
	reverse_rotate_operation(lst_a);
	reverse_rotate_operation(lst_b);
	ft_putstr_fd("rrr\n", 1);
}

void	reverse_rotate_operation(t_list **lst)
{
	t_list *nil;

	catch_nil(lst);
	nil = *lst;
	catch_bottom(lst);
	nil->value = (*lst)->value;
	(*lst)->value = "nil";
}
