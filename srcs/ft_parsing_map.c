/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakariyahamdouchi <zakariyahamdouchi@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:55:06 by zhamdouc          #+#    #+#             */
/*   Updated: 2023/04/26 19:40:24 by zakariyaham      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"
//check avec map vide
int	fill_map(int fd, char **cube_map, int len)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < len)
	{
		cube_map[i] = get_next_line(fd);
		i++;
	}
	cube_map[i] = NULL;
	i = 0;
	while (cube_map[i][0] == '\n')
		i++;
	while (i < len)
	{
		if (cube_map[i][0] == '\n')
		{
			i++;
			while (cube_map[i])
			{
				while (cube_map[i][j])
				{
					if (cube_map[i][j] && cube_map[i][j] !='\n' && (cube_map[i][j] != ' ' && (cube_map[i][j] > 14 && cube_map[i][j] < 8)))
						return (1);
					j++;
				}
				j = 0;
				i++;
			}
			return (0);
		}
		i++;
	}
	return (0);
}
//skip tous les espaces pas seulement ' '

void	skip_space(char **cube_map)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (cube_map[i])
	{
		while (cube_map[i][j] == ' ' || (cube_map[i][j] < 14 && cube_map[i][j] > 8))
			j++;
		if (j > 0)
		{
			while (cube_map[i][j] && cube_map[i][j] != '\n')
			{
				cube_map[i][k] = cube_map[i][j];
				j++;
				k++;
			}
			while (cube_map[i][k] && cube_map[i][k] != '\n')
			{
				cube_map[i][k] = ' ';
				k++;
			}
			k = 0;
		}
		j = 0;
		i++;
	}
}
/*
tester qu'il ne peut avoir despace dans une ligne
demain finir le parsing, carte entourer de mur et N S E W
comment faire si la map ne finis pas par un '\n' !!!
*/
int	no_space(char **cube_map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (cube_map[i])
	{
		while (cube_map[i][j] && cube_map[i][j] != '\n')
		{
			if (cube_map[i][j] == ' ' || (cube_map[i][j] < 14 && cube_map[i][j] > 8))
			{
				while (cube_map[i][j] && cube_map[i][j] != '\n')
				{
					if (cube_map[i][j] == ' ' || (cube_map[i][j] < 14 && cube_map[i][j] > 8))
						return (1);
					j++;
				}
			}
			if (cube_map[i][j] != '\n')
				j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

// int	check_inside(char **cube_map, int len)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (cube_map[i][j] && cube_map[i][0] == '\n')
// 		i++;
// 	while (cube_map[i][j] && cube_map[i][j] == '1')
// 		j++;
// 	while (cube_map[i][j] && cube_map[i][j] == ' ')
// 		j++;
// 	if (cube_map[i][j] != '\n' && cube_map[i][j] != NULL)
// 		return (1);
// 	i++;
// 	j = 0;
// 	while (cube_map[i])
// 	{
// 		if (cube_map[i][j] != '1')
// 			return (1);
// 		while (cube_map[i][j] && (cube_map[i][j] != ' ' && cube_map[i][j] != '\n'))
// 			j++;
// 		if (cube_map[i][j - 1] != 1)
// 			return (1);
// 		j = 0;
// 		i++;
// 	}
// }

int	check_inside(char **cube_map, t_cube *cube)
{
	int	i;
	int	j;

	j = 0;
	i = cube->start;
	while (cube_map[i][j] && cube_map[i][j] == '1')
		j++;
	while (cube_map[i][j] && (cube_map[i][j] == ' ' || (cube_map[i][j] < 14 && cube_map[i][j] > 8)))
		j++;
	if (cube_map[i][j] != '\n' && cube_map[i][j] != '\0')
		return (1);
	i++;
	j = 0;
	while (i < (cube->end - 1))
	{
		if (cube_map[i][j] != '1')
			return (1);
		while (cube_map[i][j] == '1' || cube_map[i][j] == '0' || cube_map[i][j] == 'N' || cube_map[i][j] == 'W' || cube_map[i][j] == 'E' || cube_map[i][j] == 'S')
			j++;
		// while (cube_map[i][j] && (cube_map[i][j] != ' ' && cube_map[i][j] != '\n'))
		// 	j++;
		if (cube_map[i][j - 1] != '1') //verifier que le dernier est bien un 1
			return (1);
		j = 0;
		i++;
	}
	while (cube_map[i][j] && cube_map[i][j] == '1')
		j++;
	while (cube_map[i][j] && (cube_map[i][j] == ' ' || (cube_map[i][j] < 14 && cube_map[i][j] > 8)))
		j++;
	if (cube_map[i][j] != '\n' && cube_map[i][j] != '\0')
		return (1);
	return (0);
}

void len_map_2(char **cube_map, t_cube *cube)
{
	int	i;
	int	j;

	i = 0;
	while (cube_map[i][0] && cube_map[i][0] == '\n')
		i++;
	cube->start = i;
	j = i;
	while (cube_map[i][0] && cube_map[i][0] != '\n')
	{
		j++;
		i++;
	}
	cube->end = j;
}

int parsing_map(int fd, char **cube_map, int len, t_cube *cube)
{
	if (fill_map(fd, cube_map, len) == 1)
		return (printf("Error\n"), 1);
	skip_space(cube_map);
	if (no_space(cube_map) == 1)
		return (printf("Error\n"), 1);
	len_map_2(cube_map, cube);
	printf("debut :%d\n fin : %d\n", cube->start, cube->end);
	if (check_inside(cube_map, cube) == 1)
		return (printf("Error\n"), 1);
	//check que la forme est correct
	print_tab(cube_map);
	return (0);
}

int	len_map(int fd)
{
	char	**cube_map;
	int		i;

	i = 0;
	cube_map = malloc (sizeof(char *) * 1);
	cube_map[0] = get_next_line(fd);
	while (cube_map[0])
	{
		i++;
		free(cube_map[0]);
		cube_map[0] = get_next_line(fd);
		if (!cube_map[0])
			break ;
	}
	free(cube_map[0]);
	free(cube_map);
	printf("taille map : %d\n", i);
	return (i);
}

int	map_init(int fd, char *argv, t_cube *cube)
{
	cube->len = len_map(fd);
	if (cube->len == 0)//pas de map
		return (1);
	close(fd);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (1);
	free_tab(cube->info);
	parsing_cube(fd, cube);
	cube->map = malloc(sizeof(char *) * (cube->len + 1));
	if (parsing_map(fd, cube->map, cube->len, cube) == 1)
		return (1);
	//print_tab(cube->map);
	//free_tab(cube->map);
	return (0);
}
