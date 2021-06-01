#include "test_for_list.h"
#include <stdio.h>
#include <string.h>

t_list    *ft_lstlast(t_list *lst)
{
    if (!lst)
        return (NULL);
    while (lst->next && ft_strncmp((lst->next)->value, "nil", 3))
        lst = lst->next;
    return (lst);
}

t_list    *make_sentinel(void)
{
    t_list *lst_new;

    if (!(lst_new = (t_list *)malloc(sizeof(t_list))))
        return (NULL);
    lst_new->value = "nil";
    lst_new->next = lst_new;
    lst_new->prev = lst_new;
    return (lst_new);
}

void    ft_lstadd_back_3(t_list **top, t_list *new)
{
    (*top)->prev->next = new;
    (*top)->prev = new;
    new->prev = (*top)->prev;
    new->next = (*top);
}

t_list    *ft_lstnew_3(void *value)
{
    t_list *lst_new;

    if (!(lst_new = (t_list *)malloc(sizeof(t_list))))
        return (NULL);
    lst_new->value = value;
    lst_new->prev = NULL;
    lst_new->next = NULL;
    printf("[%s]  ", lst_new->value);
    return (lst_new);
}

int main(int argc, char *argv[])
{
    int i = 1;
    t_list *list;

    list = make_sentinel();
    while (i < argc)
    {
        ft_lstadd_back_3(&list, ft_lstnew_3(argv[i]));
        i++;
        printf("prev %s / tmp %s / next %s\n", (list->prev)->value, list->value, (list->next)->value);
    }
    print_circulatio(list);
}
