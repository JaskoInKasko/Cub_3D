#include "../includes/Cub3D.h"

void ft_define_direction(t_game *cub, char c)
{
    if (c == 'N')
    {
        cub->player.dirX = 0;
        cub->player.dirY = -1;
        cub->player.planeX = 0.66;
        cub->player.planeY = 0;
    }
    else if (c == 'S')
    {
        cub->player.dirX = 0;
        cub->player.dirY = 1;
        cub->player.planeX = -0.66;
        cub->player.planeY = 0;
    }
    else if (c == 'W')
    {
        cub->player.dirX = -1;
        cub->player.dirY = 0;
        cub->player.planeX = 0;
        cub->player.planeY = -0.66;
    }
    else if (c == 'E')
    {
        cub->player.dirX = 1;
        cub->player.dirY = 0;
        cub->player.planeX = 0;
        cub->player.planeY = 0.66;
    }
}

int		map_content_loop(t_game *cub, int i, int i2, int full_content)
{
	while (cub->map.map_filled[++i])
	{
		while (cub->map.map_filled[i][++i2])
		{
			if (cub->map.map_filled[i][i2] == '1' && full_content == 0)
				full_content = 1;
			if (cub->map.map_filled[i][i2] == 'N' || cub->map.map_filled[i][i2] == 'S'
					|| cub->map.map_filled[i][i2] == 'E' || cub->map.map_filled[i][i2] == 'W')
			{
				if (full_content == 1)
					full_content = 2;
				if (cub->player.posX != 0 || cub->player.posY != 0)
					ft_exit(cub, PLAYER, EXIT_FAILURE);
				ft_define_direction(cub, cub->map.map_filled[i][i2]);
				cub->player.posX = i2 + 0.51;
				cub->player.posY = i + 0.51;
				cub->map.map_filled[i][i2] = '0';
			}
		}
		i2 = -1;
	}
	return (full_content);
}

void	check_map_content(t_game *cub)
{
    int	i;
	int	i2;
	int	full_content;

	i = -1;
	i2 = -1;
	full_content= 0;
	full_content = map_content_loop(cub, i, i2, full_content);
	if (full_content != 2)
		ft_exit(cub, MAP_SIZE, EXIT_FAILURE);
}