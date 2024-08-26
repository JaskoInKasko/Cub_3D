#include "../includes/Cub3D.h"

void	alloc_structs(t_game *cub)
{
	cub->map = (t_map_data *)malloc(sizeof(t_map_data));
	if (!cub->map)
		ft_exit(cub, MALLOC, EXIT_FAILURE);
	cub->ad_map = (t_addidtion_map_info *)malloc(sizeof(t_addidtion_map_info));
	if (!cub->ad_map)
		ft_exit(cub, MALLOC, EXIT_FAILURE);
}

void	init_structs(t_game *cub, char *argv[])
{
	cub->map->map_name = argv[1];
    cub->player.dirX = -1;
    cub->player.dirY = 0;
    cub->player.planeX = 0;
    cub->player.planeY = 1;
	get_cubfile_info(cub);
	fill_list(cub);
}