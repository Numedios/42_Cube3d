/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelabba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:57:10 by sbelabba          #+#    #+#             */
/*   Updated: 2023/05/24 18:57:11 by sbelabba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_player_start(t_game *game, t_player p)
{
	if (p.x == 0 || p.y == 0)
	{
		printf("ERROR : Le joueur est sur un bord %s\n", game->map[p.x]);
		free_game_exit(game, 1);
	}
	if (game->map[p.x + 1] && game->map[p.x + 1][p.y])
		if (game->map[p.x - 1] && game->map[p.x - 1][p.y])
			if (game->map[p.x] && game->map[p.x][p.y + 1])
				if (game->map[p.x] && game->map[p.x][p.y - 1])
					return ;
	printf("ERROR : Le joueur est sur un bord %s\n", game->map[p.x]);
	free_game_exit(game, 1);
}

void	instance_player(t_game *game, int i, int j)
{
	game->player.x = i;
	game->player.y = j;
	game->player.dir = game->map[i][j];
	set_dir_start(game);
}
