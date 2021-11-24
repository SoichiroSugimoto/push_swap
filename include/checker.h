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

#endif
