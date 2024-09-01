#include "../includes/Cub3D.h"

void ft_set_text(t_game *cub)
{
    mlx_string_put(cub->mlx, cub->win, SCREEN_WIDTH + 15, 20 , 0x00FFFFFF, "Welcome to Cub3D!");
    mlx_string_put(cub->mlx, cub->win, SCREEN_WIDTH + 15, 60, 0x00FFFFFF, "Controls:");
    mlx_string_put(cub->mlx, cub->win, SCREEN_WIDTH + 15, 80, 0x00FFFFFF, "Move: W, A, S, D or Mouse");
    mlx_string_put(cub->mlx, cub->win, SCREEN_WIDTH + 15, 100, 0x00FFFFFF, "Rotate: Left Arrow, Right Arrow");
    mlx_string_put(cub->mlx, cub->win, SCREEN_WIDTH + 15, 120, 0x00FFFFFF, "Exit: ESC or X Button");
    mlx_string_put(cub->mlx, cub->win, SCREEN_WIDTH + 15, 140, 0x00FFFFFF, "Shoot: F or Right Click");
    mlx_string_put(cub->mlx, cub->win, SCREEN_WIDTH + 15, 160, 0x00FFFFFF, "Open Door: Space");
    mlx_string_put(cub->mlx, cub->win, SCREEN_WIDTH + 15, 180, 0x00FFFFFF, "Close Door: Space");
    mlx_string_put(cub->mlx, cub->win, SCREEN_WIDTH + 15, 200, 0x00FFFFFF, "Enjoy the game!");
    mlx_string_put(cub->mlx, cub->win, SCREEN_WIDTH + 15, SCREEN_HEIGHT / 2 - 10, 0x00FFFFFF, "@ Ismayil && Jasmin");
}

void ft_draw(t_game *cub)
{
    int x;
    int y;

    x = -1;
    y = -1;
    ft_set_background(cub);
    ft_set_text(cub);
    while(++x < SCREEN_WIDTH)
    {
        double cameraX = 2 * x / (double)SCREEN_WIDTH - 1;
        double rayDirX = cub->player.dirX + cub->player.planeX * cameraX;
        double rayDirY = cub->player.dirY + cub->player.planeY * cameraX;

        int mapX = (int)cub->player.posX;
        int mapY = (int)cub->player.posY;

        double sideDistX;
        double sideDistY;

        double deltaDistX;
        double deltaDistY;


        if (rayDirX == 0) {
            deltaDistX = 1e30; // Effectively infinity
        } else {
            deltaDistX = fabs(1.0 / rayDirX);
        }

        if (rayDirY == 0) {
            deltaDistY = 1e30; // Effectively infinity
        } else {
            deltaDistY = fabs(1.0 / rayDirY);
        }
        double perpWallDist;

        int stepX;
        int stepY;

        int hit = 0;
        int side;

        if(rayDirX < 0)
        {
            stepX = -1;
            sideDistX = (cub->player.posX - mapX) * deltaDistX;
        }
        else
        {
            stepX = 1;
            sideDistX = (mapX + 1.0 - cub->player.posX) * deltaDistX;
        }
        if(rayDirY < 0)
        {
            stepY = -1;
            sideDistY = (cub->player.posY - mapY) * deltaDistY;
        }
        else
        {
            stepY = 1;
            sideDistY = (mapY + 1.0 - cub->player.posY) * deltaDistY;
        }

        while(hit == 0)
        {
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
			// if(!cub->map->map_filled[mapX][mapY])
			// 	break;
            if(cub->map->map_filled[mapY][mapX] != '0' && cub->map->map_filled[mapY][mapX] != 'O')
				hit = 1;
        }

        if(side == 0) perpWallDist = (sideDistX - deltaDistX);
        else          perpWallDist = (sideDistY - deltaDistY);

        int lineHeight = (int)(SCREEN_HEIGHT / perpWallDist);
        int drawStart = -lineHeight / 2 + SCREEN_HEIGHT / 2;
        if(drawStart < 0) drawStart = 0;
        int drawEnd = lineHeight / 2 + SCREEN_HEIGHT / 2;
        if(drawEnd >= SCREEN_HEIGHT) drawEnd = SCREEN_HEIGHT - 1;

        double wallX;
        if (side == 0) wallX = cub->player.posY + perpWallDist * rayDirY;
        else           wallX = cub->player.posX + perpWallDist * rayDirX;
        wallX -= floor(wallX);

        int texX = (int)(wallX * (double)TEXTURE_WIDTH);
        if (side == 0 && rayDirX > 0) texX = TEXTURE_WIDTH - texX - 1; // Reverse texture, ters gorune biler bunsuz
        if (side == 1 && rayDirY < 0) texX = TEXTURE_WIDTH - texX - 1; // Reverse texture
        char *color;
        y = drawStart;
        while (y < drawEnd) 
        {
            int texY = (((y * 256 - SCREEN_HEIGHT * 128 + lineHeight * 128) * TEXTURE_HEIGHT) / lineHeight) / 256;
            if(cub->map->map_filled[mapY][mapX] == 'D')
                color = cub->img.data_enemy + (texY * cub->img.tex_line_length + texX * (cub->img.bits_per_pixel / 8));
            else if(cub->map->map_filled[mapY][mapX] == 'C')
                color = cub->img.data_door + (texY * cub->img.tex_line_length + texX * (cub->img.bits_per_pixel / 8));
            else if(side == 1 && rayDirY > 0)
                color = cub->img.data_north + (texY * cub->img.tex_line_length + texX * (cub->img.bits_per_pixel / 8));
            else if (side == 1 && rayDirY < 0)
                color = cub->img.data_south + (texY * cub->img.tex_line_length + texX * (cub->img.bits_per_pixel / 8));
            else if (side == 0 && rayDirX > 0)
                color = cub->img.data_west + (texY * cub->img.tex_line_length + texX * (cub->img.bits_per_pixel / 8));
            else if (cub->map->map_filled[mapY][mapX] == 'H')
                color = cub->img.data_hitler + (texY * cub->img.tex_line_length + texX * (cub->img.bits_per_pixel / 8));
            else if (side == 0 && rayDirX < 0 && cub->map->map_filled[mapY][mapX] == '1')
                color = cub->img.data_east + (texY * cub->img.tex_line_length + texX * (cub->img.bits_per_pixel / 8));
            int color_int = *(unsigned int*)color;
            if (side == 1) color_int = (color_int >> 1) & 8355711; // Darken the color for y-side walls
            my_mlx_pixel_put(cub, x, y, color_int);
            y++;
        }
    }
    if(!cub->flag.shoot_flag)
        ft_set_pistol(cub);
    else
        ft_set_pistol_shoot(cub);
    ft_set_scope(cub);
    mlx_put_image_to_window(cub->mlx, cub->win, cub->img.img, 0, 0);
    x = 0;
    y = 0;
    while(cub->map->map_filled[y] && y < 24)
    {
        int m = y * 10;
        while(cub->map->map_filled[y][x])
        {
            int n = x * 10;
            if(cub->map->map_filled[y][x] == '0' || cub->map->map_filled[y][x] == 'O')
            {
                mlx_put_image_to_window(cub->mlx, cub->win, cub->img.mini_floor, n + 640, m + 240);
            }
            else if(cub->map->map_filled[y][x] != ' ')
            {
                mlx_put_image_to_window(cub->mlx, cub->win, cub->img.mini_wall, n + 640, m + 240);
            }
            x = x + 1;
        }
        x = 0;
        y = y + 1;
    }
    mlx_put_image_to_window(cub->mlx, cub->win, cub->img.mini_player, (int)cub->player.posX * MINI_TEX_WIDTH + SCREEN_WIDTH, (int)cub->player.posY * MINI_TEX_HEIGHT + (SCREEN_HEIGHT / 2));

}

    // int x = 0;
    // int y = 0;
    // while(cub->map->map_filled[y] && y < 24)
    // {
    //     int m = y * 10;
    //     while(cub->map->map_filled[x][y])
    //     {
    //         int n = x * 10;
    //         if(cub->map->map_filled[y][x] == '0' || cub->map->map_filled[startY][startX] == 'O')
    //         {
    //             mlx_put_image_to_window(cub->mlx, cub->win, vars->mini_floor, n + 640, m + 240);
    //         }
    //         else if(cub->map->map_filled[y][x] != ' ')
    //         {
    //             mlx_put_image_to_window(cub->mlx, cub->win, vars->mini_wall, n + 640, m + 240);
    //         }
    //         x = x + 1;
    //     }
    //     x = 0;
    //     y = y + 1;
    // }
    // mlx_put_image_to_window(cub->mlx, cub->win, cub->img.mini_player, (int)cub->player.posX * MINI_TEX_WIDTH + SCREEN_WIDTH, (int)cub->player.posY * MINI_TEX_HEIGHT + (SCREEN_HEIGHT / 2));

