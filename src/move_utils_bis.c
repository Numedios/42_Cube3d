/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils_bis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:57:10 by zhamdouc          #+#    #+#             */
/*   Updated: 2023/05/29 17:57:31 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_hitbox_right(t_game *game)
{
	int		x;
	int		y;
	double	xx;
	double	yy;

	xx = game->x + (game->player.planex * 0.05);
	yy = game->y + (game->player.planey * 0.05);
	x = (int) xx;
	y = (int) yy;
	if (!game->map[y])
		return (0);
	if (!game->map[y][x])
		return (0);
	if (game->map[y][x] == ' ')
		return (0);
	if (game->map[y] && game->map[y][x] && game->map[y][x] == '1')
		return (0);
	return (1);
}

int	check_hitbox_left(t_game *game)
{
	int		x;
	int		y;
	double	xx;
	double	yy;

	xx = game->x - (game->player.planex * 0.05);
	yy = game->y - (game->player.planey * 0.05);
	x = (int)xx;
	y = (int)yy;
	if (!game->map[y])
		return (0);
	if (!game->map[y][x])
		return (0);
	if (game->map[y][x] == ' ')
		return (0);
	if (game->map[y] && game->map[y][x] && game->map[y][x] == '1')
		return (0);
	return (1);
}
