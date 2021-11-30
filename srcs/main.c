/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:50:58 by sosugimo          #+#    #+#             */
/*   Updated: 2021/11/30 12:08:16 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_set(t_list **lst_a, t_list **lst_b, char **array)
{
	lst_all_free(lst_a);
	free_b_nil(lst_b);
	free_array(array);
}

void	args_error(int argc)
{
	if (argc == 1)
		exit (0);
}

int	main(int argc, char *argv[])
{
	int		i;
	char	**array;
	t_list	*lst_a;
	t_list	*lst_b;

	args_error(argc);
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
	free_set(&lst_a, &lst_b, array);
}
