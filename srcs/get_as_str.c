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
	while (i <= cnt)
	{
		printf("             %s\n", array[i]);
		i++;
	}
}

void	malloc_error_double(char	**str)
{
	char	*txt;

	txt = "Error: malloc error\n";
	if (str == NULL)
	{
		ft_putstr_fd(txt, 1);
		exit (0);
	}
}

// split_str_num
char	**get_as_atr(char *str)
{
	int		n;
	int		i;
	int		len;
	char	**array;

	n = 0;
	i = 0;
	n = array_cnt(str);
	array = (char **)malloc(sizeof(char *) * n);
	malloc_error_double(array);
	while (n >= i + 1 && str)
	{
		len = 0;
		while (*str == ' ')
			str++;
		while (str[len] != ' ')
			len++;
		array[i] = (char *)malloc(sizeof(char) * (len + 1));
		malloc_error(array[i]);
		ft_strlcpy(array[i], str, len);
		printf("array[i]: %s\n", array[i]);////////
		str += len;
		i++;
	}
	array[i] = NULL;
	printf("array[i]: %s\n", array[i]);////////
	return (array);
}

// void	all_free(char **str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		free(str[i]);
// 		str[i] = NULL;
// 		i++;
// 	}
// }

void	sort_str_num(char *str, t_list **lst_a)
{
	char	**array;
	int		i;

	i = 0;
	array = get_as_atr(str);
	printf("array_cnt: %d\n", array_cnt(str));
	print_array(array, array_cnt(str));
	while (i < array_cnt(str))
	{
		if (ft_strlen(array[i]) >= 10)
			check_intrange(ft_atoi(array[i]));
		ft_lstadd_nilback(lst_a, ft_lstnew(check_num_value(array[i])));
		i++;
	}
	printf("--------------------------\n");
	print_circulatio2(*lst_a);
}
