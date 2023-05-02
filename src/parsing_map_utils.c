#include "minishell.h"

void check_char_map(t_game *game)
{
	int i;
	int j;
	int	player;

	i = 0;
	player = 0;
	while (game->map && game->map[i])
	{
		j = 0;
		while (game->map[i] && game->map[i][j])
		{
			if (game->map[i][j] && !check_sep(game->map[i][j]," 10NSWE"))
			{
				printf("ERROR : Map L%d = %s // *%c*\n", i, game->map[i], game->map[i][j]);
				free_game_exit(game, 1);
			}
			if (game->map[i][j] && check_sep(game->map[i][j],"NSWE")) // si definir position joueur autant le faire ici
			{
				instance_player(game, i , j);
				player++;
			}
			j++;
		}
		i++;
	}
	if (player != 1)
	{
		printf("ERRROR : multiple ou aucun position de joueur\n");
		free_game_exit(game, 1);
	}
	check_player_start(game, game->player);
}

void check_wall_line(t_game *game)
{
	int j;
	int last_line;

	j = 0;
	last_line = 0;
		last_line++;
	last_line--;
	if (!game->map)
	{
		printf("ERROR : pas de map");
		free_game_exit(game, 1);
	}
	while (game->map[0] && game-> map[0][j])
	{
		if (game->map[0][j] != ' ' && game->map[last_line] && game->map[0][j] != '1')
		{
			printf("ERROR : map premiere ligne pas composer uniquement de 1\n");
			free_game_exit(game, 1);
		}
		if (game->map[last_line][j] != ' ' && game->map[last_line][j] != '1')
		{
			printf("ERROR : map derniere ligne pas composer uniquement de 1\n");
			free_game_exit(game, 1);
		}
		j++;
	}
}

void check_adjacent(int row, int col, t_game *game)
{
	if (game->map[row + 1] && game->map[row + 1][col] && game->map[row + 1][col] != '1' && game->map[row + 1][col] != ' ')
	{
		printf("ERROR : row + 1 map non fermer \n %s // *%c*\n", game->map[row], game->map[row + 1][col]);
		free_game_exit(game, 1);
	}
	if (row > 0 && game->map[row - 1] && game->map[row - 1][col] && game->map[row - 1][col] != '1' && game->map[row - 1][col] != ' ')
	{
		printf("ERROR : row - 1 map non fermer \n %s // *%c*\n", game->map[row], game->map[row - 1][col]);
		free_game_exit(game, 1);
	}
	if (game->map[row] && game->map[row][col + 1] && game->map[row][col + 1] != '1' && game->map[row][col + 1] != ' ')
	{
		printf("ERROR : col + 1 map non fermer \n %s // *%c*\n", game->map[row], game->map[row][col + 1]);
		free_game_exit(game, 1);
	}
	if (col > 0 && game->map[row] && game->map[row][col - 1] && game->map[row][col - 1] != '1' && game->map[row][col - 1] != ' ')
	{
		printf("ERROR : col -1 map non fermer \n %s // *%c*\n", game->map[row], game->map[row][col - 1]);
		free_game_exit(game, 1);
	}
}

void check_wall_map(t_game *game)
{
	int i;
	int j;

	check_wall_line(game);
	i = 0;
	while (game->map && game->map[i])
	{
		j = 0;
		while (game->map && game->map[i] && game->map[i][j])
		{
			if (game->map[i][j] == ' ')
				check_adjacent(i, j, game);
			j++;
		}
		i++;
	}
}
