#include "../includes/Cub3D.h"

int	get_mapline_begin(t_game *cub, int istr, int iletter)
{
	int	begin;

	begin = 0;
	while (cub->map->map_filled[istr][++iletter] == ' '
        && cub->map->map_filled[istr][iletter] != '\0')
        begin++;
	if (cub->map->map_filled[istr][iletter] == '\0'
		|| cub->map->map_filled[istr][iletter] != '1')
	 	ft_exit(cub, WALL);
	return (begin);
}

void	check_left_walls(t_game *cub, int istr, int iletter, int begin)
{
	if (istr > 0)
	{
		if (begin > cub->map->line_begin_prev)
		{
			while (begin > cub->map->line_begin_prev)
			{
				if (cub->map->map_filled[istr - 1][cub->map->line_begin_prev] != '1')
				 	ft_exit(cub, WALL);
				cub->map->line_begin_prev++;
			}
		}
		else if (begin < cub->map->line_begin_prev)
		{
			iletter = begin;
			while (iletter < cub->map->line_begin_prev)
			{
				if (cub->map->map_filled[istr][iletter] != '1')
				 	ft_exit(cub, WALL);
				iletter++;
			}
		}
	}
}

void	check_right_walls(t_game *cub, int istr , int end)
{
	if (istr > 0)
	{
		if (end > cub->map->line_end_prev)
		{
			while (end > cub->map->line_end_prev)
			{
				if (cub->map->map_filled[istr][end] != '1')
				 	ft_exit(cub, WALL);
				end--;
			}
		}
		if (end < cub->map->line_end_prev)
		{
			while (end < cub->map->line_end_prev)
			{
				if (cub->map->map_filled[istr - 1][cub->map->line_end_prev] != '1')
				 	ft_exit(cub, WALL);
				cub->map->line_end_prev--;
			}
		}
	}
}

void	check_last_row_walls(t_game *cub, int istr, int iletter)
{
	iletter = -1;
    istr--;
    while (cub->map->map_filled[istr][++iletter])
        if (cub->map->map_filled[istr][iletter] != '1')
            ft_exit(cub, WALL);
}

void    check_map_walls(t_game *cub)
{
    int istr;
    int iletter;
    int begin;
    int end;

	istr = -1;
    while (cub->map->map_filled[++istr])
    {
		iletter = -1;
		begin = get_mapline_begin(cub, istr, iletter);
		check_left_walls(cub, istr, iletter, begin);
		cub->map->line_begin_prev = begin;
        iletter = begin--;
        while (cub->map->map_filled[0][++begin])
			if (cub->map->map_filled[0][begin] != '1')
            	ft_exit(cub, WALL);
        while (cub->map->map_filled[istr][iletter])
            iletter++;
		end = iletter - 1;
		check_right_walls(cub, istr , end);
        cub->map->line_end_prev = iletter - 1;
        if (cub->map->map_filled[istr][cub->map->line_end_prev] != '1')
            ft_exit(cub, WALL);
    }
    check_last_row_walls(cub, istr, iletter);
}