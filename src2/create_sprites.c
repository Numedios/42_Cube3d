#include "minishell.h"

char	*cut_split_sprite(char *line, t_game *game)
{
	int 	i;
	int		size;
	char	*res;

	i = 0;
	res = NULL;
	while(line && *line &&  *line == ' ')
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
	return(res);
}


char	*split_sprite(char *line, char *dir, t_game *game)
{
	int i;
	char *res;

	i = 0;
	res = NULL;
	while (line[i])
	{
		while (line && line[i] && line[i] == ' ')
			i++;
		if (ft_compstr(line + i, dir))
			res = cut_split_sprite(line + (i +2), game);
		i = i +2;
		while (line && line[i] && line[i] == ' ')
			i++;
		while (line && line[i] && line[i] != ' ' && line[i] != '\r' && line[i] != '\n')
			i++;
		while (line && line[i] && line[i] == ' ')
			i++;
		if (line && line[i] && line[i] != ' ' && line[i] != '\r' && line[i] != '\n')
		{
			printf("ERROR : plusieur chemin pour %s\n", dir);
			if (res)
				free(res);
			free_game_exit(game, 1);
		}
		break;	
	}
	return (res);
}

int set_sprite_value(char *tab, char **sprite, char *dir, t_game *game)
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
			printf("%s\n",tab);
            printf("Error: sprite %s already exists.\n", dir);
			free_game_exit(game, 1);
        }
    }
    return (0);
}


void check_color_sprite(t_game *game, char *num, int *set)
{
    char **pos;
    int i;

    i = 0;
    if (num)
        pos = ft_split(num, ',');
    if (!pos || ft_strlen_tab(pos) != 3)
    {
        if (pos)
            free_tab(pos);
		printf("Error : \"%s\" plus de 3 couleur (R,G,B)\n", num);
        free_game_exit(game, 1);
    }
    while (pos && pos[i])
    {
        set[i] = ft_atoi(pos[i]);
        if (set[i] && (set[i] < 0  || set[i] > 255))
        {
            printf("Error : couleur %d pqs compris entre 0 et 255", set[i]);
            if (pos)
                free_tab(pos);
            free_game_exit(game, 1);
        }
        i++;
    }
    if (pos)
        free_tab(pos);
}


void check_colors(t_game *game)
{
	check_color_sprite(game, game->sprite.bot, game->model.bot);
	check_color_sprite(game, game->sprite.top, game->model.top);
}

void	create_sprites(t_game *game)
{
	int			i;

	i = 0;
	while (game->tab && game->tab[i])
	{
		set_sprite_value(game->tab[i], &game->sprite.north, "NO", game);
		set_sprite_value(game->tab[i], &game->sprite.sud, "SO", game);
		set_sprite_value(game->tab[i], &game->sprite.east, "EA", game);
		set_sprite_value(game->tab[i], &game->sprite.west, "WE", game);
		set_sprite_value(game->tab[i], &game->sprite.bot, "F", game);
		set_sprite_value(game->tab[i], &game->sprite.top, "C", game);
		i++;
	}
	check_all_sprite(game);
	check_colors(game);
}