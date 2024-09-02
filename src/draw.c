#include "../includes/Cub3D.h"

void my_mlx_pixel_put(t_game *cub, int x, int y, int color)
{
    char    *dst;

    dst = cub->img.addr + (y * cub->img.line_length + x * (cub->img.bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void ft_set_pistol_shoot(t_game *cub)
{
    char *color;
	int x;
	int y;

	x = 0;
	y = 0;
	while(y < PISTOL_HEIGHT)
	{
		while(x < PISTOL_WIDTH)
		{
			color = cub->img.data_pistol_shoot + (y * cub->img.pistol_line_length + x * (cub->img.bits_per_pixel / 8));
			unsigned int color_int = *(unsigned int*)color;
			if(color_int != 0xFF000000) //0xFF000000 is the background color, we don't want to draw it, so we skip it
				my_mlx_pixel_put(cub, x + (SCREEN_WIDTH - PISTOL_WIDTH) / 2, y + SCREEN_HEIGHT - PISTOL_HEIGHT, color_int);
			x++;
		}
		x = 0;
		y++;
	}
}

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

void ft_set_minimap_background(t_game *cub)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while(y < MINIMAP_SIZE)
	{
		while(x < MINIMAP_SIZE)
		{
			mlx_put_image_to_window(cub->mlx, cub->win, cub->img.mini_black, x * MINI_TEX_WIDTH + SCREEN_WIDTH, y * MINI_TEX_HEIGHT + (SCREEN_HEIGHT / 2));
			x++;
		}
		x = 0;
		y++;
	}
}

void ft_set_background(t_game *cub)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while(y < SCREEN_HEIGHT)
    {
        if(y < SCREEN_HEIGHT / 2)
        {
            while(x < SCREEN_WIDTH)
            {
                my_mlx_pixel_put(cub, x, y, SKY_BLUE);
                x++;
            }
        }
        else
        {
            while(x < SCREEN_WIDTH)
            {
                my_mlx_pixel_put(cub, x, y, FLOOR_COLOR);
                x++;
            }
        }
        x = 0;
        y++;
    }
}

void ft_set_pistol(t_game *cub)
{
    char *color;
	int x;
	int y;

	x = 0;
	y = 0;
	while(y < PISTOL_HEIGHT)
	{
		while(x < PISTOL_WIDTH)
		{
			color = cub->img.data_pistol + (y * cub->img.pistol_line_length + x * (cub->img.bits_per_pixel / 8));
			unsigned int color_int = *(unsigned int*)color;
			if(color_int != 0xFF000000) //0xFF000000 is the background color, we don't want to draw it, so we skip it
				my_mlx_pixel_put(cub, x + (SCREEN_WIDTH - PISTOL_WIDTH) / 2, y + SCREEN_HEIGHT - PISTOL_HEIGHT, color_int);
			x++;
		}
		x = 0;
		y++;
	}
}

void ft_set_scope(t_game *cub)
{
	char *color;
	int x;
	int y;

	x = 0;
	y = 0;
	while(y < SCOPE_HEIGHT)
	{
		while(x < SCOPE_WIDTH)
		{
			color = cub->img.data_scope + (y * cub->img.scope_line_length + x * (cub->img.bits_per_pixel / 8));
			unsigned int color_int = *(unsigned int*)color;
			if(color_int != 0xFF000000) //0xFF000000 is the background color, we don't want to draw it, so we skip it
				my_mlx_pixel_put(cub, x + (SCREEN_WIDTH - SCOPE_WIDTH) / 2, y + (SCREEN_HEIGHT - SCOPE_HEIGHT) / 2, color_int);
			x++;
		}
		x = 0;
		y++;
	}
}