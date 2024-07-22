#include "../includes/Cub3D.h"

void    ft_free(t_game *cub)
{
    if (cub->map)
        free(cub->map);
    if (cub->ad_map)
        free(cub->ad_map);
    if (cub->map->line_cpy)
        free(cub->map->line_cpy);
    if (cub->map->map_line)
        free(cub->map->map_line);
}

void    ft_exit(t_game *cub)
{
    ft_free(cub);
    exit(EXIT_FAILURE);
}