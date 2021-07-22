#ifndef INSERT_CONTENTS_H
# define INSERT_CONTENTS_H

# include <string.h>
# include <stdlib.h>

typedef struct s_list
{
	char			*value;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

int					check_nil(char *str);
t_list				*ft_lstlast(t_list *lst);
t_list				*make_sentinel(void);
t_list				*put_setinel(t_list **lst, t_list *new);
t_list				*ft_lstnew(void *value);
void				init_lst(t_list **lst_a, t_list **lst_b);
void				lst_all_free(t_list **lst_a);
void				free_b_nil(t_list **lst);
void				ft_lstadd_nilback(t_list **lst, t_list *new);
int					array_cnt(char *str);
void				print_array(char **array, int cnt);
void				malloc_error(void *point);
char				**split_str_num(char *str);
void				get_as_str(char *str, t_list **lst_a);

void				print_circulatio(t_list *lst);
void				print_2stacks(t_list *lst_a, t_list *lst_b);

#endif