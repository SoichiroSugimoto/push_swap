#include "test_for_list.h"
#include "use_operations/use_operations.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int	check_nil(char *str)
{
	if (!(strcmp(str,"nil")))
	{
		// printf("nil");
		return (0) ;
	}
	return (1);
}

void	joudge_empty(t_list **lst)
{
	if (!*lst || !lst)
		printf("Empty\n");
}


void	print_2stacks(t_list *lst_a, t_list *lst_b)
{
	push_b_operation(&lst_a, &lst_b);
	// push_b_operation(&lst_a, &lst_b);
	// push_b_operation(&lst_a, &lst_b);
	// push_b_operation(&lst_a, &lst_b);
	// push_b_operation(&lst_a, &lst_b);

	push_a_operation(&lst_a, &lst_b);
	// push_a_operation(&lst_a, &lst_b);
	// push_a_operation(&lst_a, &lst_b);
	// push_a_operation(&lst_a, &lst_b);

	printf("\n");
	printf("---------------[a]\n");
	print_circulatio_2nd(lst_a);
	printf("\n");
	printf("---------------[b]\n");
	print_circulatio_2nd(lst_b);
	printf("--------------------------------------------\n");
	printf("\n\n");
}

void	print_circulatio_2nd(t_list *list)
{
	int i = 0;
	int j = 0;

	// while ((strcmp(list->value,"nil")))
	// 	list = list->next;
	// list = list->next;

	swap_operation(&list);
	// rotate_operation(&list);
	catch_top(&list);
	// catch_2nd_top(&list);
	// catch_bottom(&list);

	joudge_empty(&list);
	while(list)
	{
		printf("%d %s\n",i , list->value);
		if (check_nil(list->value) == 0)
			j++;
		if (j >= 2)
			break;
		list = list->next;
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