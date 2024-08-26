#include "../includes/Cub3D.h"

// void ft_draw(t_vars *vars)
// {
//     set_background(vars);
//     for(int x = 0; x < screenWidth; x++)
//     {
//         double cameraX = 2 * x / (double)screenWidth - 1;
//         double rayDirX = vars->dirX + vars->planeX * cameraX;
//         double rayDirY = vars->dirY + vars->planeY * cameraX;

//         int mapX = (int)vars->posX;
//         int mapY = (int)vars->posY;

//         double sideDistX;
//         double sideDistY;

//         double deltaDistX;
//         double deltaDistY;


//         if (rayDirX == 0) {
//             deltaDistX = 1e30; // Effectively infinity
//         } else {
//             deltaDistX = fabs(1.0 / rayDirX);
//         }

//         if (rayDirY == 0) {
//             deltaDistY = 1e30; // Effectively infinity
//         } else {
//             deltaDistY = fabs(1.0 / rayDirY);
//         }

//         double perpWallDist;

//         int stepX;
//         int stepY;

//         int hit = 0;
//         int side;

//         if(rayDirX < 0)
//         {
//             stepX = -1;
//             sideDistX = (vars->posX - mapX) * deltaDistX;
//         }
//         else
//         {
//             stepX = 1;
//             sideDistX = (mapX + 1.0 - vars->posX) * deltaDistX;
//         }
//         if(rayDirY < 0)
//         {
//             stepY = -1;
//             sideDistY = (vars->posY - mapY) * deltaDistY;
//         }
//         else
//         {
//             stepY = 1;
//             sideDistY = (mapY + 1.0 - vars->posY) * deltaDistY;
//         }

//         while(hit == 0)
//         {
//             if(sideDistX < sideDistY)
//             {
//                 sideDistX += deltaDistX;
//                 mapX += stepX;
//                 side = 0;
//             }
//             else
//             {
//                 sideDistY += deltaDistY;
//                 mapY += stepY;
//                 side = 1;
//             }
//             if(vars->worldMap[mapX][mapY] > '0') hit = 1;
//         }

//         if(side == 0) perpWallDist = (sideDistX - deltaDistX);
//         else          perpWallDist = (sideDistY - deltaDistY);

//         int lineHeight = (int)(screenHeight / perpWallDist);
//         int drawStart = -lineHeight / 2 + screenHeight / 2;
//         if(drawStart < 0) drawStart = 0;
//         int drawEnd = lineHeight / 2 + screenHeight / 2;
//         if(drawEnd >= screenHeight) drawEnd = screenHeight - 1;

//         double wallX;
//         if (side == 0) wallX = vars->posY + perpWallDist * rayDirY;
//         else           wallX = vars->posX + perpWallDist * rayDirX;
//         wallX -= floor(wallX);

//         int texX = (int)(wallX * (double)texWidth);
//         if (side == 0 && rayDirX > 0) texX = texWidth - texX - 1; // Reverse texture, ters gorune biler bunsuz
//         if (side == 1 && rayDirY < 0) texX = texWidth - texX - 1; // Reverse texture
//         char *color;
        
//         for (int y = drawStart; y < drawEnd; y++) 
//         {
//             int texY = (((y * 256 - screenHeight * 128 + lineHeight * 128) * texHeight) / lineHeight) / 256;
//             if(vars->worldMap[mapX][mapY] == 'E')
//                 color = vars->data_enemy + (texY * vars->tex_line_length + texX * (vars->bits_per_pixel / 8));
//             else if(vars->worldMap[mapX][mapY] == '3')
//                 color = vars->data_door + (texY * vars->tex_line_length + texX * (vars->bits_per_pixel / 8));
//             else if(side == 1 && rayDirY > 0)
//                 color = vars->data_north + (texY * vars->tex_line_length + texX * (vars->bits_per_pixel / 8));
//             else if (side == 1 && rayDirY < 0)
//                 color = vars->data_south + (texY * vars->tex_line_length + texX * (vars->bits_per_pixel / 8));
//             else if (side == 0 && rayDirX > 0)
//                 color = vars->data_west + (texY * vars->tex_line_length + texX * (vars->bits_per_pixel / 8));
//             else if (vars->worldMap[mapX][mapY] == '1')
//                 color = vars->data_east + (texY * vars->tex_line_length + texX * (vars->bits_per_pixel / 8));
//             else
//                 color = vars->data_hitler + (texY * vars->tex_line_length + texX * (vars->bits_per_pixel / 8));

//             int color_int = *(unsigned int*)color;
//             if (side == 1) color_int = (color_int >> 1) & 8355711; // Darken the color for y-side walls
//             my_mlx_pixel_put(vars, x, y, color_int);
//         }
//     }
//     set_pistol(vars);
//     set_scope(vars);
//     mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
//     int x = 0;
//     int y = 0;
//     while(vars->worldMap[x] && x < mapWidth)
//     {
//         int m = x * 10;
//         while(vars->worldMap[x][y])
//         {
//             int n = y * 10;
//             if(vars->worldMap[x][y] == '0')
//             {
//                 mlx_put_image_to_window(vars->mlx, vars->win, vars->mini_floor, m + 640, n + 240);
//             }
//             else if(vars->worldMap[x][y] == 'P')
//             {
//                 mlx_put_image_to_window(vars->mlx, vars->win, vars->mini_player, m + 640, n + 240);
//             }
//             else
//             {
//                 mlx_put_image_to_window(vars->mlx, vars->win, vars->mini_wall, m + 640, n + 240);
//             }
//             y = y + 1;
//         }
//         y = 0;
//         x = x + 1;
//     }
// }

void ft_load_texture(t_game *cub)
{
    int width;
    int height;

    cub->img.north = mlx_xpm_file_to_image(cub->mlx, "textures/blue.xpm", &width, &height);
    cub->img.south = mlx_xpm_file_to_image(cub->mlx, "textures/brick.xpm", &width, &height);
    cub->img.east = mlx_xpm_file_to_image(cub->mlx, "textures/grey.xpm", &width, &height);
    cub->img.west = mlx_xpm_file_to_image(cub->mlx, "textures/wood.xpm", &width, &height);
    cub->img.hitler = mlx_xpm_file_to_image(cub->mlx, "textures/hitler.xpm", &width, &height);
    cub->img.door = mlx_xpm_file_to_image(cub->mlx, "textures/door.xpm", &width, &height);
    cub->img.pistol = mlx_xpm_file_to_image(cub->mlx, "textures/pistol_original.xpm", &width, &height);
    cub->img.scope = mlx_xpm_file_to_image(cub->mlx, "textures/scope.xpm", &width, &height);
    cub->img.enemy = mlx_xpm_file_to_image(cub->mlx, "textures/enemy.xpm", &width, &height);
    cub->img.mini_floor = mlx_xpm_file_to_image(cub->mlx, "textures/mini_floor.xpm", &width, &height);
    cub->img.mini_wall = mlx_xpm_file_to_image(cub->mlx, "textures/mini_wall.xpm", &width, &height);
    cub->img.mini_player = mlx_xpm_file_to_image(cub->mlx, "textures/mini_player.xpm", &width, &height);

    cub->img.data_south = mlx_get_data_addr(cub->img.south, &cub->img.bits_per_pixel, &cub->img.tex_line_length, &cub->img.endian);
    cub->img.data_north = mlx_get_data_addr(cub->img.north, &cub->img.bits_per_pixel, &cub->img.tex_line_length, &cub->img.endian);
    cub->img.data_east = mlx_get_data_addr(cub->img.east, &cub->img.bits_per_pixel, &cub->img.tex_line_length, &cub->img.endian);
    cub->img.data_west = mlx_get_data_addr(cub->img.west, &cub->img.bits_per_pixel, &cub->img.tex_line_length, &cub->img.endian);
    cub->img.data_hitler = mlx_get_data_addr(cub->img.hitler, &cub->img.bits_per_pixel, &cub->img.tex_line_length, &cub->img.endian);
    cub->img.data_door = mlx_get_data_addr(cub->img.door, &cub->img.bits_per_pixel, &cub->img.tex_line_length, &cub->img.endian);
    cub->img.data_pistol = mlx_get_data_addr(cub->img.pistol, &cub->img.bits_per_pixel, &cub->img.pistol_line_length, &cub->img.endian);
    cub->img.data_scope = mlx_get_data_addr(cub->img.scope, &cub->img.bits_per_pixel, &cub->img.scope_line_length, &cub->img.endian);
    cub->img.data_enemy = mlx_get_data_addr(cub->img.enemy, &cub->img.bits_per_pixel, &cub->img.tex_line_length, &cub->img.endian);
}

int	ft_x(t_game *cub)
{
    ft_exit(cub, ESC, EXIT_SUCCESS);
    return 0;
}

void ft_start_game(t_game *cub)
{
   	cub->mlx = mlx_init();
	if (cub->mlx == NULL)
		ft_exit(cub, MLX_INT, EXIT_FAILURE);
    cub->win = mlx_new_window(	cub->mlx, SCREEN_WIDTH + 240, SCREEN_HEIGHT, "Wolfenstein 3D");
    if(cub->win == NULL)
        ft_exit(cub, MLX_WIN, EXIT_FAILURE);
    cub->img.img = mlx_new_image(cub->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
    cub->img.addr = mlx_get_data_addr(cub->img.img, &cub->img.bits_per_pixel, &cub->img.line_length, &cub->img.endian);
	ft_load_texture(cub);
	// ft_draw(cub);
	mlx_hook(cub->win, DestroyNotify, DestroyAll, &ft_x, cub);
	mlx_loop(cub->mlx);
}
int	main(int argc, char *argv[])
{
	t_game cub;

	if (argc == 2)
	{
		ft_bzero(&cub, sizeof(t_game));
		alloc_structs(&cub);
		init_structs(&cub, argv);
		check_map_walls(&cub);
		check_map_content(&cub);
		ft_start_game(&cub);
		ft_exit(&cub, NULL, EXIT_SUCCESS);
	}
	else
		ft_putstr_fd(INV_ARGS, 2);
	return (0);
}
// int main()
// {
//     void *mlx;
//     void *win;

//     mlx = mlx_init();
//     win = mlx_new_window(mlx, 640, 480, "Hello, MinilibX!");
//     mlx_loop(mlx);
//     return (0);
// }
