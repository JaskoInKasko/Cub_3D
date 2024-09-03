#include "../includes/Cub3D.h"

void	init_structs(t_game *cub, char *argv[])
{
	cub->map.map_name = argv[1];
    // cub->player.dirX = -1;
    // cub->player.dirY = 0;
    // cub->player.planeX = 0;
    // cub->player.planeY = 1;
	get_cubfile_info(cub);
	get_addition_mapinfo(cub);
}