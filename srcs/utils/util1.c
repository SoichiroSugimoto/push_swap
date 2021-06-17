#include "utils.h"

int	check_nil(char *str)
{
	if (!(strcmp(str,"nil")))
		return (MATCH) ;
	return (1);
}
