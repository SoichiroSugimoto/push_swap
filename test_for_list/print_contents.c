#include "test_for_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void	check_nil(char *str)
{
	if (!(strcmp(str,"nil")))
	{
		printf("nil");
		exit(0) ;
	}
	return ;
}

void print_content(t_list *list)
{
	int i = 0;

	printf("HERE IS IN THE LIST\n\n");
	while(list)
	{
		printf("%d %s\n",i , list->value);
		check_nil(list->value);
		list = list->next;
		i++;
	}
	printf("\nOPPOSIOTION\n");
	while(i >= 1)
	{
		list = list->prev;
		printf("%d %s\n", i, list->value);
		check_nil(list->value);
		i--;
	}
}