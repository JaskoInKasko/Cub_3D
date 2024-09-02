#include "../includes/Cub3D.h"

void my_mlx_pixel_put(t_game *cub, int x, int y, int color)
{
    char    *dst;

    dst = cub->img.addr + (y * cub->img.line_length + x * (cub->img.bits_per_pixel / 8));
    *(unsigned int*)dst = color;
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