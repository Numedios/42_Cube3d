/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:52:55 by sbelabba          #+#    #+#             */
/*   Updated: 2023/05/29 17:52:00 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_map_p(t_map_p *map)
{
	map->height = -1;
	map->max_widht = -1;
	map->start = -1;
}

int	start_line_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->tab && game->tab[i])
	{
		j = 0;
		while (game->tab && game->tab[i] && game->tab[i][j]
			&& game->tab[i][j] == ' ')
			j++;
		if (game->tab && game->tab[i] && game->tab[i][j]
			&& game->tab[i][j] == '1')
			return (i);
		i++;
	}
	return (-1);
}

int	start_width_map(t_game *game, t_map_p map_p, int max, int j)
{
	int	i;
	int	c;

	i = map_p.start;
	if (i == -1)
	{
		printf("Error :\nstart_width map\n");
		free_game_exit(game, 1);
	}
	while (game->tab && game->tab[i])
	{
		j = 0;
		while (game->tab && game->tab[i] && game->tab[i][j])
		{
			if (game->tab[i][j] != ' ' && game->tab[i][j] != '\n'
				&& game->tab[i][j] != '\r')
				c = j;
			j++;
		}
		if (c > max)
			max = c;
		i++;
	}
	return (max + 1);
}
