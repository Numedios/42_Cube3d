#include "minishell.h"

void	set_map_p(t_map_p *map)
{
	map->height = -1;
	map->max_widht = -1;
	map->start = -1;
}

int	start_line_map(t_game *game)
{
	int	i;
	int j;

	i = 0;
	
	while (game->tab && game->tab[i])
	{
		j = 0;
		while (game->tab && game->tab[i] && game->tab[i][j]  && game->tab[i][j] == ' ')
			j++;
		if (game->tab && game->tab[i] && game->tab[i][j]  && game->tab[i][j] == '1')
			return (i);
		i++;
	}
	return (-1);
}

int	start_height_map(t_game *game, t_map_p	map_p)
{
	int	i;
	int j;

	i = map_p.start;
	if (i == -1)
	{
		printf("Error : start_height");	
		free_game_exit(game, 1);
	}
	while (game->tab && game->tab[i])
	{
		j = 0;
		while (game->tab && game->tab[i] && game->tab[i][j]  && game->tab[i][j] == ' ')
			j++;
		if (game->tab && game->tab[i] && game->tab[i][j]  && game->tab[i][j] != '1')
			return (i - map_p.start);
		i++;
	}
	return (i - map_p.start);
}

void	check_map_block(t_game *game, t_map_p	map_p)
{
	int	i;
	int j;

	i = map_p.start;
	if (i == -1)
	{
		printf("Error : start_height");	
		free_game_exit(game, 1);
	}
	while (game->tab && game->tab[i])
	{
		j = 0;
		while (game->tab && game->tab[i] && game->tab[i][j]  && game->tab[i][j] == ' ')
			j++;
		if (game->tab && game->tab[i] && game->tab[i][j]  && game->tab[i][j] != '1')
			break ;
		i++;
	}
	while (game->tab && game->tab[i])
	{
		j = 0;
		while (game->tab && game->tab[i] && game->tab[i][j]  && game->tab[i][j] == ' ')
			j++;
		if (game->tab && game->tab[i] && game->tab[i][j]  && game->tab[i][j] == '1')
		{
			printf("ERROR : map en plusieurs block\n");
			free_game_exit(game, 1);
		}
		i++;
	}

}
int	start_width_map(t_game *game, t_map_p map_p)
{
	int	i;
	int j;
	int c;
	int max;

	i = map_p.start;
	max = 0;
	if (i == -1)
	{
		printf("Error : start_width map"); // pas besoin maybe	
		free_game_exit(game, 1);
	}
	while (game->tab && game->tab[i])
	{
		j = 0;
		while (game->tab && game->tab[i] && game->tab[i][j])
		{
			if (game->tab[i][j] != ' ' && game->tab[i][j] != '\n' && game->tab[i][j] != '\r')
				c = j;
			j++;
		}
		if (c > max)
			max = c;
		i++;
	}
	return (max + 1);
}
