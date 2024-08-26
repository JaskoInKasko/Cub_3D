#include "../includes/Cub3D.h"

void ft_free(char *ptr)
{
    if(ptr)
    {
        free(ptr);
        ptr = NULL;
    }
}

void ft_free_double(char **ptr)
{
    int i;

    i = -1;
    if(ptr)
    {
        while(ptr[++i])
            ft_free(ptr[i]);
        free(ptr);
    }
}

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

void	ft_free_all(t_game *cub)
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
                
void	ft_destroy_window_and_display(t_game *cub)
{
	if (cub->mlx != NULL && cub->win != NULL)
	{
		mlx_destroy_window(cub->mlx, cub->win);
		cub->win = NULL;
		mlx_destroy_display(cub->mlx);
		free(cub->mlx);
		cub->mlx = NULL;
	}
	else if (cub->mlx != NULL)
	{
		mlx_destroy_display(cub->mlx);
		free(cub->mlx);
		cub->mlx = NULL;
	}
}

void    ft_exit(t_game *cub, char *msg, int exit_status)
{
    int fd;
    // int exit_code;

    // exit_code = 0;
    fd = 2;
    //if(cub->flag->success_flag == TRUE)
    if (exit_status == EXIT_SUCCESS)
    {
        fd = 1;
        // exit_code = 1;
    }
    ft_free_all(cub);
	ft_destroy_window_and_display(cub);
    if (msg)
        write(fd, msg, ft_strlen(msg));
    exit(exit_status);
}