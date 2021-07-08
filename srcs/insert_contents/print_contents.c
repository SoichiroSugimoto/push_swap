#include "insert_contents.h"
#include "../use_operations/use_operations.h"
#include "../sort_number/sort_number.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// int	check_nil(char *str)
// {
// 	if (!(strcmp(str,"nil")))
// 		return (0) ;
// 	return (1);
// }

void	joudge_empty(t_list **lst)
{
	if (!*lst || !lst)
		printf("Empty\n");
}


void	print_2stacks(t_list *lst_a, t_list *lst_b)
{
	printf("\n");
	printf("---------------[a]\n");
	print_circulatio_2nd(lst_a);
	printf("\n");
	printf("---------------[b]\n");
	print_circulatio_2nd(lst_b);
	printf("--------------------------------------------\n");
	printf("\n\n");
}

void	operation_x(t_list **lst_a, t_list **lst_b)
{
	push_b(lst_a, lst_b);
	push_b(lst_a, lst_b);
	push_b(lst_a, lst_b);

	printf("    ############\n");
	push_a(lst_a, lst_b);
	push_a(lst_a, lst_b);
	push_a(lst_a, lst_b);

	printf("    ############\n");
	push_b(lst_a, lst_b);
	push_b(lst_a, lst_b);
	push_b(lst_a, lst_b);

	printf("    ############\n");
	push_a(lst_a, lst_b);
	push_a(lst_a, lst_b);
	push_a(lst_a, lst_b);
	push_a(lst_a, lst_b);
	push_a(lst_a, lst_b);
	push_a(lst_a, lst_b);
}

void	print_circulatio_2nd(t_list *lst)
{
	int i = 0;
	int j = 0;

	catch_top(&lst);
	joudge_empty(&lst);
	while(lst)
	{
		printf("[%d]  %s\n",i , lst->value);
		if (check_nil(lst->value) == 0)
			j++;
		if (j >= 2)
			break;
		lst = lst->next;
		i++;
	}
}











void print_content(t_list *list)
{
	int i = 0;

	while ((strcmp(list->value,"nil")))
		list = list->next;
	list = list->next;
	printf("HERE IS IN THE LIST\n\n");
	while(list)
	{
		printf("%d %s\n",i , list->value);
		if (check_nil(list->value) == 0)
			break;
		list = list->next;
		i++;
	}
	printf("\nOPPOSIOTION\n");
	while(i >= 1)
	{
		list = list->prev;
		printf("%d %s\n", i, list->value);
		if (check_nil(list->value) == 0)
		{
			printf("nil\n");
			break;
		}
		i--;
	}
	printf("\n\nFin\n");
}

void	print_circulatio(t_list *list)
{
	int i = 0;
	int j = 0;

	while ((strcmp(list->value,"nil")))
		list = list->prev;
	list = list->prev;

	printf("\n\n");
	while(list)
	{
		printf("%d %s\n",i , list->value);
		if (check_nil(list->value) == 0)
			j++;
		if (j >= 4)
			break;
		list = list->prev;
		i++;
	}
}