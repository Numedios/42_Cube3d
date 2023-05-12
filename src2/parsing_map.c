#include "minishell.h"

void	check_map(t_game *game)
{
	check_char_map(game);
	check_wall_map(game);
}


void	parsing_map(t_game *game)
{
	t_map_p	map_p;


	set_map_p(&map_p);
	map_p.start = start_line_map(game);
	if (map_p.start < 0)
	{
		printf("ERROR : map introuvable\n");
		free_game_exit(game, 1);
	}
	check_map_block(game, map_p);
	map_p.height = start_height_map(game, map_p);
	if (map_p.height <= 0)
	{
		printf("ERROR : map pas assez haute\n");
		free_game_exit(game, 1);
	}
	map_p.max_widht = start_width_map(game, map_p);
	if (map_p.max_widht <= 0)
	{
		printf("ERROR : map pas assez longue \n");
		free_game_exit(game, 1);
	}
	game->map_p = map_p;
	create_map(game, map_p);
	check_map(game);
}




void bad_char(t_game *game)
{
	int i;
	int	j;

	i = 0;
	while (game->tab && game->tab[i])
	{	
		j = 0;
		while (game->tab && game->tab[i] && game->tab[i][j]  && game->tab[i][j] == ' ')
		{
			j++;
		}
		if (!ft_compstr(game->tab[i] + j, "NO ") && !ft_compstr(game->tab[i] + j, "SO ") && !ft_compstr(game->tab[i] + j, "WE ") && !ft_compstr(game->tab[i] + j, "EA ") && !ft_compstr(game->tab[i] + j, "F ") &&   !ft_compstr(game->tab[i] + j, "C ") && !ft_compstr(game->tab[i] + j, "1") && (game->tab[i][j]) != '\r' && (game->tab[i][j]) != '\n')
		{
			printf("ERROR : L%d %s\n", i + 1, game->tab[i] + j);
			free_game_exit(game, 1);
		}
		i++;
	}
}