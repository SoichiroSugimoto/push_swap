#include "use_operations.h"

void	reverse_rotate_operation(t_list **lst)
{
	t_list *nil;

	catch_nil(lst);
	nil = *lst;
	catch_bottom(lst);
	nil->value = (*lst)->value;
	(*lst)->value = "nil";
}