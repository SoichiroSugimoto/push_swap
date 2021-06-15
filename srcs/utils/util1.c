#include "utils.h"

int	check_nil(char *str)
{
	if (!(strcmp(str,"nil")))
		return (0) ;
	return (1);
}
