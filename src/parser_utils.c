#include "../includes/Cub3D.h"

void	check_map_content(t_game *cub)
{
    int	i;
	int	i2;

	i = -1;
	i2 = -1;
	while (cub->map->map_filled[++i])
	{
		while (cub->map->map_filled[i][++i2])
		{
			if (cub->map->map_filled[i][i2] == 'N' || cub->map->map_filled[i][i2] == 'S'
					|| cub->map->map_filled[i][i2] == 'E' || cub->map->map_filled[i][i2] == 'W')
			{
				if (cub->player.posX != 0 || cub->player.posY != 0)
					ft_exit(cub, PLAYER, EXIT_FAILURE);
				cub->player.posX = i2;
				cub->player.posY = i;
			}
		}
		i2 = -1;
		cub->map->map_row++;
	}
}