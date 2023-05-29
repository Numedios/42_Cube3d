/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:46:36 by sbelabba          #+#    #+#             */
/*   Updated: 2023/05/29 17:53:36 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_wall_line(t_game *game, int j, int last_line)
{
	while (game->map[last_line])
		last_line++;
	last_line--;
	if (!game->map)
	{
		printf("ERROR :\npas de map\n");
		free_game_exit(game, 1);
	}
	while (game->map[0] && game-> map[0][j])
	{
		if (game->map[0][j] != ' ' && game->map[last_line]
			&& game->map[0][j] != '1')
		{
			printf("ERROR :\nmap premiere ligne pas composer uniquement de 1\n");
			free_game_exit(game, 1);
		}
		if (game->map[last_line][j] != ' ' && game->map[last_line][j] != '1')
		{
			printf("ERROR :\nmap derniere ligne pas composer uniquement de 1\n");
			free_game_exit(game, 1);
		}
		j++;
	}
}

void	check_adjacent_4(int row, int col, t_game *game)
{
	if (game->map[row] && !game->map[row][col + 1]
		&& comp_char(game->map[row][col + 1], "01EWSN", 6))
	{
		printf("ERROR :\ncol + 1 map non fermer \n %s // *%c*\n", game->map[row],
			game->map[row][col + 1]);
		free_game_exit(game, 1);
	}
	if (col > 0 && game->map[row] && !game->map[row][col - 1]
		&& comp_char(game->map[row][col - 1], "01EWSN", 6))
	{
		printf("ERROR :\ncol -1 map non fermer \n %s // *%c*\n", game->map[row],
			game->map[row][col - 1]);
		free_game_exit(game, 1);
	}
}

void	check_adjacent_3(int row, int col, t_game *game)
{
	if (game->map[row + 1] && !game->map[row + 1][col]
		&& comp_char(game->map[row + 1][col], "01EWSN", 6))
	{
		printf("ERROR :\nrow + 1 map non fermer \n %s // *%c*\n", game->map[row],
			game->map[row + 1][col]);
		free_game_exit(game, 1);
	}
	if (row > 0 && game->map[row - 1] && !game->map[row - 1][col]
		&& comp_char(game->map[row - 1][col], "01EWSN", 6))
	{
		printf("ERROR :\nrow - 1 map non fermer \n %s // *%c*\n", game->map[row],
			game->map[row - 1][col]);
		free_game_exit(game, 1);
	}
	check_adjacent_4(row, col, game);
}

void	check_wall_map(t_game *game)
{
	int	i;
	int	j;

	check_wall_line(game, 0, 0);
	i = 0;
	while (game->map && game->map[i])
	{
		j = 0;
		while (game->map && game->map[i] && game->map[i][j])
		{
			if (game->map[i][j] == ' ')
				check_adjacent(i, j, game);
			if (game->map[i][j] == '0')
				check_adjacent_3(i, j, game);
			j++;
		}
		if (game->map[i][(game->map_p.max_widht - 1)] == '0')
		{
			printf("ERROR :\n%s\nligne non fermer a la fin\n", game->map[i]);
			free_game_exit(game, 1);
		}
		i++;
	}
}
