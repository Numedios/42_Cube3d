#include "minishell.h"

void    print_tab(char **tab)
{
	int i;

	i = 0;
	while (tab && tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
}