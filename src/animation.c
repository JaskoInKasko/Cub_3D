#include "../includes/Cub3D.h"

int	ft_animation(t_game *cub)
{
	size_t	i = 0;

    if(cub->flag.shoot_flag == 1)
    {
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