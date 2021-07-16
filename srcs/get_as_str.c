#include <stdio.h>
#include "../include/insert_contents.h"
#include "../include/sort_number.h"
#include "../include/use_operations.h"
#include "../include/utils.h"
#include "../libft/libft.h"

int	array_cnt(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		while (str[i] && str[i] != ' ')
			i++;
		while (str[i] && str[i] == ' ')
			i++;
		res++;
	}
	return (res);
}

void	joudge_empty2(t_list **lst)
{
	if (!*lst || !lst)
		printf("Empty\n");
}

void	print_circulatio2(t_list *lst)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	catch_top(&lst);
	joudge_empty2(&lst);
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

void	print_2stacks2(t_list *lst_a, t_list *lst_b)
{
	printf("\n");
	printf("---------------[a]\n");
	print_circulatio2(lst_a);
	printf("\n");
	printf("---------------[b]\n");
	print_circulatio2(lst_b);
	printf("--------------------------------------------\n");
	printf("\n\n");
}

void	print_array(char **array, int cnt)
{
	int	i;

	i = 0;
	while (i < cnt)
	{
		printf("%s\n", array[i]);
		i++;
	}
}

char	**get_as_atr(char *str)
{
	int		n;
	int		i;
	int		len;
	char	**array;

	n = 0;
	i = 0;
	n = array_cnt(str);
	printf("str: %s\n", str);
	printf("array_cnt: %d\n", n);
	array = (char **)malloc(sizeof(char *) * (n + 1));
	while (n >= i + 1 && str)
	{
		len = 0;
		while (*str == ' ')
			str++;
		while (str[len] != ' ')
			len++;
		array[i] = (char *)malloc(sizeof(char) * (len + 1));
		ft_strlcpy(array[i], str, len);
		str += len;
		i++;
	}
	array[i] = NULL;
	return (array);
}

void	sort_str_num(char *str, t_list **lst_a, t_list **lst_b)
{
	char	**array;
	int		cnt;
	int		i;

	i = 0;
	cnt = array_cnt(str);
	array = get_as_atr(str);
	while (i < cnt)
	{
		if (ft_strlen(array[i]) >= 10)
			check_intrange(ft_atoi(array[i]));
		ft_lstadd_nilback(lst_a, ft_lstnew(check_num_value(array[i])));
		i++;
	}
	if (count_list(*lst_a) >= 2 && confirm_sorted(*lst_a) != 1)
		sort_number(lst_a, lst_b);
	printf("\n------- end --------\n\n");
	print_circulatio2(*lst_a);
	system("leaks push_swap");
}
