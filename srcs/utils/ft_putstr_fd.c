#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	int i;

	i = 0;
	if (!s || !fd)
		return ;
	while (s[i] && fd)
	{
		write(fd, &s[i], 1);
		i++;
	}
}