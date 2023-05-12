#include "minishell.h"

static int	world_cmp(char const *str, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] && str[i] != c)
			len++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (len + 1);
}

static char	*world_len(char const *str, char c)
{
	int		i;
	int		len;
	char	*world;

	i = 0;
	len = 0;
	while (str[i] && str[i] != c)
	{
		len++;
		i++;
	}
	world = malloc(sizeof(char) * (len + 1));
	if (!world)
		return (NULL);
	i = 0;
	while (i < len)
	{
		world[i] = str[i];
		i++;
	}
	world[i] = '\0';
	return (world);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	char	*world;
	int		i;

	i = 0;
	res = malloc(sizeof(char *) * world_cmp(s, c));
	if (!res)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			world = world_len(s, c);
			res[i] = world;
			i++;
		}
		while (*s && *s != c)
			s++;
	}
	res[i] = 0;
	return (res);
}