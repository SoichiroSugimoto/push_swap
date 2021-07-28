#include "../../include/insert_contents.h"
#include "../../include/sort_number.h"
#include "../../include/use_operations.h"
#include "../../include/utils.h"
#include "../../libft/libft.h"
#include "../../include/utils.h"
#include "../../include/checker.h"

void	read_error(int n)
{
	char	*txt1;
	char	*txt2;

	txt1 = "Error: function;read error\n";
	txt2 = "Error: Operation is not existing.\n";
	if (n == -1)
	{
		printf("%s", txt1);
		exit(0);
	}
	if (n > 4)
	{
		printf("%s", txt2);
		exit(0);
	}
}

void	not_exist(void)
{
	printf("Error: Operation is not existing.\n");
	exit(0);
}
