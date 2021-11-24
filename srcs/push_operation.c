/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:52:10 by sosugimo          #+#    #+#             */
/*   Updated: 2021/11/24 16:02:48 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_b(t_list **lst_a, t_list **lst_b, t_ps *info)
{
	if (*lst_a != NULL && all_isnil(*lst_a) != 1)
	{
		push_operation(lst_a, lst_b);
		info->result = join_char(info->result, PB);
	}
}

void	push_a(t_list **lst_a, t_list **lst_b, t_ps *info)
{
	if (*lst_b != NULL && all_isnil(*lst_b) != 1)
	{
		push_operation(lst_b, lst_a);
		info->result = join_char(info->result, PA);
	}
}

void	push_operation(t_list **lst_a, t_list **lst_b)
{
	t_list	*nil_a;
	t_list	*top_a;

	catch_top(lst_a);
	top_a = *lst_a;
	catch_nil(lst_a);
	nil_a = *lst_a;
	if (!(count_list(*lst_a) <= 1))
		catch_2nd_top(lst_a);
	(*lst_a)->prev = nil_a;
	nil_a->next = *lst_a;
	top_a->next = NULL;
	top_a->prev = NULL;
	ft_lstadd_nilfront(lst_b, top_a);
}

void	ft_lstadd_nilfront(t_list **lst, t_list *new)
{
	t_list	*nil;

	if (!lst)
	{
		lst = &new;
		return ;
	}
	if (!*lst)
	{
		nil = put_setinel(lst, make_sentinel());
		*lst = nil;
	}
	catch_nil(lst);
	nil = *lst;
	catch_top(lst);
	(*lst)->prev = new;
	new->prev = nil;
	new->next = *lst;
	nil->next = new;
}

int	all_isnil(t_list *lst)
{
	catch_nil(&lst);
	if (!(check_nil((lst->next)->value)))
		return (1);
	else
		return (0);
}
