/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:56:23 by sbelabba          #+#    #+#             */
/*   Updated: 2023/05/29 16:18:45 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* check si la map est en 1 block */

void	space_skip(t_game *game, t_map_p map_p, int k, int *j)
{
	while ((*j) < (map_p.max_widht))
	{
		game->map[k][(*j)] = ' ';
		(*j)++;
	}
}

void	create_map(t_game *game, t_map_p map_p, int k, int j)
{
	int	i;

	i = map_p.start;
	game->map = malloc(sizeof(char *) * (map_p.height + 1));
	if (!game->map)
		free_game_exit(game, 1);
	while (i < map_p.start + map_p.height)
	{
		j = 0;
		game->map[k] = malloc(sizeof(char) * (map_p.max_widht + 1));
		if (!game->map[k])
			free_game_exit(game, 1);
		while (game->tab[i][j] && j < (map_p.max_widht)
			&& game->tab[i][j] != '\n' && game->tab[i][j] != '\r')
		{
			game->map[k][j] = game->tab[i][j];
			j++;
		}
		space_skip(game, map_p, k, &j);
		game->map[k][j] = '\0';
		i++;
		k++;
	}
	game->map[k] = 0;
}
