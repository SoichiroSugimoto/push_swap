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


char	*check_num_value(char *str);
t_list	*ft_lstlast(t_list *lst);
t_list	*make_sentinel();
t_list	*put_setinel(t_list **lst, t_list *new);
t_list	*ft_lstnew(void *value);
void	ft_lstadd_nilback(t_list **lst, t_list *new);
void	print_content(t_list *list);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	print_circulatio(t_list *list);
void	print_circulatio_2nd(t_list *list);
void	print_2stacks(t_list *lst_a, t_list *lst_b);


#endif