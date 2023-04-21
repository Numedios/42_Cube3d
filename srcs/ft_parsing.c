/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:16:45 by zhamdouc          #+#    #+#             */
/*   Updated: 2023/04/21 19:00:01 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"



int first_parsing(char *argv)
{
	int len;
	int i;
	static char cmp[5] = ".cub";

	i = 4;
	len = ft_strlen(argv);
	if (len < 5)
	{
		ft_printf("bad argument");
		return (1);
	}
	while (i > 0)
	{
		argv[len] = cmp[i];
		i--;
		len--;
	}
	if (i != 0)
		return (1);
	return (0);
}

int	parsing_info(char **cube_info)
{
	if (ft_strncmp(cube_info[0], "NO", 2) != 0)
		return (free_tab(cube_info), 1);
	if (ft_strncmp(cube_info[1], "SO", 2) != 0)
		return (free_tab(cube_info), 1);
	if (ft_strncmp(cube_info[2], "WE", 2) != 0)
		return (free_tab(cube_info), 1);
	if (ft_strncmp(cube_info[3], "EA", 2) != 0)
		return (free_tab(cube_info), 1);
	if (ft_strncmp(cube_info[4], "F", 1) != 0)
		return (free_tab(cube_info), 1);
	if (ft_strncmp(cube_info[5], "C", 1) != 0)
		return (free_tab(cube_info), 1);
	return (0);
}

int	parsing_cube(int fd)
{
	char **cube_info;
	int i;
	
	i = 0;
	cube_info = malloc (sizeof(char *) * 7);
	while (i < 6)
	{
		cube_info[i] = get_next_line(fd);
		if (cube_info[i] && cube_info[i][0] == '\n')
			free(cube_info[i]);
		else
			i++;
	}
	cube_info[i] = NULL;
	if (parsing_info(cube_info) == 1)
		return (1);
	print_tab(cube_info);
	free_tab(cube_info);
	return (0);
}

int parsing(int argc, char *argv)
{
	int	fd;
	
	if (argc != 2)
		return (1);
	if (first_parsing(argv) == 1)
		return (1);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (1);
	if (parsing_cube(fd) == 1)
		return (1);
	
	return (0);
}