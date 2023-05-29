/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:34:38 by zhamdouc          #+#    #+#             */
/*   Updated: 2023/05/29 16:18:45 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_isdigit(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str && str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

void	check_virgule(t_game *game, char *num)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (num && num[i])
	{
		if (num && num[i] && num[i] == ',')
			c++;
		i++;
	}
	if (c != 2)
	{
		printf("Error : \"%s\" %d virgule au lieu de 2 \n", num, c);
		free_game_exit(game, 1);
	}
}

int	comp_char(char c, const char *str, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (c == str[i])
			return (0);
		i++;
	}
	return (1);
}

void	check_adjacent_2(int row, int col, t_game *game)
{
	if (game->map[row] && game->map[row][col + 1]
		&& comp_char(game->map[row][col + 1], " 1\r", 3))
	{
		printf("ERROR : col + 1 map non fermer \n %s // *%c*\n", game->map[row],
			game->map[row][col + 1]);
		free_game_exit(game, 1);
	}
	if (col > 0 && game->map[row] && game->map[row][col - 1]
		&& comp_char(game->map[row][col - 1], " 1\r", 3))
	{
		printf("ERROR : col -1 map non fermer \n %s // *%c*\n", game->map[row],
			game->map[row][col - 1]);
		free_game_exit(game, 1);
	}
}

void	check_adjacent(int row, int col, t_game *game)
{
	if (game->map[row + 1] && game->map[row + 1][col]
		&& comp_char(game->map[row + 1][col], " 1\r", 3))
	{
		printf("ERROR : row + 1 map non fermer \n %s // *%c*\n", game->map[row],
			game->map[row + 1][col]);
		free_game_exit(game, 1);
	}
	if (row > 0 && game->map[row - 1] && game->map[row - 1][col]
		&& comp_char(game->map[row - 1][col], " 1\r", 3))
	{
		printf("ERROR : row - 1 map non fermer \n %s // *%c*\n", game->map[row],
			game->map[row - 1][col]);
		free_game_exit(game, 1);
	}
	check_adjacent_2(row, col, game);
}
