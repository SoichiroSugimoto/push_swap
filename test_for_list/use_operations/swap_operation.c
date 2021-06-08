#include "use_operations.h"

void	swap_operation(t_list **lst)
{
	char *tmp;
	char *tmp2;

	if (count_list(*lst) > 1)
	{
		catch_top(lst);
		tmp = (*lst)->value;
		catch_2nd_top(lst);
		tmp2 = (*lst)->value;
		(*lst)->value = tmp;
		catch_top(lst);
		(*lst)->value = tmp2;
	}
}