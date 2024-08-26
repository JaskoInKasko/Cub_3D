#include "../includes/Cub3D.h"

int	get_mapline_begin(t_game *cub, int i, int i2)
{
	int	begin;

	begin = 0;
	while (cub->map->map_filled[i][++i2] == ' '
        && cub->map->map_filled[i][i2] != '\0')
        begin++;
	if (cub->map->map_filled[i][i2] == '\0'
		|| cub->map->map_filled[i][i2] != '1')
	 	ft_exit(cub, WALL);
	return (begin);
}

void	loop_through_map(t_game *cub, int i, int i2)
{
	while (cub->map->map_filled[i][i2])
	{
		if (cub->map->map_filled[i][i2] == '0')
		{
			if (cub->map->map_filled[i - 1]
				&& (!cub->map->map_filled[i - 1][i2]
					|| cub->map->map_filled[i - 1][i2] == ' '))
				ft_exit(cub, WALL);
			else if (cub->map->map_filled[i + 1]
				&& (!cub->map->map_filled[i + 1][i2]
					|| cub->map->map_filled[i + 1][i2] == ' '))
				ft_exit(cub, WALL);
			else if (!cub->map->map_filled[i][i2 + 1]
					|| cub->map->map_filled[i][i2 + 1] == '\0')
				ft_exit(cub, WALL);
			else if (!cub->map->map_filled[i][i2 - 1]
					|| cub->map->map_filled[i][i2 - 1] == ' ')
				ft_exit(cub, WALL);
		}
        i2++;
	}
}

void    check_map_walls(t_game *cub)
{
    int i;
    int i2;
    int begin;

	i = -1;
    while (cub->map->map_filled[++i])
    {
		i2 = -1;
		begin = get_mapline_begin(cub, i, i2);
        i2 = begin--;
        while (cub->map->map_filled[0][++begin])
		{
			if (cub->map->map_filled[0][begin] == '0')
			{
				if (cub->map->map_filled[1] && cub->map->map_filled[1][begin]
					&& cub->map->map_filled[1][begin] == ' ')
					ft_exit(cub, WALL);
			}
		}
		loop_through_map(cub, i, i2);
    }
}