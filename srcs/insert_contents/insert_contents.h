#ifndef INSERT_CONTENTS_H
# define INSERT_CONTENTS_H

// # include "../use_operations/use_operations.h"
// # include "../sort_number/sort_number.h"
// # include "../utils/utils.h"
# include <string.h>
# include <stdlib.h>

typedef struct		s_list
{
	char			*value;
	struct s_list 	*next;
	struct s_list 	*prev;
}					t_list;

int		check_nil(char *str);
char	*check_num_value(char *str);
t_list	*ft_lstlast(t_list *lst);
t_list	*make_sentinel();
t_list	*put_setinel(t_list **lst, t_list *new);
t_list	*ft_lstnew(void *value);
void	ft_lstadd_nilback(t_list **lst, t_list *new);

#endif