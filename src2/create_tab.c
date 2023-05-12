#include "minishell.h"

int count_char(char *str)
{
	int i;
	int res;
	
	i = 0;
	res = 0;
	while(str && str[i])
	{
		if (str[i] == '\n')
			res++;
		i++;
	}
	return (res);
}

int	open_fd(char *file)
{
	int fd;

	fd = open(file, 00400);
	if (fd == -1)
		exit(1);
	return (fd);
}

int count_ligne(char *str)
{
	char	buf[1024];
	int 	rd;
	int 	line;
	int		fd;
	
	fd = open_fd(str);
	rd = 1024;
	line = 0;
	while (rd == 1024)
	{
		rd = read(fd, buf, 1024);
		if (rd < 0)
		{
			close(fd);
			exit (1);
		}
		buf[rd] = '\0';
		line += count_char(buf);
	}
	if (buf[rd-1] != '\n')
		line++;
	close(fd);
	return(line);
}


char	**create_tab(char *file)
{
	int		fd;
	char	**tab;
	int		i;
	int nb_ligne;

	i = 0;
	nb_ligne = count_ligne(file);
	tab = malloc(sizeof(char*) * (nb_ligne + 1));
	if (!tab)
		exit (1);
	fd = open(file, 00400);
	if (fd == -1)
		free(tab);
	while (i < nb_ligne)
	{
		tab[i] = get_next_line(fd);
		if (!tab[i])
		{
			free_tab(tab);
			exit (1);
		}
		i++;
	}
	tab[i] = 0;
	close(fd);
	return (tab);
}