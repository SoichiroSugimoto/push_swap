#ifndef DEAL_WITH_ERROR_H
# define DEAL_WITH_ERROR_H

# include <string.h>
# include <stdlib.h>
# include "../insert_contents/insert_contents.h"
# include "../use_operations/use_operations.h"
# include "../utils/utils.h"

char	*check_num_value(char *str);
void	check_duplication(int num1, int num2);
void	check_intrange(long long num);

#endif
