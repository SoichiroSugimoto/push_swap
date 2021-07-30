#include "../../include/insert_contents.h"
#include "../../include/sort_number.h"
#include "../../include/use_operations.h"
#include "../../include/utils.h"
#include "../../libft/libft.h"
#include "../../include/utils.h"
#include "../../include/checker.h"

void	exec_operation(char *cmd, t_list **lst_a, t_list **lst_b)
{
	if (ft_strncmp(cmd, "sa", ft_strlen(cmd) - 1) == 0)
		checker_swap(lst_a);
	else if (ft_strncmp(cmd, "sb", ft_strlen(cmd) - 1) == 0)
		checker_swap(lst_b);
	else if (ft_strncmp(cmd, "ss", ft_strlen(cmd) - 1) == 0)
		ss_checker(lst_a, lst_b);
	else if (ft_strncmp(cmd, "pa", ft_strlen(cmd) - 1) == 0)
		checker_push(lst_b, lst_a);
	else if (ft_strncmp(cmd, "pb", ft_strlen(cmd) - 1) == 0)
		checker_push(lst_a, lst_b);
	else if (ft_strncmp(cmd, "ra", ft_strlen(cmd) - 1) == 0)
		checker_rotate(lst_a);
	else if (ft_strncmp(cmd, "rb", ft_strlen(cmd) - 1) == 0)
		checker_rotate(lst_b);
	else if (ft_strncmp(cmd, "rr", ft_strlen(cmd) - 1) == 0)
		rr_checker(lst_a, lst_b);
	else if (ft_strncmp(cmd, "rra", ft_strlen(cmd) - 1) == 0)
		checker_reverse_rotate(lst_a);
	else if (ft_strncmp(cmd, "rrb", ft_strlen(cmd) - 1) == 0)
		checker_reverse_rotate(lst_b);
	else if (ft_strncmp(cmd, "rrr", ft_strlen(cmd) - 1) == 0)
		rrr_checker(lst_a, lst_b);
	else
		not_exist();
}

void	init_array(char *array, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		array[i] = '\0';
		i++;
	}
}

void	checker_exec(t_list **lst_a, t_list **lst_b)
{
	int		n;
	char	cmd[5];

	n = 2;
	init_array(cmd, 5);
	while (n > 1)
	{
		n = read(0, cmd, sizeof(char) * 5);
		if (n == 1)
			break ;
		read_error(n);
		exec_operation(cmd, lst_a, lst_b);
		init_array(cmd, 4);
	}
}

void	judge_checker(t_list *lst_a, t_list *lst_b)
{
	if (check_sorted(lst_a, lst_b) == 1)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
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
	checker_exec(&lst_a, &lst_b);
	judge_checker(lst_a, lst_b);
	free_for_checker(&lst_a, &lst_b, array);
}
