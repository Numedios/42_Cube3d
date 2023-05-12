#include "minishell.h"

void put_player(t_game *game)
{
	int i;
	int j;
	int box;

	box = game->player.hitbox;
	i = 0;
	j = 0;
	while(i < 8)
	{
		j = 0;
		while(j < 8)
		{
			mlx_pixel_put(game->mlx, game->win, (int)((game->player.posy - box)), (int)((game->player.posx - box)), 0x00FF0000);
			mlx_pixel_put(game->mlx, game->win, (int)((game->player.posy + box)), (int)((game->player.posx + box)), 0x00FF0000);
			mlx_pixel_put(game->mlx, game->win, (int)((game->player.posy - box)), (int)((game->player.posx + box)), 0x00FF0000);
			mlx_pixel_put(game->mlx, game->win, (int)((game->player.posy + box)), (int)((game->player.posx - box)), 0x00FF0000);
			j++;
		}
		i++;
	}
	mlx_pixel_put(game->mlx, game->win, (game->player.posy), game->player.posx, 0x000000FF);
}
void drawVerticalLine(int x, int drawStart, int drawEnd, int color, t_game *game)
{
    int y = drawStart;
    while (y <= drawEnd)
    {
        mlx_pixel_put(game->mlx, game->win, x, y, color);
        y++;
    }
}

void draw_line(int x1, int y1, int x2, int y2, t_game *game)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = x1 < x2 ? 1 : -1;
    int sy = y1 < y2 ? 1 : -1;
    int err = dx - dy;
    
    while (x1 != x2 || y1 != y2) {
        mlx_pixel_put(game->mlx, game->win, y1, x1,  0x000000FF);
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

void draw_ver_line(t_game *game, int x, int y_start, int y_end, int color)
{
    int y;

    for (y = y_start; y <= y_end; y++)
    {
        mlx_pixel_put(game->mlx, game->win, x, y, color);
    }
}


void put_visionn(t_game *game)
{
	int i;
	int box;
	int w;
	double cameraX;
	double rayDirX;
	double rayDirY;
	int mapX;
    int mapY;
	double sideDistX;
    double sideDistY;
	double deltaDistY;
	double deltaDistX;
	double perpWallDist;
	int stepX;
    int stepY;
	int hit;
	int side;
	int lineHeight;
	int drawStart;
	int drawEnd;

	box = game->player.hitbox;
	i = 0;
	w = 64 * game->map_p.max_widht;
	while(i < w)
	{
		cameraX = (2 * i) / (double) w - 1;
		rayDirX = game->player.dirx + game->player.planex * cameraX;
		rayDirY = game->player.diry + game->player.planey * cameraX;
		mapX = (int)game->player.posx ;
		mapY = (int)game->player.posy;

		if (rayDirX == 0)
		{
    		deltaDistX = 1e30;
		}
		else
		{
    		deltaDistX = fabs(1 / rayDirX);
		}
		if (rayDirY == 0)
		{
    		deltaDistY = 1e30;
		}
		else
		{
   			deltaDistY = fabs(1 / rayDirY);
		}

		hit = 0;

		if(rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (game->player.posx - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - game->player.posx ) * deltaDistX;
		}
		if(rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (game->player.posy - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - game->player.posy) * deltaDistY;
		}
		while(hit == 0)
      	{
			//jump to next map square, either in x-direction, or in y-direction
			if(sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
        	}
			if(game->map[(mapX)/64][(mapY)/64] == '1')
			{
				printf("mapx = %d // mapy = %d\n", (mapX)%64, (mapY)%64);
				draw_line((int)game->player.posx, (int)game->player.posy , mapX , mapY, game);
				hit = 1;
			}

		}
		if(side == 0)
			perpWallDist = (sideDistX - deltaDistX);
		else
			perpWallDist = (sideDistY - deltaDistY);
		lineHeight = (int)((game->map_p.height * 64) / perpWallDist);
		drawStart = ((-lineHeight) / 2) + ((game->map_p.height*64) / 2);
		if(drawStart < 0)
			drawStart = 0;
		drawEnd = (lineHeight / 2) + ((game->map_p.height * 64) / 2);
		if(drawEnd >= (game->map_p.height * 64))
			drawEnd = (game->map_p.height * 64) - 1;
		int color;
		if(mapX % 64 == 63 && mapX != 0)
    		color = 0xFF0000; // red 
		else if (mapX % 64 == 0)
		    color = 0xFFFF00; // yellow
		else if(mapY % 64 == 0 && mapY != 0)
    		color =  0x0000FF; // blue
		else if (mapY % 64  == 63)
		    color = 0x00FF00; // green
		else 
			color = 0x000000; //black
		draw_ver_line(game, i ,drawStart, drawEnd ,color);
		i++;
	}

}


void	put_vision(t_game *game)
{
	int i;
	int w;

	i = 0;
	w = 64 * game->map_p.max_widht;
	//printf(" plane x = %f // plane y =%f\n", game->player.planex , game->player.planey);
	while(i < w)
	{
		mlx_pixel_put(game->mlx, game->win, (game->player.posy + (game->player.diry * i)), (game->player.posx + (game->player.dirx  * i)), 0xFFFF00);
		//mlx_pixel_put(game->mlx, game->win, (game->player.posy + (game->player.diry * i)) * game->player.planey, (game->player.posx + (game->player.dirx  * i)) * game->player.planex, 0x00FF0000);
		i++;
	}
}

void	window_image_loop(t_game *game)
{
	int	j;
	int i;

	j = 0;
	i = 0;
	while (game->map && game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game -> map[i][j] == ' ')
				mlx_put_image_to_window(game->mlx, game-> win,
					game->model.north, j * 64, i * 64);
			if (game -> map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game-> win,
					game->model.sud, j * 64, i * 64);
			if (game -> map[i][j] == '0')
				mlx_put_image_to_window(game->mlx, game-> win,
					game->model.east, j * 64, i * 64);
			if (game -> map[i][j] == 'S' || game -> map[i][j] == 'N' || game -> map[i][j] == 'E' || game -> map[i][j] == 'W')
				mlx_put_image_to_window(game->mlx, game-> win,
					game->model.east, j * 64, i * 64);
			j++;
		}
		i++;
	}
	put_player(game);
	put_visionn(game);
	put_vision(game);
}


int	check_hitbox_down(t_game *game)
{
	int box;
	int x;
	int y;

	y = (int) game->player.posy - (game->player.diry * 1);
	x = (int) game->player.posx - (game->player.dirx * 1);
	box = game->player.hitbox;
	if (game->map[((x + box ) / 64)] && game->map[((x + box ) / 64)][(y + box ) / 64] && game->map[((x + box ) / 64)][(y + box ) / 64] == '1') // bas droite
		return (0);
	if (game->map[((x - box ) / 64)] && game->map[((x - box ) / 64)][(y + box ) / 64] && game->map[((x - box ) / 64)][(y + box )  / 64] == '1') // haut gauche
		return (0);
	if (game->map[((x - box ) / 64)] && game->map[((x - box ) / 64)][(y - box ) / 64] && game->map[((x - box ) / 64)][(y - box ) / 64] == '1') // bas droit
		return (0);
	if (game->map[((x + box ) / 64)] && game->map[((x + box ) / 64)][(y - box ) / 64] && game->map[((x + box ) / 64)][(y - box ) / 64] == '1') // bas gauche
		return (0);
	return (1);
}

int	check_hitbox_up(t_game *game)
{
	int box;
	int x;
	int y;

	x = (int) game->player.posx + (game->player.dirx * 1);
	y = (int) game->player.posy + (game->player.diry * 1);
	box = game->player.hitbox;
	if (game->map[((x + box) / 64)] && game->map[((x + box ) / 64)][(y + box ) / 64] && game->map[((x + box ) / 64)][(y + box ) / 64] == '1') // bas droite
		return (0);
	if (game->map[((x - box ) / 64)] && game->map[((x - box ) / 64)][(y + box ) / 64] && game->map[((x - box ) / 64)][(y + box )  / 64] == '1') // haut gauche
		return (0);
	if (game->map[((x - box ) / 64)] && game->map[((x - box ) / 64)][(y - box ) / 64] && game->map[((x - box ) / 64)][(y - box ) / 64] == '1') // bas droit
		return (0);
	if (game->map[((x + box ) / 64)] && game->map[((x + box ) / 64)][(y - box ) / 64] && game->map[((x + box ) / 64)][(y - box ) / 64] == '1') // bas gauche
		return (0);
	return (1);
}

int	move_control(int keycode, t_game *game)
{
	double oldirx;
	double oldPlanex;

	oldPlanex = game->player.planex;
	oldirx = game->player.dirx;
	if (keycode == 119 || keycode == 122)
	{
		//printf("haut\n");
		if (check_hitbox_up(game))
		{
			game->player.posy = game->player.posy + (game->player.diry * 1);
			game->player.posx = game->player.posx + (game->player.dirx * 1);
		}
	}
	if (keycode == 100)
	{
		//printf("droite\n");
		//printf("dir x = %f// dir y = %f\n", game->player.dirx, game->player.diry);

		game->player.dirx = game->player.dirx * cos(-(0.1)) - game->player.diry * sin(-(0.1));
     	game->player.diry = oldirx * sin(-(0.1)) + game->player.diry * cos(-(0.1));

		game->player.planex = game->player.planex * cos(-0.1) - game->player.planey * sin(-0.1);
		game->player.planey = oldPlanex * sin(-0.1) + game->player.planey * cos(-0.1);
		//printf("dir x = %f// dir y = %f\n", game->player.dirx, game->player.diry);
	}
	if (keycode == 97 || keycode == 113)
	{
		//printf("gauche\n");
		//printf("old dir x = %f// old dir y = %f\n", game->player.dirx, game->player.diry);

		game->player.dirx = game->player.dirx * cos((0.1)) - game->player.diry * sin((0.1));
     	game->player.diry = oldirx * sin(0.1) + game->player.diry * cos((0.1));

		game->player.planex = game->player.planex * cos(0.1) - game->player.planey * sin(0.1);
		game->player.planey = oldPlanex * sin(0.1) + game->player.planey * cos(0.1);
		//printf("dir x = %f// dir y = %f\n", game->player.dirx, game->player.diry);
	}
	
	if (keycode == 115)
	{
		//printf("bas\n");
		if (check_hitbox_down(game))
		{
			game->player.posy = game->player.posy - (game->player.diry * 1);
			game->player.posx = game->player.posx - (game->player.dirx * 1);
		}
	}
	if (keycode == 65307)
		mlx_loop_end(game->mlx);
	window_image_loop(game);
	return (0);
}



//north x = 0, y = -1
//sud dirX = 0 dirY = 1
//east dirX = 1 dirY = 0
//weast dirX = -1 dirY = 0


void set_dir_start(t_game *game)
{
	if (game->map[game->player.x] && game->map[game->player.x][game->player.y] == 'W')
	{
		game->player.dirx = 0;
		game->player.diry = -1;
	}
	if (game->map[game->player.x] && game->map[game->player.x][game->player.y] == 'E')
	{
		game->player.dirx = 0;
		game->player.diry = 1;
	}
	if (game->map[game->player.x] && game->map[game->player.x][game->player.y] == 'S')
	{
		game->player.dirx = 1;
		game->player.diry = 0;
	}
	if (game->map[game->player.x] && game->map[game->player.x][game->player.y] == 'N')
	{
		game->player.dirx = -1;
		game->player.diry = 0;
	}
	if(game->player.dirx > 0)
	{
    	game->player.planey = -0.66;
    	game->player.planex = 0;
	}
	else if(game->player.dirx < 0)
	{
    	game->player.planey = 0.66;
    	game->player.planex = 0;
	}
	else if(game->player.diry > 0)
	{
    	game->player.planex = 0.66;
    	game->player.planey = 0;
	}
	else if(game->player.diry < 0)
	{
    	game->player.planex = -0.66;
    	game->player.planey = 0;
	}
}

void set_vecteur_start(t_game *game)
{

	//printf(" seted plane x = %f // plane y =%f\n", game->player.planex , game->player.planey);
	game->player.posx = (double) game->player.x;
	game->player.posy = (double) game->player.y;
}

void start_game(t_game *game)
{
	set_vecteur_start(game);
	game->win = mlx_new_window(game->mlx, 64*game->map_p.max_widht, 64*game->map_p.height, "Hello world!");
	window_image_loop(game);
	mlx_hook(game->win, 2, (1L<<0), move_control, game);
	mlx_loop(game->mlx);
}

int main(int argc, char **argv)
{
	t_game	game;

	argc--;
	argv++;
	set_game(&game);
	parsing_arg(argc, argv); // parse les arguments
	parsing(argv[0], &game); // creer les sprites
	//printf("x = %d / y =%d\n", game.player.x, game.player.y);
	debut(&game);
	//start_game(&game);
	free_game_exit(&game, 1);
}