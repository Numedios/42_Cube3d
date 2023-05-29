/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 19:12:14 by sbelabba          #+#    #+#             */
/*   Updated: 2023/05/29 16:18:45 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*get_next_line(int fd)
{
	int			rd;
	char		*line;
	static char	buf[42 + 1];

	if (fd < 0 || fd > 1024 || read(fd, 0, 0) < 0)
		return (NULL);
	line = NULL;
	rd = 42;
	line = ft_strjoin_gnl(line, buf);
	while (rd == 42 && check_end(line) == 0)
	{
		rd = read(fd, buf, 42);
		if (rd < 0)
			return (NULL);
		buf[rd] = '\0';
		line = ft_strjoin_gnl(line, buf);
	}
	if (!line[0])
	{
		free(line);
		return (NULL);
	}
	get_line(line, buf);
	return (line);
}
