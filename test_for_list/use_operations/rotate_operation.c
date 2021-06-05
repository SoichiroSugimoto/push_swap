#include "use_operations.h"

void	rotate_operation(t_list **lst)
{
	t_list *nil;

	catch_nil(lst);
	nil = *lst;
	catch_top(lst);
	nil->value = (*lst)->value;
	(*lst)->value = "nil";
}