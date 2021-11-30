/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_contents.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:48:43 by sosugimo          #+#    #+#             */
/*   Updated: 2021/11/29 19:48:44 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSERT_CONTENTS_H
# define INSERT_CONTENTS_H

# include "push_swap.h"

int					check_nil(char *str);
t_list				*ft_lstlast(t_list *lst);
t_list				*make_sentinel(void);
t_list				*put_setinel(t_list **lst, t_list *new);
t_list				*ft_lstnew(void *value);
void				ft_lstadd_nilback(t_list **lst, t_list *new);
int					array_cnt(char *str);
void				print_array(char **array, int cnt);
void				free_array(char **array);
char				**split_str_num(char *str);
char				**get_as_str(char *str, t_list **lst_a);

#endif