
#include "minishell.h"

void	free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab && tab[i])
	{
		free(tab[i]);
		i++;
	}
	if (tab)
		free(tab);
	tab = NULL;
}

void    free_sprite_char(t_sprite *sprite)
{
	if (sprite->north)
		free(sprite->north);
	sprite->north = NULL;
	if (sprite->sud)
		free(sprite->sud);
	sprite->sud = NULL;
	if (sprite->east)
		free(sprite->east);
	sprite->east = NULL; 
	if (sprite->west)
		free(sprite->west);
	sprite->west = NULL; 
	if (sprite->bot)
		free(sprite->bot);
	sprite->bot = NULL; 
	if (sprite->top)
		free(sprite->top);
	sprite->top = NULL; 
}

void    free_model(t_model *model, void *mlx)
{
	if (model->north)
		mlx_destroy_image(mlx, model->north);
	model->north = NULL;
	if (model->sud)
		mlx_destroy_image(mlx, model->sud);
	model->sud = NULL;
	if (model->east)
		mlx_destroy_image(mlx, model->east);
	model->east = NULL; 
	if (model->west)
		mlx_destroy_image(mlx, model->west);
	model->west = NULL; 
}

void free_game_exit(t_game *game, int exit_code)
{
	if (game->tab)
		free_tab(game->tab);
	game->tab = NULL;
	
	if (game->map)
		free_tab(game->map);
	game->map = NULL;
	free_sprite_char(&game->sprite);
	free_model(&game->model, game->mlx);
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
	
	exit(exit_code);
}