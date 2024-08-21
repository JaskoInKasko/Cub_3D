#include "../includes/Cub3D.h"

void	alloc_structs(t_game *cub)
{
	cub->map = (t_map_data *)malloc(sizeof(t_map_data));
	cub->ad_map = (t_addidtion_map_info *)malloc(sizeof(t_addidtion_map_info));
	cub->player = (t_player *)malloc(sizeof(t_player));
	if (!cub->map || !cub->ad_map || !cub->player)
		ft_exit(cub, MALLOC);
}

void	init_structs(t_game *cub, char *argv[])
{
    cub->mapline_flag = 0;

	cub->map->fd = 0;
	cub->map->line_cpy = NULL;
	cub->map->map_filled = NULL;
	cub->map->map_name = argv[1];
    cub->map->mapline = NULL;
    cub->map->map_info = NULL;
	cub->map->line_begin_prev = 0;
	cub->map->line_end_prev = 0;
	cub->map->line_begin_cur = 0;

	cub->ad_map->direction = NULL;
    cub->ad_map->texture_path = NULL;
	cub->ad_map->rgb_color = NULL;
	get_cubfile_info(cub);
	fill_list(cub);
}