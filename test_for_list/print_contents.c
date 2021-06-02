#include "test_for_list.h"
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