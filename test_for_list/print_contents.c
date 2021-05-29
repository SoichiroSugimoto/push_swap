#include "test_for_list.h"
#include <stdio.h>

void print_content(t_list *list)
{
	int i = 0;

	printf("HERE IS IN THE LIST\n\n");
	while(list)
	{
		printf("%s\n", list->value);
		list = list->next;
	}
}