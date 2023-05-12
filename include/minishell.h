
#ifndef MINISHELL_H
# define MINISHELL_H

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

#ifndef MY_HEADER_H//
#define MY_HEADER_H//

#define w_width 500//
#define w_height 500//
#define cell_size 8//

#endif /* MY_HEADER_H *///

typedef struct map_p //sert uniquement au parsing
{
	int	start;
	int	height;
	int max_widht;

}			t_map_p;

typedef struct sprite //sert uniquement au parsing
{
	char    *north;
	char    *sud;
	char 	*east;
	char	*west;
	char		*bot;
	char		*top;
}			t_sprite;

typedef struct	model
{
	void    *north;
	void    *sud;
	void 	*east;
	void	*west;
	int		bot[3];
	int		top[3];
}			t_model;

typedef struct player
{
	int		x;
	int		y;
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	double	camerax;
	int		hitbox;
	int		speed;
	char	dir;

}			t_player;

typedef struct s_game
{
	char 		**tab;
	char 		**map;
	void		*mlx;
	void		*win;
	int cols;//
	int	rows;//
	t_sprite	sprite;
	t_model		model;
	t_player	player;
	t_map_p		map_p;
}		t_game;

typedef struct jett//
{
	float	x;
	float	y;
	float	old_x;
	float	old_y;
	float	width;
	float	height;
	float	FOV_angle;
	int	wall_width;
	int	nb_rays;
	float	ray_angle;
	// float	radius;
	int wall_hit_x;
	int wall_hit_y;
	int wall_distance;
	int		turnDirection;
	int		walkDirection;
	float	rotationAngle;
	float	moveSpeed;
	float	rotationSpeed;
	void    *mlx_ptr;
	void    *win_ptr;
	char **map;
	int cols;//
	int	rows;//

}			t_jett;

/*	2d.c	*/
void    *debut(t_game *game);
void    angleplus(t_jett *jett, float anglemove);
int wall_hit_horizontal(t_jett *jett, float angle);

/* get_next_line.c */

char	*get_next_line(int fd);

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
void		free_game_exit(t_game *game, int exit_code);

/* supp.c */

void    	print_tab(char **tab);

/* create_tab.c */

int			count_char(char *str);
int			open_fd(char *file);
int			count_ligne(char *str);
char		**create_tab(char *file);

/* set_struc.c */

void		set_sprite(t_sprite *sprite);
void		set_model(t_game *game);
void		set_game(t_game *game);

/* create_sprites.c */

char		*cut_split_sprite(char *line, t_game *game);
char		*split_sprite(char *line, char *dir, t_game *game);
int 		set_sprite_value(char *tab, char **sprite, char *dir, t_game *game);
void		create_sprites(t_game *game);

/* create_sprites_utils.c */

int			check_sprite(char *str, void *mlx);
int			check_all_sprite(t_game *game);
int			size_path(char *line);
int			ft_compstr(char *line, char *cmp);
int			check_dir(char *line, char *dir);


/* create_map.c */

void		create_map(t_game *game, t_map_p map_p);

/* create_map-utils.c */

void		set_map_p(t_map_p *map);
int			start_line_map(t_game *game);
int			start_height_map(t_game *game, t_map_p	map_p);
void		check_map_block(t_game *game, t_map_p	map_p);
int			start_width_map(t_game *game, t_map_p map_p);


/* parsing_map.c */

void		check_map(t_game *game);
void		parsing_map(t_game *game);
void		bad_char(t_game *game);

/* parsing_map_utils.c*/

void		check_char_map(t_game *game);
void		check_wall_line(t_game *game);
void		check_adjacent(int row, int col, t_game *game);
void		check_wall_map(t_game *game);

/* parsing.c */

void parsing(char *file, t_game *game);

/* create_player */

void 		instance_player(t_game *game, int x, int y);
void 		check_player_start(t_game *game, t_player p);

/* split.c */

char	**ft_split(char const *s, char c);

/* libft.c */

int			check_sep(char c, char *sep);
int			ft_strlen(char *str);
int			ft_strlen_tab(char **tab);
int			ft_atoi(const char *nptr);

/* set_mlx.c */

void		*create_sprite(char *str, t_game *game); // rajouter game et tout free
void		add_model(t_game *game);
void		init_mlx(t_game *game);



int			main(int argc, char **argv);
void set_dir_start(t_game *game);

#endif