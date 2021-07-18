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

// void	print_array(char **array, int cnt)
// {
// 	int	i;

// 	i = 0;
// 	while (i < cnt)
// 	{
// 		printf("%s\n", array[i]);
// 		i++;
// 	}
// }

void	lst_all_free(t_list **lst_a)
{
	catch_top(lst_a);
	while (check_nil((*lst_a)->value) != 1)
	{
		printf("       *lst_a: %s", (*lst_a)->value);
		free(*lst_a);
		*lst_a = (*lst_a)->next;
	}
	printf("       *lst_a: %s", (*lst_a)->value);
	free(*lst_a);
}

int	main(int argc, char *argv[])
{
	int		i;
	// char	**array;
	t_list	*lst_a;
	t_list	*lst_b;

	if (argc == 2 && ft_strchr(argv[1], ' '))
	{
		sort_str_num(argv[1], &lst_a);
		// i = 0;
		// array = get_as_atr(argv[1]);
		// print_array(array, array_cnt(argv[1]));
		// while (i < array_cnt(argv[1]))
		// {
		// 	if (ft_strlen(array[i]) >= 10)
		// 		check_intrange(ft_atoi(array[i]));
		// 	ft_lstadd_nilback(&lst_a, ft_lstnew(check_num_value(array[i])));
		// 	i++;
		// }
		// printf("--------------------------\n");
		// print_circulatio(lst_a);
	}
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
	print_circulatio(lst_a);
	lst_all_free(&lst_a);
	// system("leaks push_swap");
}
