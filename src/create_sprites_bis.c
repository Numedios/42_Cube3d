/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sprites_bis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:45:43 by zhamdouc          #+#    #+#             */
/*   Updated: 2023/05/26 15:35:39 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*cut_split_sprite(char *line, t_game *game)
{
	int		i;
	int		size;
	char	*res;

	i = 0;
	res = NULL;
	while (line && *line && *line == ' ')
		line++;
	size = size_path(line);
	res = malloc(sizeof(char) * (size + 1));
	if (!res)
		free_game_exit(game, 1);
	while (i < size && line)
	{
		res[i] = line[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

void	split_sprite_2(char *line, t_game *game, int *i)
{
	(*i) = (*i) + 2;
	while (line && line[(*i)] && line[(*i)] == ' ')
		(*i)++;
	while (line && line[(*i)] && line[(*i)] != ' '
		&& line[(*i)] != '\r' && line[(*i)] != '\n')
		(*i)++;
	while (line && line[(*i)] && line[(*i)] == ' ')
		(*i)++;
}

char	*split_sprite(char *line, char *dir, t_game *game)
{
	int		i;
	char	*res;

	i = 0;
	res = NULL;
	while (line[i])
	{
		while (line && line[i] && line[i] == ' ')
			i++;
		if (ft_compstr(line + i, dir))
			res = cut_split_sprite(line + (i + 2), game);
		split_sprite_2(line, game, &i);
		if (line && line[i] && line[i] != ' '
			&& line[i] != '\r' && line[i] != '\n')
		{
			printf("ERROR : plusieur chemin pour %s\n", dir);
			if (res)
				free(res);
			free_game_exit(game, 1);
		}
		break ;
	}
	if (!res)
		free_game_exit(game, 1);
	return (res);
}

int	set_sprite_value(char *tab, char **sprite, char *dir, t_game *game)
{
	if (check_dir(tab, dir))
	{
		if (!(*sprite))
		{
			*sprite = split_sprite(tab, dir, game);
			return (0);
		}
		else
		{
			printf("Error: sprite %s already exists.\n", dir);
			free_game_exit(game, 1);
		}
	}
	return (0);
}
