#include "minishell.h"

void check_player_start(t_game *game, t_player p)
{
	if (p.x == 0 || p.y == 0)
	{
		printf("ERROR : Le joueur est sur un bord %s\n", game->map[p.y]);
		free_game_exit(game, 1);
	}
	if (game->map[p.y + 1] && game->map[p.y + 1][p.x])
		if (game->map[p.y - 1] && game->map[p.y - 1][p.x])
			if (game->map[p.y] && game->map[p.y ][p.x + 1])
				if (game->map[p.y] && game->map[p.y ][p.x - 1])
					return ;

	printf("ERROR : Le joueur est sur un bord %s\n", game->map[p.y]);
	free_game_exit(game, 1);
}       

void instance_player(t_game *game, int x, int y)
{
	game->player.x = x;
	game->player.y = y;
	game->player.dir = game->map[y][x];
	set_dir_start(game);
}