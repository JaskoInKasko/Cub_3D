#include "../includes/Cub3D.h"

void    check_map(t_game *cub)
{
    int istr;
    int iletter;
    int begin;
    int end;

	istr = -1;
    while (cub->map->map_filled[++istr])
    {
		begin = 0;
		iletter = -1;
        while (cub->map->map_filled[istr][++iletter] == ' '
            && cub->map->map_filled[istr][iletter] != '\0')
            begin++;
		if (cub->map->map_filled[istr][iletter] == '\0')
		 	ft_exit(cub, WALL);
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
		cub->map->line_begin_prev = begin;
        iletter = begin;
		begin--;
        while (cub->map->map_filled[0][++begin])
			if (cub->map->map_filled[0][begin] != '1')
            	ft_exit(cub, WALL);
        while (cub->map->map_filled[istr][iletter])
            iletter++;
		end = iletter - 1;
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
        cub->map->line_end_prev = iletter - 1;
        if (cub->map->map_filled[istr][cub->map->line_end_prev] != '1')
            ft_exit(cub, WALL);
    }
    iletter = -1;
    istr--;
    while (cub->map->map_filled[istr][++iletter])
        if (cub->map->map_filled[istr][iletter] != '1')
                ft_exit(cub, WALL);
}