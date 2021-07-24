#include <stdio.h>
#include "../include/insert_contents.h"
#include "../include/sort_number.h"
#include "../include/use_operations.h"
#include "../include/utils.h"
#include "../libft/libft.h"

void	malloc_error(void *point)
{
	char	*txt;

	txt = "Error: malloc error\n";
	if (point == NULL)
	{
		ft_putstr_fd(txt, 1);
		exit (0);
	}
}

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

void	free_b_nil(t_list **lst)
{
	catch_nil(lst);
	if (*lst != NULL)
		free(*lst);
}

void	lst_all_free(t_list **lst_a)
{
	t_list	*tmp;

	catch_top(lst_a);
	while (check_nil((*lst_a)->value) != 0)
	{
		tmp = *lst_a;
		*lst_a = (*lst_a)->next;
		free(tmp);
		tmp = NULL;
	}
	free(*lst_a);
}

void	init_lst(t_list **lst_a, t_list **lst_b)
{
	*lst_a = NULL;
	*lst_b = NULL;
}

int	main(int argc, char *argv[])
{
	int		i;
	char	**array;
	t_list	*lst_a;
	t_list	*lst_b;

	array = NULL;
	init_lst(&lst_a, &lst_b);
	if (argc == 2 && ft_strchr(argv[1], ' '))
		array = get_as_str(argv[1], &lst_a);
	else
	{
		i = 1;
		while (i < argc)
		{
			if (ft_strlen(argv[i]) >= 10)
				check_intrange(ft_atoi(argv[i]));
			ft_lstadd_nilback(&lst_a, ft_lstnew(check_num_value(argv[i])));
			i++;
		}
	}
	if (count_list(lst_a) >= 2 && confirm_sorted(lst_a) != 1)
		sort_number(&lst_a, &lst_b);
	if (lst_b != NULL)
		print_2stacks(lst_a, lst_b);
	lst_all_free(&lst_a);
	free_b_nil(&lst_b);
	free_array(array);
	// system("leaks push_swap");
	// 8 77 34 10 9 1 54 4 7 66 32
	// ./push_swap 8 77 34 10 9 1 54 4 7 66 44 79 0 17 81 100 62 90 15 200 47 3
	// ./push_swap 8 77 34 10 9 1 54 4 7 66 44 79 0 17 81 100 62 90 15 200 47 3
	// ./push_swap 8 77 34 10 9 1 54 4 7 66 44 79 0 17 81 100 62 90 15 200 47
	// ./push_swap 8 77 34 10 9 1 54 4 7 66 32
	// ./push_swap 8 77 34 10 9 1 54 4 7 66
}
