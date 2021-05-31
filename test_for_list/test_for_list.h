#ifndef TEST_FOR_CONTENTS_H
# define TEST_FOR_CONTENTS_H

# include <string.h>
# include <stdlib.h>

typedef struct		s_list
{
	char *value;
	struct s_list *next;
	struct s_list *prev;
}					t_list;

void	print_content(t_list *list);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
t_list	*ft_lstnew(void *value);
t_list	*ft_lstlast(t_list *lst);


#endif