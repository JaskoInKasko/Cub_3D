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
		ptr = NULL;
    }
}

void	ft_free_all(t_game *cub)
{
    ft_free(cub->map.line_cpy);
    ft_free(cub->map.mapline);
    ft_free_double(cub->map.map_filled);
    ft_free_double(cub->map.map_info);
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

void ft_destroy_single_img(t_game *cub, void *ptr)
{
	if(ptr)
	{
		mlx_destroy_image(cub->mlx, ptr);
		ptr = NULL;
	}
}

void ft_destroy_imgs(t_game *cub)
{
	ft_destroy_single_img(cub, cub->img.north);
	ft_destroy_single_img(cub, cub->img.south);
	ft_destroy_single_img(cub, cub->img.east);
	ft_destroy_single_img(cub, cub->img.west);
	ft_destroy_single_img(cub, cub->img.hitler);
	ft_destroy_single_img(cub, cub->img.door);
	ft_destroy_single_img(cub, cub->img.pistol);
    ft_destroy_single_img(cub, cub->img.pistol_shoot);
	ft_destroy_single_img(cub, cub->img.scope);
	ft_destroy_single_img(cub, cub->img.enemy);
	ft_destroy_single_img(cub, cub->img.mini_floor);
	ft_destroy_single_img(cub, cub->img.mini_wall);
	ft_destroy_single_img(cub, cub->img.mini_player);
    ft_destroy_single_img(cub, cub->img.mini_black);
	ft_destroy_single_img(cub, cub->img.img);
}

void    ft_exit(t_game *cub, char *msg, int exit_status)
{
    int fd;

    fd = 2;
    if (exit_status == EXIT_SUCCESS)
        fd = 1;
    ft_free_all(cub);
	ft_destroy_imgs(cub);
	ft_destroy_window_and_display(cub);
    if (msg)
        write(fd, msg, ft_strlen(msg));
    exit(exit_status);
}