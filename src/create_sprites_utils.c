/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sprites_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:58:22 by sbelabba          #+#    #+#             */
/*   Updated: 2023/05/29 18:09:44 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 rajouter game et tout free
*/

int	check_sprite(char *str, void *mlx, t_game *game)
{
	void	*img;
	int		img_width;
	int		img_height;

	img = NULL;
	if (str)
		img = mlx_xpm_file_to_image(mlx, str,
				&img_width, &img_height);
	if (!img)
	{
		free_game_exit(game, 1);
	}
	if (img)
		mlx_destroy_image(mlx, img);
	return (1);
}

int	check_all_sprite(t_game *game)
{
	void	*mlx;
	int		res;

	res = 0;
	mlx = mlx_init();
	if (!mlx)
		return (0);
	res += check_sprite(game->sprite.north, mlx, game);
	res += check_sprite(game->sprite.south, mlx, game);
	res += check_sprite(game->sprite.east, mlx, game);
	res += check_sprite(game->sprite.west, mlx, game);
	if (res != 4)
	{
		printf("ERROR :\nun sprite n'existe pas\n");
		mlx_destroy_display(mlx);
		free(mlx);
		free_game_exit(game, 1);
		return (0);
	}
	mlx_destroy_display(mlx);
	free(mlx);
	return (1);
}

int	size_path(char *line)
{
	int	i;

	i = 0;
	while (line && line[i] && line[i] != ' '
		&& line[i] != '\n' && line[i] != '\r')
		i++;
	return (i);
}

int	ft_compstr(char *line, char *cmp)
{
	int	i;

	i = 0;
	if (line && line[0] == '\0')
		return (1);
	while (cmp && cmp[i])
	{
		if (line && line[i] && line[i] != cmp[i])
			return (0);
		i++;
	}
	return (1);
}

int	check_dir(char *line, char *dir)
{
	int	i;

	i = 0;
	while (line && line[i])
	{
		while (line && line[i] && line[i] == ' ')
			i++;
		if (line && line[i] && line[i] != '\r'
			&& line[i] != '\n' && ft_compstr(line + i, dir))
			return (1);
		break ;
	}
	return (0);
}
