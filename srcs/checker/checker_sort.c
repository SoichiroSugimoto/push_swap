/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:29:43 by sosugimo          #+#    #+#             */
/*   Updated: 2021/12/07 22:06:47 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	exec_operation(char *cmd, t_list **lst_a, t_list **lst_b)
{
	if (ft_strncmp(cmd, "sa", ft_strlen(cmd)) == 0)
		checker_swap(lst_a);
	else if (ft_strncmp(cmd, "sb", ft_strlen(cmd)) == 0)
		checker_swap(lst_b);
	else if (ft_strncmp(cmd, "ss", ft_strlen(cmd)) == 0)
		ss_checker(lst_a, lst_b);
	else if (ft_strncmp(cmd, "pa", ft_strlen(cmd)) == 0)
		checker_push(lst_b, lst_a);
	else if (ft_strncmp(cmd, "pb", ft_strlen(cmd)) == 0)
		checker_push(lst_a, lst_b);
	else if (ft_strncmp(cmd, "ra", ft_strlen(cmd)) == 0)
		checker_rotate(lst_a);
	else if (ft_strncmp(cmd, "rb", ft_strlen(cmd)) == 0)
		checker_rotate(lst_b);
	else if (ft_strncmp(cmd, "rr", ft_strlen(cmd)) == 0)
		rr_checker(lst_a, lst_b);
	else if (ft_strncmp(cmd, "rra", ft_strlen(cmd)) == 0)
		checker_reverse_rotate(lst_a);
	else if (ft_strncmp(cmd, "rrb", ft_strlen(cmd)) == 0)
		checker_reverse_rotate(lst_b);
	else if (ft_strncmp(cmd, "rrr", ft_strlen(cmd)) == 0)
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
	char	*cmd;

	n = 0;
	cmd = NULL;
	while (n > -1)
	{
		n = get_next_line(0, &cmd);
		if (n == -1)
		{
			free(cmd);
			break ;
		}
		if (*cmd != '\0')
			exec_operation(cmd, lst_a, lst_b);
		free(cmd);
		if (n == 0)
			break ;
	}
	read_error(n);
}
