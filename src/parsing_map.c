/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:46:28 by sbelabba          #+#    #+#             */
/*   Updated: 2023/05/25 14:03:51 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	map_p.max_widht = start_width_map(game, map_p, 0, 0);
	if (map_p.max_widht <= 0)
	{
		printf("ERROR : map pas assez longue \n");
		free_game_exit(game, 1);
	}
	game->map_p = map_p;
	create_map(game, map_p, 0, 0);
	check_map(game);
}

void	bad_char(t_game *game, int i)
{
	int	j;

	while (game->tab && game->tab[i])
	{	
		j = 0;
		while (game->tab && game->tab[i] && game->tab[i][j]
			&& game->tab[i][j] == ' ')
		{
			j++;
		}
		if (!ft_compstr(game->tab[i] + j, "NO ")
			&& !ft_compstr(game->tab[i] + j, "SO ")
			&& !ft_compstr(game->tab[i] + j, "WE ")
			&& !ft_compstr(game->tab[i] + j, "EA ")
			&& !ft_compstr(game->tab[i] + j, "F ")
			&& !ft_compstr(game->tab[i] + j, "C ")
			&& !ft_compstr(game->tab[i] + j, "1")
			&& (game->tab[i][j]) != '\r' && (game->tab[i][j]) != '\n')
		{
			printf("ERROR : L%d %s\n", i + 1, game->tab[i] + j);
			free_game_exit(game, 1);
		}
		i++;
	}
}

void	check_char_map_2(t_game *game, int *player, int *i, int *j)
{
	while (game->map[(*i)] && game->map[(*i)][(*j)])
	{
		if (game->map[(*i)][(*j)]
			&& !check_sep(game->map[(*i)][(*j)], " 10NSWE"))
		{
			printf("ERROR : Map L%d = %s // *%c*\n", (*i), game->map[(*i)],
				game->map[(*i)][(*j)]);
			free_game_exit(game, 1);
		}
		if (game->map[(*i)][(*j)] && check_sep(game->map[(*i)][(*j)], "NSWE"))
		{
			instance_player(game, (*i), (*j));
			(*player)++;
		}
		(*j)++;
	}
}

void	check_char_map(t_game *game)
{
	int	i;
	int	j;
	int	player;

	i = 0;
	player = 0;
	while (game->map && game->map[i])
	{
		j = 0;
		check_char_map_2(game, &player, &i, &j);
		i++;
	}
	if (player != 1)
	{
		printf("ERRROR : multiple ou aucun position de joueur\n");
		free_game_exit(game, 1);
	}
	check_player_start(game, game->player);
}
