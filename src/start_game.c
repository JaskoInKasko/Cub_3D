#include "../includes/Cub3D.h"

void ft_calculate_start_and_end_for_minimap_part2(t_game *cub)
{
    if (cub->minimap.end_x > cub->map.map_column + 1)
    {
        cub->minimap.end_x = cub->map.map_column + 1;
        if(cub->map.map_column + 1 < MINIMAP_SIZE)
            cub->minimap.start_x = 0;
        else
            cub->minimap.start_x = cub->map.map_column + 1 - MINIMAP_SIZE;
    }
    if (cub->minimap.end_y > cub->map.map_row + 1)
    {
        cub->minimap.end_y = cub->map.map_row + 1;
        if(cub->map.map_row + 1 < MINIMAP_SIZE)
            cub->minimap.start_y = 0;
        else
            cub->minimap.start_y = cub->map.map_row + 1 - MINIMAP_SIZE;
    }
}

void ft_calculate_start_and_end_for_minimap_part1(t_game *cub)
{
    cub->minimap.start_x = cub->player.posX - (MINIMAP_SIZE / 2);
    cub->minimap.start_y = cub->player.posY - (MINIMAP_SIZE / 2);
    cub->minimap.end_x = cub->player.posX + (MINIMAP_SIZE / 2);
    cub->minimap.end_y = cub->player.posY + (MINIMAP_SIZE / 2);
    if (cub->minimap.start_x < 0) 
    {
        cub->minimap.start_x = 0;
        cub->minimap.end_x = MINIMAP_SIZE;
        // cub->minimap.end_x = MINIMAP_SIZE < cub->map.map_column + 1 ? MINIMAP_SIZE : cub->map.map_column + 1;
    }
    if (cub->minimap.start_y < 0) 
    {
        cub->minimap.start_y = 0;
        cub->minimap.end_y = MINIMAP_SIZE;
        // cub->minimap.end_y = MINIMAP_SIZE < cub->map.map_row + 1 ? MINIMAP_SIZE : cub->map.map_row + 1;
    }
}

void ft_put_image_to_window_for_minimap(t_game *cub)
{
    if ((int)cub->player.posX == cub->minimap.start_x && (int)cub->player.posY == cub->minimap.start_y)
        mlx_put_image_to_window(cub->mlx, cub->win, cub->img.mini_player, cub->minimap.x * MINI_TEX_WIDTH + SCREEN_WIDTH, cub->minimap.y * MINI_TEX_HEIGHT + (SCREEN_HEIGHT / 2));
    else if(cub->map.map_filled[cub->minimap.start_y][cub->minimap.start_x] == '0' || cub->map.map_filled[cub->minimap.start_y][cub->minimap.start_x] == 'O')
        mlx_put_image_to_window(cub->mlx, cub->win, cub->img.mini_floor, cub->minimap.x * MINI_TEX_WIDTH + SCREEN_WIDTH, cub->minimap.y * MINI_TEX_HEIGHT + (SCREEN_HEIGHT / 2));
    else if(cub->map.map_filled[cub->minimap.start_y][cub->minimap.start_x] != ' ')
        mlx_put_image_to_window(cub->mlx, cub->win, cub->img.mini_wall, cub->minimap.x * MINI_TEX_WIDTH + SCREEN_WIDTH, cub->minimap.y * MINI_TEX_HEIGHT + (SCREEN_HEIGHT / 2));
    else
        mlx_put_image_to_window(cub->mlx, cub->win, cub->img.mini_black, cub->minimap.x * MINI_TEX_WIDTH + SCREEN_WIDTH, cub->minimap.y * MINI_TEX_HEIGHT + (SCREEN_HEIGHT / 2));
}

void ft_draw_minimap(t_game *cub)
{
    if(!cub->flag.shoot_flag)
        ft_set_minimap_background(cub);
    ft_calculate_start_and_end_for_minimap_part1(cub);
    ft_calculate_start_and_end_for_minimap_part2(cub);
    cub->minimap.x = 0;
    cub->minimap.y = 0;
    cub->minimap.original_start_x = cub->minimap.start_x;
    while(cub->map.map_filled[cub->minimap.start_y] && cub->minimap.start_y < cub->minimap.end_y)
    {
        cub->minimap.start_x = cub->minimap.original_start_x;
        while(cub->map.map_filled[cub->minimap.start_y][cub->minimap.start_x] && cub->minimap.start_x < cub->minimap.end_x)
        {
            ft_put_image_to_window_for_minimap(cub);
            cub->minimap.x++;
            cub->minimap.start_x++;
        }
        cub->minimap.start_y++;
        cub->minimap.x = 0;
        cub->minimap.y++;
    }
}


void ft_calculate_vars_values_for_draw_part1(t_game *cub)
{
    cub->ray.rayDirX = cub->player.dirX + cub->player.planeX * cub->ray.cameraX;
    cub->ray.rayDirY = cub->player.dirY + cub->player.planeY * cub->ray.cameraX;
    cub->ray.mapX = (int)cub->player.posX;
    cub->ray.mapY = (int)cub->player.posY;
    cub->ray.deltaDistX = fabs(1.0 / cub->ray.rayDirX);
    cub->ray.deltaDistY = fabs(1.0 / cub->ray.rayDirY);
    cub->ray.stepX = 1;
    cub->ray.stepY = 1;
    cub->ray.sideDistX = (cub->ray.mapX + 1.0 - cub->player.posX) * cub->ray.deltaDistX;
    cub->ray.sideDistY = (cub->ray.mapY + 1.0 - cub->player.posY) * cub->ray.deltaDistY;
    if(cub->ray.rayDirX == 0)
        cub->ray.deltaDistX = 1e30;
    if(cub->ray.rayDirY == 0)
        cub->ray.deltaDistY = 1e30;
    if(cub->ray.rayDirX < 0)
    {
        cub->ray.stepX = -1;
        cub->ray.sideDistX = (cub->player.posX - cub->ray.mapX) * cub->ray.deltaDistX;
    }
    if(cub->ray.rayDirY < 0)
    {
        cub->ray.stepY = -1;
        cub->ray.sideDistY = (cub->player.posY - cub->ray.mapY) * cub->ray.deltaDistY;
    }
}

void ft_find_hit_point(t_game *cub)
{
    cub->ray.hit = 0;
    while(cub->ray.hit == 0)
    {
        if(cub->ray.sideDistX < cub->ray.sideDistY)
        {
            cub->ray.sideDistX += cub->ray.deltaDistX;
            cub->ray.mapX += cub->ray.stepX;
            cub->ray.side = 0;
        }
        else
        {
            cub->ray.sideDistY += cub->ray.deltaDistY;
            cub->ray.mapY += cub->ray.stepY;
            cub->ray.side = 1;
        }
        // if(!cub->map.map_filled[mapX][mapY])
        // 	break;
        if(cub->map.map_filled[cub->ray.mapY][cub->ray.mapX] != '0' && cub->map.map_filled[cub->ray.mapY][cub->ray.mapX] != 'O')
            cub->ray.hit = 1;
    }
}

void ft_calculate_vars_values_for_draw_part2(t_game *cub)
{
    if(cub->ray.side == 0) 
        cub->ray.perpWallDist = (cub->ray.sideDistX - cub->ray.deltaDistX);
    else          
        cub->ray.perpWallDist = (cub->ray.sideDistY - cub->ray.deltaDistY);
    cub->ray.lineHeight = (int)(SCREEN_HEIGHT / cub->ray.perpWallDist);
    cub->ray.drawStart = -cub->ray.lineHeight / 2 + SCREEN_HEIGHT / 2;
    if(cub->ray.drawStart < 0) 
        cub->ray.drawStart = 0;
    cub->ray.drawEnd = cub->ray.lineHeight / 2 + SCREEN_HEIGHT / 2;
    if(cub->ray.drawEnd >= SCREEN_HEIGHT) 
        cub->ray.drawEnd = SCREEN_HEIGHT - 1;
    if (cub->ray.side == 0) 
        cub->ray.wallX = cub->player.posY + cub->ray.perpWallDist * cub->ray.rayDirY;
    else           
        cub->ray.wallX = cub->player.posX + cub->ray.perpWallDist * cub->ray.rayDirX;
    cub->ray.wallX -= floor(cub->ray.wallX);
    cub->ray.texX = (int)(cub->ray.wallX * (double)TEXTURE_WIDTH);
    if (cub->ray.side == 0 && cub->ray.rayDirX > 0) 
        cub->ray.texX = TEXTURE_WIDTH - cub->ray.texX - 1; // Reverse texture, ters gorune biler bunsuz
    if (cub->ray.side == 1 && cub->ray.rayDirY < 0) 
        cub->ray.texX = TEXTURE_WIDTH - cub->ray.texX - 1; // Reverse texture
}

void ft_define_pixel_color_for_draw(t_game *cub, int y)
{
    cub->ray.texY = (((y * 256 - SCREEN_HEIGHT * 128 + cub->ray.lineHeight * 128) * TEXTURE_HEIGHT) / cub->ray.lineHeight) / 256;
    if(cub->map.map_filled[cub->ray.mapY][cub->ray.mapX] == 'D')
        cub->ray.color = cub->img.data_enemy + (cub->ray.texY * cub->img.tex_line_length + cub->ray.texX * (cub->img.bits_per_pixel / 8));
    else if(cub->map.map_filled[cub->ray.mapY][cub->ray.mapX] == 'C')
        cub->ray.color = cub->img.data_door + (cub->ray.texY * cub->img.tex_line_length + cub->ray.texX * (cub->img.bits_per_pixel / 8));
    else if(cub->ray.side == 1 && cub->ray.rayDirY > 0)
        cub->ray.color = cub->img.data_south + (cub->ray.texY * cub->img.tex_line_length + cub->ray.texX * (cub->img.bits_per_pixel / 8));
    else if (cub->ray.side == 1 && cub->ray.rayDirY < 0)
        cub->ray.color = cub->img.data_north + (cub->ray.texY * cub->img.tex_line_length + cub->ray.texX * (cub->img.bits_per_pixel / 8));
    else if (cub->ray.side == 0 && cub->ray.rayDirX > 0)
        cub->ray.color = cub->img.data_east + (cub->ray.texY * cub->img.tex_line_length + cub->ray.texX * (cub->img.bits_per_pixel / 8));
    else if (cub->map.map_filled[cub->ray.mapY][cub->ray.mapX] == 'H')
        cub->ray.color = cub->img.data_hitler + (cub->ray.texY * cub->img.tex_line_length + cub->ray.texX * (cub->img.bits_per_pixel / 8));
    else if (cub->ray.side == 0 && cub->ray.rayDirX < 0 && cub->map.map_filled[cub->ray.mapY][cub->ray.mapX] == '1')
        cub->ray.color = cub->img.data_west + (cub->ray.texY * cub->img.tex_line_length + cub->ray.texX * (cub->img.bits_per_pixel / 8));
    cub->ray.color_int = *(unsigned int*)cub->ray.color;
    if (cub->ray.side == 1) 
        cub->ray.color_int = (cub->ray.color_int >> 1) & 8355711; // Darken the color for y-side walls
}

void ft_set_screen(t_game *cub)
{
    int x;
    int y;

    x = -1;
    y = -1;
    while(++x < SCREEN_WIDTH)
    {
        cub->ray.cameraX = 2 * x / (double)SCREEN_WIDTH - 1;
        ft_calculate_vars_values_for_draw_part1(cub);
        ft_find_hit_point(cub);
        ft_calculate_vars_values_for_draw_part2(cub);
        y = cub->ray.drawStart;
        while (y < cub->ray.drawEnd) 
        {
            ft_define_pixel_color_for_draw(cub, y);
            my_mlx_pixel_put(cub, x, y, cub->ray.color_int);
            y++;
        }
    } 
}
void ft_draw(t_game *cub)
{
    int x;
    int y;

    x = -1;
    y = -1;
    ft_set_background(cub);
    ft_set_text(cub);
    ft_set_screen(cub);
    if(!cub->flag.shoot_flag)
        ft_set_pistol(cub);
    else
        ft_set_pistol_shoot(cub);
    ft_set_scope(cub);
    mlx_put_image_to_window(cub->mlx, cub->win, cub->img.img, 0, 0);
    ft_draw_minimap(cub);
}

