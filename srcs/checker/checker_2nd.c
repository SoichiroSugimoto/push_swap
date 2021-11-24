#include "../../include/push_swap.h"

void	read_error(int n)
{
	char	*txt1;
	char	*txt2;

	txt1 = "Error: function;read error\n";
	txt2 = "Error: Operation is not existing.\n";
	if (n == -1)
	{
		ft_putstr_fd(txt1, 1);
		exit(0);
	}
	if (n > 4)
	{
		ft_putstr_fd(txt2, 1);
		exit(0);
	}
}

void	not_exist(void)
{
	ft_putstr_fd("Error: Operation is not existing.\n", 1);
	exit(0);
}
