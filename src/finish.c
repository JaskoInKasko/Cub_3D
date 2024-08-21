#include "../includes/Cub3D.h"

void err_msg(t_game *cub, char *msg)
{
    (void)cub;
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

static void	ft_free_extend(t_game *cub)
{
    int i;

    i = -1;
    if (cub->map->map_filled)
    {
        while(cub->map->map_filled[++i])
        {
            free(cub->map->map_filled[i]);
            cub->map->map_filled[i] = NULL;
        }
        free(cub->map->map_filled);
        cub->map->map_filled = NULL;
    }
    if (cub->map->map_info)
    {
        i = -1;
        while(cub->map->map_info[++i])
        {
            free(cub->map->map_info[i]);
            cub->map->map_info[i] = NULL;
        }
        free(cub->map->map_info);
        cub->map->map_info = NULL;
    }
}

void	ft_free(t_game *cub)
{
    if (cub->map->line_cpy)
    {
        free(cub->map->line_cpy);
        cub->map->line_cpy = NULL;

    }
    if (cub->map->mapline)
    {
        free(cub->map->mapline);
        cub->map->mapline = NULL;
    }
	ft_free_extend(cub);
    if (cub->map)
    {
        free(cub->map);
        cub->map = NULL;
    }
    if (cub->ad_map)
    {
        free(cub->ad_map);
        cub->ad_map = NULL;
    }
}

void    ft_exit(t_game *cub, char *msg)
{
    err_msg(cub, msg);
    ft_free(cub);
    exit(EXIT_FAILURE);
}