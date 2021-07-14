#include <stdio.h>
#include <stdlib.h>
//get numbers as commandline arguments, then convert that into  array
int	ft_strlen(const char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_strlcpy(char *dst, const char *src, int dstsize)
{
	int	i;

	i = 0;
	if (!src || !dst)
		return (0);
	if (!dstsize)
		return (ft_strlen(src));
	while (i + 1 <= dstsize && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

int	array_num(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		while (str[i] && str[i] != ' ')
			i++;
		while (str[i] && str[i] == ' ')
			i++;
		res++;
	}
	return (res);
}

void	print_array(char **array, int cnt)
{
	int	i;

	i = 0;
	while (i < cnt)
	{
		printf("%s\n", array[i]);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int		n;
	int		i;
	int		len;
	char	*str;
	char	**array;

	n = 0;
	i = 0;
	str = argv[1];
	n = array_num(str);
	printf("str: %s\n", str);
	printf("array_num: %d\n", n);
	array = (char **)malloc(sizeof(char *) * (n + 1));
	while (n >= i + 1 && str)
	{
		len = 0;
		while (*str == ' ')
			str++;
		while (str[len] != ' ')
			len++;
		array[i] = (char *)malloc(sizeof(char) * (len + 1));
		ft_strlcpy(array[i], str, len);
		str += len;
		i++;
	}
	array[i] = NULL;
	print_array(array, i);
}
