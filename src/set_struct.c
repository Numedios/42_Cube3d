#include "minishell.h"

void set_sprite(t_sprite *sprite)
{
	sprite->north = NULL;
	sprite->sud = NULL;
	sprite->east = NULL;
	sprite->west = NULL;
	sprite->bot = NULL;
	sprite->top = NULL;
}