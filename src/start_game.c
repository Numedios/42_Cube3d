/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:15:07 by sbelabba          #+#    #+#             */
/*   Updated: 2023/05/25 14:07:56 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	press(int keycode, t_game *game)
{
	game->key = 0;
	game->key = keycode;
	return (0);
}

int	release(int keycode, t_game *game)
{
	(void)keycode;
	game->key = 0;
	return (0);
}

void	start_game(t_game *game)
{
	game->key = 0;
	set_screen(game);
	game->x = find_x(game->map, game);
	game->y = find_y(game->map, game);
	game->north = new_pic(game, 0, 0, 1);
	game->east = new_pic(game, 0, 0, 2);
	game->west = new_pic(game, 0, 0, 3);
	game->south = new_pic(game, 0, 0, 4);
	free_sprite_char(&game->sprite);
	game->win = mlx_new_window(game->mlx, game->screen.length,
			game->screen.height, "Cube3D");
	window_image_loop(game);
	mlx_hook(game->win, 2, 1L << 0, &press, game);
	mlx_hook(game->win, 3, 1L << 1, &release, game);
	mlx_hook(game->win, 17, 0, free_game_exite, game);
	mlx_loop_hook(game->mlx, &move_control, game);
	mlx_loop(game->mlx);
}
