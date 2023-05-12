#include "minishell.h"

/* check si la map est en 1 block */

void	create_map(t_game *game, t_map_p map_p)
{
	int	i;
	int j;
	int	k;

	k = 0;
	i = map_p.start;
	game->map = malloc(sizeof(char * ) * (map_p.height + 1));
	if (!game->map)
		free_game_exit(game, 1);
	while (game->tab && game->tab[i] && game->tab[i][0] != '\r'  && game->tab[i][0] != '\n')
	{
		j = 0;
		game->map[k] = malloc(sizeof(char) * (map_p.max_widht + 1));
		if (!game->map[k])
			free_game_exit(game, 1);
		while (game->tab[i][j] && j < (map_p.max_widht) &&  game->tab[i][j] != '\n' && game->tab[i][j] != '\r')
		{
			game->map[k][j] = game->tab[i][j];
			j++;
		}
		while (j < (map_p.max_widht))
		{
			game->map[k][j] = ' ';
			j++;
		}
		game->map[k][j] = '\0';
		i++;
		k++;
	}
	game->map[k] = 0;

}