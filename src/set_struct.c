/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 19:38:46 by sbelabba          #+#    #+#             */
/*   Updated: 2023/05/29 16:18:45 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_sprite(t_sprite *sprite)
{
	sprite->north = NULL;
	sprite->sud = NULL;
	sprite->east = NULL;
	sprite->west = NULL;
	sprite->bot = NULL;
	sprite->top = NULL;
}

void	set_game(t_game *game)
{
	game->tab = NULL;
	game->map = NULL;
	game->mlx = NULL;
	game->win = NULL;
	game->north = NULL;
	game->south = NULL;
	game->west = NULL;
	game->east = NULL;
	game->pic = NULL;
	game->player.speed = 5;
	game->player.hitbox = 4;
	set_sprite(&game->sprite);
}
