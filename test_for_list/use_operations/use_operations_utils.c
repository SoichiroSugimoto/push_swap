#include "use_operations.h"

void	get_head(t_list **lst)
{
	while ((*lst)->next && ft_strncmp(((*lst)->next)->value, "nil", 3))
		*lst = (*lst)->next;
}