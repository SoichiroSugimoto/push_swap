#ifndef UTILS_H
# define UTILS_H

# include "push_swap.h"

char		*check_num_value(char *str);
void		check_duplication(int num1, int num2);
void		check_intrange(long long num);
int			check_nil(char *str);
int			count_list(t_list *lst);
void		malloc_error(void *point);
void		free_b_nil(t_list **lst);
void		lst_all_free(t_list **lst_a);
void		init_lst(t_list **lst_a, t_list **lst_b);
int			ft_strlcpy2(char *dst, const char *src, int dstsize);

#endif
