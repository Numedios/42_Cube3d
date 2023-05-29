/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 17:56:09 by sbelabba          #+#    #+#             */
/*   Updated: 2023/05/29 17:57:19 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	camera_left(t_game *game, double oldirx, double oldPlanex)
{
	game->player.dirx = game->player.dirx * cos((0.02))
		- game->player.diry * sin((0.02));
	game->player.diry = oldirx * sin(0.02) + game->player.diry * cos((0.02));
	game->player.planex = game->player.planex * cos(0.02)
		- game->player.planey * sin(0.02);
	game->player.planey = oldPlanex * sin(0.02)
		+ game->player.planey * cos(0.02);
}

void	camera_right(t_game *game, double oldirx, double oldPlanex)
{
	game->player.dirx = game->player.dirx * cos(-(0.02))
		- game->player.diry * sin(-(0.02));
	game->player.diry = oldirx * sin(-(0.02))
		+ game->player.diry * cos(-(0.02));
	game->player.planex = game->player.planex * cos(-0.02)
		- game->player.planey * sin(-0.02);
	game->player.planey = oldPlanex * sin(-0.02)
		+ game->player.planey * cos(-0.02);
}

void	move_right(t_game *game)
{
	if (check_hitbox_right(game))
	{
		game->x = game->x + (game->player.planex * 0.05);
		game->y = game->y + (game->player.planey * 0.05);
	}
}

void	move_left(t_game *game)
{
	if (check_hitbox_left(game))
	{
		game->x = game->x - (game->player.planex * 0.05);
		game->y = game->y - (game->player.planey * 0.05);
	}
}

int	move_control(t_game *game)
{
	double	oldirx;
	double	oldplanex;
	int		keycode;

	keycode = game->key;
	oldplanex = game->player.planex;
	oldirx = game->player.dirx;
	if (keycode == 65361)
		camera_right(game, oldirx, oldplanex);
	if (keycode == 65363)
		camera_left(game, oldirx, oldplanex);
	if (keycode == 119 || keycode == 122)
		move_up(game);
	if (keycode == 97)
		move_left(game);
	if (keycode == 100 || keycode == 113)
		move_right(game);
	if (keycode == 115)
		move_down(game);
	if (keycode == 65307)
		mlx_loop_end(game->mlx);
	window_image_loop(game);
	return (0);
}
