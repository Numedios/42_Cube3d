/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:16:45 by zhamdouc          #+#    #+#             */
/*   Updated: 2023/04/24 18:06:46 by zhamdouc         ###   ########.fr       */
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
	if (!cube_info[0] ||ft_strncmp(cube_info[0], "NO", 2) != 0)
		return (1);
	if (!cube_info[1] ||ft_strncmp(cube_info[1], "SO", 2) != 0)
		return (1);
	if (!cube_info[2] ||ft_strncmp(cube_info[2], "WE", 2) != 0)
		return (1);
	if (!cube_info[3] || ft_strncmp(cube_info[3], "EA", 2) != 0)
		return (1);
	if (!cube_info[4] ||ft_strncmp(cube_info[4], "F", 1) != 0)
		return (1);
	if (!cube_info[5] ||ft_strncmp(cube_info[5], "C", 1) != 0)
		return (1);
	return (0);
}

int	parsing_cube(int fd, t_cube *cube)// si je fais une structure pour enregistrer les maps il faut return cub_info, donc un char **
{
	int i;
	
	i = 0;
	cube->info = malloc (sizeof(char *) * 7);
	while (i < 6)
	{
		cube->info[i] = get_next_line(fd);
		if (cube->info[i] && cube->info[i][0] == '\n')
			free(cube->info[i]);
		else
			i++;
	}
	cube->info[i] = NULL;
	if (parsing_info(cube->info) == 1)
		return (1);
	//print_tab(cube->info);
	//free_tab(cube->info);
	return (0);
}

int parsing(int argc, char *argv, t_cube *cube)
{
	int	fd;
	//close fd quand une fonction return 1, et free au bon moment, faire une structure qui contient les maps
	if (argc != 2)
		return (1);
	if (first_parsing(argv) == 1)
		return (1);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (1);
	if (parsing_cube(fd, cube) == 1)
		return (1);
	if (map_init(fd, argv, cube) == 1)
		return (1);
	return (0);
}