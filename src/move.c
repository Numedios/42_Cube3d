/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 17:56:09 by sbelabba          #+#    #+#             */
/*   Updated: 2023/05/25 14:06:36 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

int	move_control(t_game *game)
{
	double	oldirx;
	double	oldplanex;
	int		keycode;

	keycode = game->key;
	oldplanex = game->player.planex;
	oldirx = game->player.dirx;
	if (keycode == 119 || keycode == 122)
		move_up(game);
	if (keycode == 97)
		camera_right(game, oldirx, oldplanex);
	if (keycode == 100 || keycode == 113)
		camera_left(game, oldirx, oldplanex);
	if (keycode == 115)
		move_down(game);
	if (keycode == 65307)
		mlx_loop_end(game->mlx);
	window_image_loop(game);
	return (0);
}
