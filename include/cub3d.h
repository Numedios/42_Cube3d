/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:49:17 by zhamdouc          #+#    #+#             */
/*   Updated: 2023/05/26 15:49:17 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <string.h>
# include <fcntl.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <limits.h>
# include <math.h>
# include "../mlx_linux/mlx.h"

typedef struct map_p //sert uniquement au parsing
{
	int	start;
	int	height;
	int	max_widht;
}			t_map_p;

typedef struct sprite //sert uniquement au parsing
{
	char	*north;
	char	*sud;
	char	*east;
	char	*west;
	char	*bot;
	char	*top;
}			t_sprite;

typedef struct s_pic
{
	int		width;
	int		height;
	void	*mlx;
	void	*win;
	void	*img;
	int		*buf;
}	t_pic;

typedef struct model
{
	int		bot[3];
	int		top[3];
}			t_model;

typedef struct player
{
	int		x;
	int		y;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	double	camerax;
	int		hitbox;
	int		speed;
	char	dir;

}			t_player;

typedef struct s_window
{
	int		height;
	int		length;
}		t_window;

typedef struct s_game
{
	char		**tab;
	char		**map;
	void		*mlx;
	void		*win;
	int			key;
	double		x;
	double		y;
	int			*buf;
	double		wall;
	double		camera_x;
	int			side;
	int			mapx;
	int			mapy;
	int			hit;
	int			stepx;
	int			stepy;
	double		deltadisty;
	double		deltadistx;
	double		raydirx;
	double		raydiry;
	double		camerax;
	double		perpwalldist;
	double		sidex;
	double		sidey;
	t_pic		*north;
	t_pic		*east;
	t_pic		*west;
	t_pic		*south;
	t_pic		*pic;
	t_window	screen;
	t_sprite	sprite;
	t_model		model;
	t_player	player;
	t_map_p		map_p;
}		t_game;

/* utils.c */
int			ft_isdigit(char *str);
void		check_virgule(t_game *game, char *num);
int			comp_char(char c, const char *str, int len);

/* get_next_line.c */

char		*get_next_line(int fd);

/* get_next_line.c */

int			check_end(char	*line);
char		*ft_strjoin_gnl(char *line, char *buf);
void		get_line(char *line, char *buf);

/* parsing_arg.c*/
void		ft_strstrend(char *str, char *search);
void		ft_try_open(char *file);
void		parsing_arg(int argc, char **argv);

/* free.c */

void		free_tab(char **tab);
void		free_sprite_char(t_sprite *sprite);
void		free_model(t_model *model, void *mlx);
void		free_game_exit(t_game *game, int exit_code);
void		free_pic(t_game *game);

/* supp.c */

void		print_tab(char **tab);

/* create_tab.c */

int			count_char(char *str);
int			open_fd(char *file);
int			count_ligne(char *str);
char		**create_tab(char *file);

/* set_struc.c */

void		set_sprite(t_sprite *sprite);
void		set_game(t_game *game);

/* create_sprites.c */

char		*cut_split_sprite(char *line, t_game *game);
char		*split_sprite(char *line, char *dir, t_game *game);
int			set_sprite_value(char *tab, char **sprite, char *dir, t_game *game);
void		create_sprites(t_game *game);

/* create_sprites_utils.c */

int			check_sprite(char *str, void *mlx);
int			check_all_sprite(t_game *game);
int			size_path(char *line);
int			ft_compstr(char *line, char *cmp);
int			check_dir(char *line, char *dir);

/* create_map.c */

void		create_map(t_game *game, t_map_p map_p, int k, int j);

/* create_map-utils.c */

void		set_map_p(t_map_p *map);
int			start_line_map(t_game *game);
int			start_height_map(t_game *game, t_map_p	map_p);
void		check_map_block(t_game *game, t_map_p	map_p);
int			start_width_map(t_game *game, t_map_p map_p, \
int max, int j);

/* parsing_map.c */

void		check_map(t_game *game);
void		parsing_map(t_game *game);
void		bad_char(t_game *game, int i);

/* parsing_map_utils.c*/

void		check_char_map(t_game *game);
void		check_wall_line(t_game *game, int j, int last_line);
void		check_adjacent(int row, int col, t_game *game);
void		check_wall_map(t_game *game);

/* parsing.c */

void		parsing(char *file, t_game *game);

/* create_player */

void		instance_player(t_game *game, int x, int y);
void		check_player_start(t_game *game, t_player p);

/* split.c */

char		**ft_split(char const *s, char c);

/* move */
int			check_hitbox_down(t_game *game);
int			check_hitbox_up(t_game *game);
void		camera_left(t_game *game, double oldirx, double oldPlanex);
void		camera_right(t_game *game, double oldirx, double oldPlanex);
void		move_up(t_game *game);
void		move_down(t_game *game);
int			move_control(t_game *game);

/* libft.c */

int			check_sep(char c, char *sep);
int			ft_strlen(char *str);
int			ft_strlen_tab(char **tab);
int			ft_atoi(const char *nptr);

/* set_mlx.c */

void		*create_sprite(char *str, t_game *game);
void		init_mlx(t_game *game);

/* math.c */

void		set_math(t_game *game, int i);
int			check_hit(t_game *game);
void		check_side(t_game *game);
void		put_pic(t_game *game, int i);
void		window_image_loop(t_game *game);

/* start_game.c */

int			press(int keycode, t_game *game);
int			release(int keycode, t_game *game);
void		start_game(t_game *game);

t_pic		*new_pic(t_game *img, int width, int height, int x);
int			main(int argc, char **argv);
int			put_texture(t_game *img, float start, int line, t_pic *texture);
void		get_on_the_floor(t_game *img);
void		set_dir_start(t_game *game);
void		set_screen(t_game *game);
int			free_game_exite(t_game *game);
double		find_x(char **map);
double		find_y(char **map);
int			main(int argc, char **argv);

#endif