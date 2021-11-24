#include "../../include/push_swap.h"

void	ss_checker(t_list **lst_a, t_list **lst_b)
{
	swap_operation(lst_a);
	swap_operation(lst_b);
}

void	rr_checker(t_list **lst_a, t_list **lst_b)
{
	rotate_operation(lst_a);
	rotate_operation(lst_b);
}

void	rrr_checker(t_list **lst_a, t_list **lst_b)
{
	reverse_rotate_operation(lst_a);
	reverse_rotate_operation(lst_b);
}
