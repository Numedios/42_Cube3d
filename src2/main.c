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
			mlx_pixel_put(game->mlx, game->win, (int)((game->player.posx - box)), (int)((game->player.posy - box)), 0x00FF0000);
			mlx_pixel_put(game->mlx, game->win, (int)((game->player.posx + box)), (int)((game->player.posy + box)), 0x00FF0000);
			mlx_pixel_put(game->mlx, game->win, (int)((game->player.posx - box)), (int)((game->player.posy + box)), 0x00FF0000);
			mlx_pixel_put(game->mlx, game->win, (int)((game->player.posx + box)), (int)((game->player.posy - box)), 0x00FF0000);
			j++;
		}
		i++;
	}
	mlx_pixel_put(game->mlx, game->win, (game->player.posx), game->player.posy, 0x000000FF);
}

void put_vision(t_game *game)
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
	w = 64*game->map_p.max_widht;
	while(i < w)
	{
		cameraX = 2 * i / (double)w - 1;
		printf("camera = %f\n", cameraX);
		rayDirX = game->player.dirx + game->player.planex * cameraX;
		rayDirY = game->player.diry + game->player.planey * cameraX;

		mapX = (int)game->player.posx;
		mapY = (int)game->player.posy;

		deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
		deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);;

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
		if(game->map[mapY/64][mapX/64] > 0)
			hit = 1;
		if(side == 0)
			perpWallDist = (sideDistX - deltaDistX);
		else
			perpWallDist = (sideDistY - deltaDistY);
		lineHeight = (int)(game->map_p.height / perpWallDist);
		drawStart = -lineHeight / 2 + game->map_p.height / 2;
		if(drawStart < 0)
			drawStart = 0;
		drawEnd = lineHeight / 2 + game->map_p.height / 2;
		if(drawEnd >= game->map_p.height)
			drawEnd = game->map_p.height - 1;
		printf("start = %d // end = %d // x = %d\n", drawStart, drawEnd, i);
		mlx_pixel_put(game->mlx, game->win, (game->player.posx + (game->player.dirx * i)), (game->player.posy + (game->player.diry  * i)), 0x00FF0000);
		i++;
	}
}
/*
void put_visionn(t_game *game)
{
	int w;

	w = 64*game->map_p.max_widht;
    for(int x = 0; x < w; x++)
    {
      //calculate ray position and direction
      double cameraX = 2 * x / (double)w - 1; //x-coordinate in camera space
      double rayDirX = game->player.dirx + game->player.planex * cameraX;
      double rayDirY = game->player.diry + game->player.planey * cameraX;
      //which box of the map we're in
      int mapX = (int) (game->player.posx);
      int mapY = (int) (game->player.posx);

      //length of ray from current position to next x or y-side
      double sideDistX;
      double sideDistY;

      //length of ray from one x or y-side to next x or y-side
      //these are derived as:
      //deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX))
      //deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY))
      //which can be simplified to abs(|rayDir| / rayDirX) and abs(|rayDir| / rayDirY)
      //where |rayDir| is the length of the vector (rayDirX, rayDirY). Its length,
      //unlike (dirX, dirY) is not 1, however this does not matter, only the
      //ratio between deltaDistX and deltaDistY matters, due to the way the DDA
      //stepping further below works. So the values can be computed as below.
      // Division through zero is prevented, even though technically that's not
      // needed in C++ with IEEE 754 floating point values.
      double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
      double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);

      double perpWallDist;

      //what direction to step in x or y-direction (either +1 or -1)
      int stepX;
      int stepY;

      int hit = 0; //was there a wall hit?
      int side; //was a NS or a EW wall hit?
      //calculate step and initial sideDist
      if(rayDirX < 0)
      {
        stepX = -1;
        sideDistX = (game->player.posx - mapX) * deltaDistX;
      }
      else
      {
        stepX = 1;
        sideDistX = (mapX + 1.0 - game->player.posx) * deltaDistX;
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
      //perform DDA
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
        //Check if ray has hit a wall
        if(game->map[mapY][mapX] > 0) hit = 1;
      }
      //Calculate distance projected on camera direction. This is the shortest distance from the point where the wall is
      //hit to the camera plane. Euclidean to center camera point would give fisheye effect!
      //This can be computed as (mapX - posX + (1 - stepX) / 2) / rayDirX for side == 0, or same formula with Y
      //for size == 1, but can be simplified to the code below thanks to how sideDist and deltaDist are computed:
      //because they were left scaled to |rayDir|. sideDist is the entire length of the ray above after the multiple
      //steps, but we subtract deltaDist once because one step more into the wall was taken above.
      if(side == 0) perpWallDist = (sideDistX - deltaDistX);
      else          perpWallDist = (sideDistY - deltaDistY);

      //Calculate height of line to draw on screen
      int lineHeight = (int)(64*game->map_p.height / perpWallDist);

      //calculate lowest and highest pixel to fill in current stripe
      int drawStart = -lineHeight / 2 + 64*game->map_p.height / 2;
      if(drawStart < 0) drawStart = 0;
      int drawEnd = lineHeight / 2 + 64*game->map_p.height / 2;
      if(drawEnd >= 64*game->map_p.height) drawEnd = 64*game->map_p.height - 1;


      //draw the pixels of the stripe as a vertical line
     	print_trait(x, drawStart, drawEnd, game);
	}
}*/

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
	put_vision(game);
}


int	check_hitbox_down(t_game *game)
{
	int box;
	int x;
	int y;

	printf("posx = %f / posy = %f\n",game->player.posx - (game->player.dirx * 1) + box ,game->player.posy - (game->player.diry * 1) + box);
	y = (int) game->player.posy - (game->player.diry * 1);
	x = (int) game->player.posx - (game->player.dirx * 1);
	printf("x = %d / y = %d\n",x + box ,y + box);
	box = game->player.hitbox;
	if (game->map[((y + box ) / 64)] && game->map[((y + box ) / 64)][(x + box ) / 64] && game->map[((y + box ) / 64)][(x + box ) / 64] == '1') // bas droite
		return (0);
	if (game->map[((y - box ) / 64)] && game->map[((y - box ) / 64)][(x + box ) / 64] && game->map[((y - box ) / 64)][(x + box )  / 64] == '1') // haut gauche
		return (0);
	if (game->map[((y - box ) / 64)] && game->map[((y - box ) / 64)][(x - box ) / 64] && game->map[((y - box ) / 64)][(x - box ) / 64] == '1') // bas droit
		return (0);
	if (game->map[((y + box ) / 64)] && game->map[((y + box ) / 64)][(x - box ) / 64] && game->map[((y + box ) / 64)][(x - box ) / 64] == '1') // bas gauche
		return (0);
	return (1);
}

int	check_hitbox_up(t_game *game)
{
	int box;
	int x;
	int y;

	x = (int) game->player.posx + (game->player.dirx * 1);
	y = (int) game->player.posy + (game->player.diry * 1);;
	box = game->player.hitbox;
	if (game->map[((y + box) / 64)] && game->map[((y + box ) / 64)][(x + box ) / 64] && game->map[((y + box ) / 64)][(x + box ) / 64] == '1') // bas droite
		return (0);
	if (game->map[((y - box ) / 64)] && game->map[((y - box ) / 64)][(x + box ) / 64] && game->map[((y - box ) / 64)][(x + box )  / 64] == '1') // haut gauche
		return (0);
	if (game->map[((y - box ) / 64)] && game->map[((y - box ) / 64)][(x - box ) / 64] && game->map[((y - box ) / 64)][(x - box ) / 64] == '1') // bas droit
		return (0);
	if (game->map[((y + box ) / 64)] && game->map[((y + box ) / 64)][(x - box ) / 64] && game->map[((y + box ) / 64)][(x - box ) / 64] == '1') // bas gauche
		return (0);
	return (1);
}

int	move_control(int keycode, t_game *game)
{
	double oldirx;
	double oldPlanex;

	oldPlanex = game->player.planex;
	oldirx = game->player.dirx;
	if (keycode == 119)
	{
		//printf("haut\n");
		if (check_hitbox_up(game))
		{
				game->player.posy = game->player.posy + (game->player.diry * 1);
				game->player.posx = game->player.posx + (game->player.dirx * 1);
		}
	}
	
	if (keycode == 97)
	{
		//printf("droite\n");
		//printf("dir x = %f// dir y = %f\n", game->player.dirx, game->player.diry);

		game->player.dirx = game->player.dirx * cos(-(0.1)) - game->player.diry * sin(-(0.1));
     	game->player.diry = oldirx * sin(-(0.1)) + game->player.diry * cos(-(0.1));

		game->player.planex = game->player.planex * cos(-0.1) - game->player.planey * sin(-0.1);
		game->player.planey = oldPlanex * sin(-0.1) + game->player.planey * cos(-0.1);
		//printf("dir x = %f// dir y = %f\n", game->player.dirx, game->player.diry);
	}
	if (keycode == 100)
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
	if (game->map[game->player.y] && game->map[game->player.y][game->player.x] == 'N')
	{
		game->player.dirx = 0;
		game->player.diry = -1;
	}
	if (game->map[game->player.y] && game->map[game->player.y][game->player.x] == 'S')
	{
		game->player.dirx = 0;
		game->player.diry = 1;
	}
	if (game->map[game->player.y] && game->map[game->player.y][game->player.x] == 'E')
	{
		game->player.dirx = 1;
		game->player.diry = 0;
	}
	if (game->map[game->player.y] && game->map[game->player.y][game->player.x] == 'W')
	{
		game->player.dirx = -1;
		game->player.diry = 0;
	}
}

void set_vecteur_start(t_game *game)
{
	game->player.planex = 0;
	game->player.planey = 0,66;
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