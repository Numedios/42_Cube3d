
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

void free_game_exit(t_game *game, int exit_code)
{
	if (game->tab)
		free_tab(game->tab);
	game->tab = NULL;
	
	if (game->map)
		free_tab(game->map);
	game->map = NULL;
	free_sprite_char(&game->sprite);
	exit(exit_code);
}