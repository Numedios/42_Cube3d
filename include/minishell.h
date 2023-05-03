
#ifndef MINISHELL_H
# define MINISHELL_H

# include <math.h>//
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
# include "../mlx_linux/mlx.h"

#ifndef MY_HEADER_H//
#define MY_HEADER_H//

#define w_width 1400//
#define w_height 1400//
#define cell_size 32//

#endif /* MY_HEADER_H *///

typedef struct map_p
{
	int	start;
	int	height;
	int max_widht;

}			t_map_p;

typedef struct sprite
{
	char    *north;
	char    *sud;
	char 	*east;
	char	*west;
	char		*bot;
	char		*top;
}			t_sprite;

typedef struct player
{
	int	x;
	int	y;
	char dir;

}			t_player;

typedef struct jett//
{
	float	x;
	float	y;
	float	width;
	float	height;
	// float	radius;
	int		turnDirection;
	int		walkDirection;
	float	rotationAngle;
	float	moveSpeed;
	float	rotationSpeed;

}			t_jett;

typedef struct s_game
{
	char **tab;
	char **map;
	int cols;//
	int	rows;//
	t_sprite	sprite;
	t_player	player;
}		t_game;




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

void	create_map(t_game *game, t_map_p map_p);

/* create_map-utils.c */

void		set_map_p(t_map_p *map);
int			start_line_map(t_game *game);
int			start_height_map(t_game *game, t_map_p	map_p);
void		check_map_block(t_game *game, t_map_p	map_p);
int			start_width_map(t_game *game, t_map_p map_p);

/* parsing_map_utils.c*/

void		check_char_map(t_game *game);
void		check_wall_line(t_game *game);
void		check_adjacent(int row, int col, t_game *game);
void		check_wall_map(t_game *game);

/* create_player */

void instance_player(t_game *game, int x, int y);
void check_player_start(t_game *game, t_player p);

/* libft.c */

int			check_sep(char c, char *sep);
int			ft_strlen(char *str);

int			main(int argc, char **argv);

/*	2d.c	*/
void    debut(t_game *game);

#endif