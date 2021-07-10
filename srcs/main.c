#include <stdio.h>
#include "insert_contents/insert_contents.h"
#include "sort_number/sort_number.h"
#include "use_operations/use_operations.h"
#include "utils/utils.h"
#include "deal_with_error/deal_with_error.h"
#include "../libft/libft.h"

void	joudge_empty(t_list **lst)
{
	if (!*lst || !lst)
		printf("Empty\n");
}

void	print_circulatio(t_list *lst)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	catch_top(&lst);
	joudge_empty(&lst);
	while (lst)
	{
		printf("[%d]  %s\n",i , lst->value);
		if (check_nil(lst->value) == 0)
			j++;
		if (j >= 2)
			break ;
		lst = lst->next;
		i++;
	}
}

void	print_2stacks(t_list *lst_a, t_list *lst_b)
{
	printf("\n");
	printf("---------------[a]\n");
	print_circulatio(lst_a);
	printf("\n");
	printf("---------------[b]\n");
	print_circulatio(lst_b);
	printf("--------------------------------------------\n");
	printf("\n\n");
}

int	main(int argc, char *argv[])
{
	int		i;
	t_list	*lst_a;
	t_list	*lst_b;

	i = 1;
	while (i < argc)
	{
		if (ft_strlen(argv[i]) >= 10)
			check_intrange(ft_atoi(argv[i]));
		ft_lstadd_nilback(&lst_a, ft_lstnew(check_num_value(argv[i])));
		i++;
	}
	if (count_list(lst_a) >= 2 && confirm_sorted(lst_a) != 1)
		sort_number(&lst_a, &lst_b);
	printf("\n------- end --------\n\n");
	print_circulatio(lst_a);
}