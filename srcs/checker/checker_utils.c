#include "../../include/insert_contents.h"
#include "../../include/sort_number.h"
#include "../../include/use_operations.h"
#include "../../include/utils.h"
#include "../../libft/libft.h"
#include "../../include/utils.h"
#include "../../include/checker.h"

void	free_for_checker(t_list **lst_a, t_list **lst_b, char **array)
{
	if (*lst_a != NULL)
		lst_all_free(lst_a);
	if (*lst_b != NULL)
		lst_all_free(lst_b);
	free_array(array);
}

void	safe_free2(char **st)
{
	free(*st);
	*st = NULL;
}
