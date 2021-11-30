/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:48:37 by sosugimo          #+#    #+#             */
/*   Updated: 2021/11/30 12:30:32 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

void	checker_swap(t_list **lst);
void	checker_push(t_list **lst_a, t_list **lst_b);
void	checker_rotate(t_list **lst);
void	checker_reverse_rotate(t_list **lst);
void	ss_checker(t_list **lst_a, t_list **lst_b);
void	rr_checker(t_list **lst_a, t_list **lst_b);
void	rrr_checker(t_list **lst_a, t_list **lst_b);
void	read_error(int n);
void	not_exist(void);
void	free_for_checker(t_list **lst_a, t_list **lst_b, char **array);
void	safe_free2(char **st);
void	checker_exec(t_list **lst_a, t_list **lst_b);
void	init_array(char *array, int n);
void	exec_operation(char *cmd, t_list **lst_a, t_list **lst_b);

#endif
