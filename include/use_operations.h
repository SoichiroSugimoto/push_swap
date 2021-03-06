/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_operations.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:49:08 by sosugimo          #+#    #+#             */
/*   Updated: 2021/11/29 19:49:09 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USE_OPERATIONS_H
# define USE_OPERATIONS_H

# include "push_swap.h"

void	catch_nil(t_list **lst);
void	catch_top(t_list **lst);
void	catch_2nd_top(t_list **lst);
void	catch_bottom(t_list **lst);
void	swap_operation(t_list **lst);
void	swap_a(t_list **lst, t_ps *info);
void	swap_b(t_list **lst, t_ps *info);
void	ss(t_list **lst_a, t_list **lst_b);
void	rotate_operation(t_list **lst);
void	rotate_a(t_list **lst, t_ps *info);
void	rotate_b(t_list **lst, t_ps *info);
void	rr(t_list **lst_a, t_list **lst_b);
void	reverse_rotate_operation(t_list **lst);
void	reverse_rotate_a(t_list **lst, t_ps *info);
void	reverse_rotate_b(t_list **lst, t_ps *info);
void	rrr(t_list **lst_a, t_list **lst_b);
void	ft_lstadd_nilfront(t_list **lst, t_list *new);
int		all_isnil(t_list *lst);
void	push_operation(t_list **lst_a, t_list **lst_b);
void	push_b(t_list **lst_a, t_list **lst_b, t_ps *info);
void	push_a(t_list **lst_a, t_list **lst_b, t_ps *info);

#endif
