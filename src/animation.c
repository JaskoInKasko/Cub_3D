#include "../includes/Cub3D.h"

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


int	ft_animation(t_game *cub)
{
	size_t	i = 0;

    if(cub->flag.shoot_flag == 1)
    {
        ft_set_pistol_shoot(cub);
        ft_draw(cub);
        while(1)
        {
            if(i == 1000000000)
            {
                cub->flag.shoot_flag = 0;
                ft_draw(cub);
                break;
            }
            i++;
        }
    }
    return 0;
}