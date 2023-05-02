#include "minishell.h"

int	check_sep(char c, char *sep)
{
	int i;

	i = 0;
	while (sep && sep[i])
	{
		if (sep[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str && str[i])
		i++;
	return (i);
}