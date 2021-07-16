#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*st;
	int		len;

	i = 0;
	len = ft_strlen(s);
	st = (char *)s;
	while (i <= len)
	{
		if (st[i] == c)
			return (&st[i]);
		i++;
	}
	return (0);
}
