#include "../includes/Cub3D.h"

void err_msg(t_game *cub, char *msg)
{
    ft_putstr_fd(msg, 2);
}

void	free_dir(char **dir)
{
    int i;

    i = -1;
	if (dir)
	{
		while(dir[++i])
			free(dir[i]);
		free(dir);
	}
}

void    ft_free(t_game *cub)
{
    int i;

    i = -1;
    if (cub->map->line_cpy)
        free(cub->map->line_cpy);
    if (cub->map->mapline)
        free(cub->map->mapline);
    if (cub->map->map_filled)
    {
        while(cub->map->map_filled[++i])
            free(cub->map->map_filled[i]);
        free(cub->map->map_filled);
    }
    if (cub->map->map_info)
    {
        i = -1;
        while(cub->map->map_info[++i])
            free(cub->map->map_info[i]);
        free(cub->map->map_info);
    }
    if (cub->map)
        free(cub->map);
    if (cub->ad_map)
        free(cub->ad_map);
}

void    ft_exit(t_game *cub, char *msg)
{
    err_msg(cub, msg);
    ft_free(cub);
    exit(EXIT_FAILURE);
}