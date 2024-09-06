/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguliyev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 22:38:51 by iguliyev          #+#    #+#             */
/*   Updated: 2024/09/03 22:38:53 by iguliyev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D_bonus.h"

void	rotate(t_game *cub, double angle)
{
	double	old_dir_x;
	double	old_dir_y;
	double	old_plane_x;
	double	old_plane_y;

	old_dir_x = cub->player.dir_x;
	old_dir_y = cub->player.dir_y;
	old_plane_x = cub->player.plane_x;
	old_plane_y = cub->player.plane_y;
	cub->player.dir_x = old_dir_x * cos(angle) - old_dir_y * sin(angle);
	cub->player.dir_y = old_dir_x * sin(angle) + old_dir_y * cos(angle);
	cub->player.plane_x = old_plane_x * cos(angle) - old_plane_y * sin(angle);
	cub->player.plane_y = old_plane_x * sin(angle) + old_plane_y * cos(angle);
}

static void	ft_calculate_vars_continous(t_game *cub, double dx, double dy)
{
	cub->ray.side_dist_x = (cub->ray.map_x + 1.0 - cub->player.pos_x)
		* cub->ray.delta_dist_x;
	cub->ray.side_dist_y = (cub->ray.map_y + 1.0 - cub->player.pos_y)
		* cub->ray.delta_dist_y;
	if (dx < 0)
	{
		cub->ray.step_x = -1;
		cub->ray.side_dist_x = (cub->player.pos_x - cub->ray.map_x)
			* cub->ray.delta_dist_x;
	}
	if (dy < 0)
	{
		cub->ray.step_y = -1;
		cub->ray.side_dist_y = (cub->player.pos_y - cub->ray.map_y)
			* cub->ray.delta_dist_y;
	}
}

static void	ft_calculate_vars_values_for_move(t_game *cub, double dx, double dy)
{
	cub->ray.new_x = cub->player.pos_x + dx * SPEED;
	cub->ray.new_y = cub->player.pos_y + dy * SPEED;
	cub->ray.step_x = 1;
	cub->ray.step_y = 1;
	cub->ray.hit = 0;
	cub->ray.map_x = (int)cub->player.pos_x;
	cub->ray.map_y = (int)cub->player.pos_y;
	if (dx == 0)
		cub->ray.delta_dist_x = 1e30;
	else
		cub->ray.delta_dist_x = fabs(1.0 / dx);
	if (dy == 0)
		cub->ray.delta_dist_y = 1e30;
	else
		cub->ray.delta_dist_y = fabs(1.0 / dy);
	ft_calculate_vars_continous(cub, dx, dy);
}

static void	ft_check_if_move_is_possible(t_game *cub)
{
	while (!cub->ray.hit)
	{
		if (cub->ray.side_dist_x < cub->ray.side_dist_y)
		{
			if (cub->ray.side_dist_x >= SPEED + 0.2)
				break ;
			cub->ray.side_dist_x += cub->ray.delta_dist_x;
			cub->ray.map_x += cub->ray.step_x;
		}
		else
		{
			if (cub->ray.side_dist_y >= SPEED + 0.2)
				break ;
			cub->ray.side_dist_y += cub->ray.delta_dist_y;
			cub->ray.map_y += cub->ray.step_y;
		}
		if (cub->map.map_filled[cub->ray.map_y][cub->ray.map_x] != '0'
			&& cub->map.map_filled[cub->ray.map_y][cub->ray.map_x] != 'O')
		{
			cub->ray.hit = 1;
		}
	}
}

void	move(t_game *cub, double dx, double dy)
{
	ft_calculate_vars_values_for_move(cub, dx, dy);
	ft_check_if_move_is_possible(cub);
	if (!cub->ray.hit)
	{
		cub->player.pos_x = cub->ray.new_x;
		cub->player.pos_y = cub->ray.new_y;
	}
}
