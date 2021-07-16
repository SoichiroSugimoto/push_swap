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
void				ft_lstadd_nilback(t_list **lst, t_list *new);
void				malloc_error(void *point);
char				**get_as_atr(char *str);
void				sort_str_num(char *str, t_list **lst_a, t_list **lst_b);

#endif