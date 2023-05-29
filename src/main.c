/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelabba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:34:00 by sbelabba          #+#    #+#             */
/*   Updated: 2023/05/24 18:34:01 by sbelabba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_pic	*new_pic(t_game *img, int width, int height, int x)
{
	t_pic	*new;
	int		bpp;
	int		endian;

	bpp = 32;
	endian = 1;
	new = malloc(sizeof(t_pic));
	new->width = width;
	new->height = height;
	if (x == 1)
		new->img = mlx_xpm_file_to_image(img->mlx, img->sprite.north, \
		&new->width, &new->height);
	else if (x == 2)
		new->img = mlx_xpm_file_to_image(img->mlx, img->sprite.east, \
		&new->width, &new->height);
	else if (x == 3)
		new->img = mlx_xpm_file_to_image(img->mlx, img->sprite.west, \
		&new->width, &new->height);
	else if (x == 4)
		new->img = mlx_xpm_file_to_image(img->mlx, img->sprite.sud, \
		&new->width, &new->height);
	else
		new->img = mlx_new_image(img->mlx, width, height);
	new->buf = (int *)mlx_get_data_addr(new->img, &bpp, &x, &endian);
	return (new);
}

int	put_texture(t_game *img, float start, int line, t_pic *texture)
{
	int		color;
	double	x_text;
	double	x_wall;
	double	y_text;

	if (img->raydirx > 0 && !img->side)
		texture = img->east;
	if (img->raydirx < 0 && !img->side)
		texture = img->west;
	if (img->raydiry < 0 && img->side)
		texture = img->north;
	if (img->side == 0)
		x_wall = img->y + img->wall * img->raydiry;
	else
		x_wall = img->x + img->wall * img->raydirx;
	x_wall -= floor((x_wall));
	x_text = (int)(x_wall * (double)(64));
	if (img->side == 0 && img->raydirx > 0)
		x_text = 64 - x_text - 1;
	if (img->side == 1 && img->raydiry < 0)
		x_text = 64 - x_text - 1;
	color = start * 256 - img->screen.height * 128 + line * 128;
	y_text = ((color * 64) / line) / 256;
	color = texture->buf[(int)(y_text * 64 + x_text)];
	return (color);
}

void	get_on_the_floor(t_game *img)
{
	int	i;

	i = 0;
	while (i < (img->screen.length * img->screen.height) / 2)
	{
		img->pic->buf[i] = img->model.top[0] << 16;
		img->pic->buf[i] += img->model.top[1] << 8;
		img->pic->buf[i] += img->model.top[2];
		i++;
	}
	while (i < img->screen.length * img->screen.height)
	{
		img->pic->buf[i] = img->model.bot[0] << 16;
		img->pic->buf[i] += img->model.bot[1] << 8;
		img->pic->buf[i] += img->model.bot[2];
		i++;
	}
}

int	free_game_exite(t_game *game)
{
	if (game->tab)
		free_tab(game->tab);
	game->tab = NULL;
	if (game->map)
		free_tab(game->map);
	game->map = NULL;
	free_sprite_char(&game->sprite);
	free_pic(game);
	if (game->win)
	{
		mlx_destroy_window(game->mlx, game->win);
		game->win = NULL;
	}
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
	exit(1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	argc--;
	argv++;
	set_game(&game);
	parsing_arg(argc, argv);
	parsing(argv[0], &game);
	start_game(&game);
	free_game_exit(&game, 1);
}
