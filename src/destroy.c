/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguliyev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 22:33:40 by iguliyev          #+#    #+#             */
/*   Updated: 2024/09/03 22:33:42 by iguliyev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

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

void	ft_destroy_single_img(t_game *cub, void *ptr)
{
	if (ptr)
	{
		mlx_destroy_image(cub->mlx, ptr);
		ptr = NULL;
	}
}

void	ft_destroy_imgs(t_game *cub)
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
