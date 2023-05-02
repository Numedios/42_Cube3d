#include "minishell.h"

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
