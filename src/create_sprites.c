/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 19:00:58 by sbelabba          #+#    #+#             */
/*   Updated: 2023/05/29 18:09:44 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_color_sprite_two(t_game *game, int *set, int i, char **pos)
{
	while (pos && pos[i])
	{
		set[i] = ft_atoi(pos[i]);
		if (set[i] && (set[i] < 0 || set[i] > 255))
		{
			printf("Error :\ncouleur %d pqs compris entre 0 et 255\n", set[i]);
			if (pos)
				free_tab(pos);
			free_game_exit(game, 1);
		}
		i++;
	}
}

void	check_color_sprite_three(t_game *game, int i, char **pos)
{
	while (pos && pos[i])
	{
		if (ft_isdigit(pos[i]) == 0)
		{
			printf("Error :\ncouleur %s n'est pas un nombre\n", pos[i]);
			if (pos)
				free_tab(pos);
			free_game_exit(game, 1);
		}
		i++;
	}
}

void	check_color_sprite(t_game *game, char *num, int *set)
{
	char	**pos;

	check_comma(game, num);
	pos = ft_split(num, ',');
	if (!pos || ft_strlen_tab(pos) != 3)
	{
		if (pos)
			free_tab(pos);
		printf("Error :\n\"%s\" plus de 3 couleur (R,G,B)\n", num);
		free_game_exit(game, 1);
	}
	check_color_sprite_two(game, set, 0, pos);
	check_color_sprite_three(game, 0, pos);
	if (pos)
		free_tab(pos);
}

void	check_colors(t_game *game)
{
	check_color_sprite(game, game->sprite.bot, game->model.bot);
	check_color_sprite(game, game->sprite.top, game->model.top);
}

void	create_sprites(t_game *game)
{
	int			i;

	i = 0;
	while (game->tab && game->tab[i])
	{
		set_sprite_value(game->tab[i], &game->sprite.north, "NO", game);
		set_sprite_value(game->tab[i], &game->sprite.south, "SO", game);
		set_sprite_value(game->tab[i], &game->sprite.east, "EA", game);
		set_sprite_value(game->tab[i], &game->sprite.west, "WE", game);
		set_sprite_value(game->tab[i], &game->sprite.bot, "F", game);
		set_sprite_value(game->tab[i], &game->sprite.top, "C", game);
		i++;
	}
	check_all_sprite(game);
	check_colors(game);
}
