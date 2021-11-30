/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:50:06 by sosugimo          #+#    #+#             */
/*   Updated: 2021/11/30 13:33:36 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	dupcheck_for_checker(t_list *lst)
{
	int	vol;
	int	i;
	int	*num;

	i = 0;
	vol = count_list(lst);
	num = (int *)malloc(sizeof(int) * vol);
	malloc_error(num);
	lst_to_array(lst, num);
	quick_sort(num, 0, vol - 1);
	while (i < vol - 1)
	{
		check_duplication(num[i], num[i + 1]);
		i++;
	}
	free(num);
}

void	checker_args_error(int argc)
{
	if (argc == 1)
		exit(0);
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

	checker_args_error(argc);
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
	dupcheck_for_checker(lst_a);
	checker_exec(&lst_a, &lst_b);
	judge_checker(lst_a, lst_b);
	free_for_checker(&lst_a, &lst_b, array);
}
