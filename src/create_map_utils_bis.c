/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_utils_bis.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:21:45 by zhamdouc          #+#    #+#             */
/*   Updated: 2023/05/29 18:03:37 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	start_height_map_two(t_game *game, int *i)
{
	int	j;

	while (game->tab && game->tab[(*i)])
	{
		j = 0;
		while (game->tab && game->tab[(*i)] && game->tab[(*i)][j]
			&& (game->tab[(*i)][j] == '\r' || game->tab[(*i)][j] == ' '))
			j++;
		if (game->tab && game->tab[(*i)] && game->tab[(*i)][j]
			&& (game->tab[(*i)][j] != '\r' && game->tab[(*i)][j] != ' '))
		{
			printf("Error :\n%s\nrouver apres la map\n", game->tab[(*i)]);
			free_game_exit(game, 1);
		}
	}
}

int	only_one_char(char *str, char c)
{
	if (str == NULL || *str == '\0')
		return (0);
	while (*str != '\0' && *str != '\r')
	{
		if (*str != c)
			return (0);
		str++;
	}
	return (1);
}

int	start_height_map(t_game *game, t_map_p	map_p)
{
	int	i;
	int	j;

	i = map_p.start;
	if (i == -1)
	{
		printf("Error :\nstart_height\n");
		free_game_exit(game, 1);
	}
	while (game->tab && game->tab[i])
	{
		j = 0;
		if (only_one_char(game->tab[i], ' ') == 1)
			return (i - map_p.start);
		while (game->tab && game->tab[i] && game->tab[i][j]
			&& game->tab[i][j] == ' ')
			j++;
		if (game->tab && game->tab[i] && game->tab[i][j]
			&& game->tab[i][j] != '1')
			return (i - map_p.start);
		i++;
	}
	start_height_map_two(game, &i);
	return (i - map_p.start);
}

void	check_map_block_two(t_game *game, int i, int j)
{
	while (game->tab && game->tab[i])
	{
		j = 0;
		while (game->tab && game->tab[i] && game->tab[i][j]
			&& game->tab[i][j] == ' ')
			j++;
		if (game->tab && game->tab[i] && game->tab[i][j]
			&& (game->tab[i][j] != ' ' && game->tab[i][j] != '\r'))
		{
			printf("ERROR :\n%s\nse situe sous la map\n", game->tab[i]);
			free_game_exit(game, 1);
		}
		i++;
	}
}

void	check_map_block(t_game *game, t_map_p	map_p)
{
	int	i;
	int	j;

	i = map_p.start;
	if (i == -1)
	{
		printf("Error :\ncheck map block\n");
		free_game_exit(game, 1);
	}
	while (game->tab && game->tab[i])
	{
		j = 0;
		while (game->tab && game->tab[i] && game->tab[i][j]
			&& game->tab[i][j] == ' ')
			j++;
		if (game->tab && game->tab[i] && game->tab[i][j]
			&& game->tab[i][j] != '1')
			break ;
		i++;
	}
	check_map_block_two(game, i, j);
}
