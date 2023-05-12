#include "minishell.h"

int	check_sprite(char *str, void *mlx) // rajouter game et tout free
{
	void	*img;
	int		img_width;
	int		img_height;

	img = mlx_xpm_file_to_image(mlx, str,
			&img_width, &img_height);
	if (!img)
	{
		return (0);
	}
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
	res += check_sprite(game->sprite.north, mlx);
	res += check_sprite(game->sprite.sud, mlx);
	res += check_sprite(game->sprite.east, mlx);
	res += check_sprite(game->sprite.west, mlx);
	if (res != 4)
	{
		printf("error un sprite n'existe pas\n");
		mlx_destroy_display(mlx);
		free(mlx);
		return (0);
	}
	mlx_destroy_display(mlx);
	free(mlx);
	return (1);
}

int	size_path(char *line)
{
	int i;

	i = 0;	
	while(line && line[i] && line[i] != ' ' && line[i] != '\n' && line[i] != '\r')
		i++;
	return(i);
}

int	ft_compstr(char *line, char *cmp)
{
	int i;

	i = 0;
	while (cmp && cmp[i])
	{
		if (line && line[i] && line[i] != cmp[i])
			return(0);
		i++;
	}
	return (1);
}

int	check_dir(char *line, char *dir)
{
	int i;

	i = 0;
	while (line && line[i])
	{
		while (line && line[i] && line[i] == ' ')
			i++;
		if (line && line[i] && line[i] != '\r' && line[i] != '\n'&& ft_compstr(line + i, dir))
			return (1);
		break;	
	}
	return (0);
}