#include "../include/utils.h"

int	check_nil(char *str)
{
	if (!(strcmp(str, "nil")))
		return (MATCH);
	return (1);
}

int	count_list(t_list *lst)
{
	int	res;

	res = 0;
	while (lst->next && ft_strncmp(lst->value, "nil", 3))
		lst = lst->next;
	lst = lst->next;
	while (lst->next && ft_strncmp(lst->value, "nil", 3))
	{
		lst = lst->next;
		res++;
	}
	return (res);
}

char	*check_num_value(char *str)
{
	int		i;
	char	*text;

	i = 0;
	text = "Error: some arguments aren’t integers.\n";
	while (str[i])
	{
		if (!((48 <= str[i] && str[i] <= 57) || str[i] == 45))
		{
			ft_putstr_fd(text, 1);
			exit (0);
		}
		i++;
	}
	return (str);
}

void	check_duplication(int num1, int num2)
{
	char	*text;

	text = "Error: some arguments are duplications.\n";
	if (num1 == num2)
	{
		ft_putstr_fd(text, 1);
		exit (0);
	}
}

void	check_intrange(long long num)
{
	char	*text_max;
	char	*text_min;

	text_max = "Error: some arguments are bigger than an integer\n";
	text_min = "Error: some arguments are smaller than an integer\n";
	if (num > INT_MAX)
	{
		ft_putstr_fd(text_max, 1);
		exit (0);
	}
	if (num < INT_MIN)
	{
		ft_putstr_fd(text_min, 1);
		exit (0);
	}
}
