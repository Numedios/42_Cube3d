/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:38:41 by zhamdouc          #+#    #+#             */
/*   Updated: 2022/11/11 15:19:48 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	norminette(int *nxt, int *a);
static char	*save_end(int j, char *lecture, int i);

static char	*remplissage(int *i, char *lecture, char *the_line, int *nxt)
{
	char	*s;
	char	*copy_line;

	while (lecture[*i] != '\n' && lecture[*i] != '\0')
		*i = *i + 1;
	if (lecture[*i] == '\n')
	{
		*i = *i + 1;
		*nxt = *nxt + 1;
	}
	if (the_line == NULL)
		the_line = ft_substr(lecture, 0, *i);
	else
	{
		s = ft_substr(lecture, 0, *i);
		copy_line = the_line;
		the_line = ft_strjoin(copy_line, s);
		free(s);
		free(copy_line);
	}
	return (the_line);
}

char	*get_next_line(int fd)
{
	static char	lecture[BUFFER_SIZE];
	t_def		var;

	if (fd == -1)
		return (NULL);
	norminette(&var.nxt, &var.a);
	var.the_line = NULL;
	while (var.nxt == 0)
	{
		var.i = 0;
		if (lecture[var.i] != 0)
		{
			if (var.a < BUFFER_SIZE && var.a > 0)
				lecture[var.a] = 0;
			var.the_line = remplissage(&var.i, lecture, var.the_line, &var.nxt);
			save_end(var.j, lecture, var.i);
		}
		else
		{
			var.a = read (fd, lecture, BUFFER_SIZE);
			if (var.a <= 0)
				return (var.the_line);
		}
	}
	return (var.the_line);
}

static void	norminette(int *nxt, int *a)
{
	*nxt = 0;
	*a = 0;
}

static char	*save_end(int j, char *lecture, int i)
{
	j = -1;
	while (lecture[i])
		lecture[++j] = lecture[i++];
	lecture[j + 1] = 0;
	return (lecture);
}
// quel difference entre envoyer buf ou &buf pour le remplissage
//gcc -Wall -Werror -Wextra -D BUFFER_SIZE=42 get_next_line.c 
//get_next_line_utils.c get_next_line.h -g
/*
int	main()
{
	int	fd;
	int i;

	i = 0;
	//title("files/41_no_nl: ");
	fd = open("test.txt", O_RDWR);
	while (i < 2)
	{
		printf("%d : %s\n", i, get_next_line (fd));
		i++;
	}
}*/