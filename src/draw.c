/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:53:13 by iguliyev          #+#    #+#             */
/*   Updated: 2024/09/07 23:40:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

static void	ft_draw_part1_continuous(t_game *cub)
{
	if (cub->ray.ray_dir_x == 0)
		cub->ray.delta_dist_x = 1e30;
	if (cub->ray.ray_dir_y == 0)
		cub->ray.delta_dist_y = 1e30;
	if (cub->ray.ray_dir_x < 0)
	{
		cub->ray.step_x = -1;
		cub->ray.side_dist_x = (cub->player.pos_x - cub->ray.map_x)
			* cub->ray.delta_dist_x;
	}
	if (cub->ray.ray_dir_y < 0)
	{
		cub->ray.step_y = -1;
		cub->ray.side_dist_y = (cub->player.pos_y - cub->ray.map_y)
			* cub->ray.delta_dist_y;
	}
}

void	ft_calculate_vars_values_for_draw_part1(t_game *cub)
{
	cub->ray.ray_dir_x = cub->player.dir_x
		+ cub->player.plane_x * cub->ray.camera_x;
	cub->ray.ray_dir_y = cub->player.dir_y
		+ cub->player.plane_y * cub->ray.camera_x;
	cub->ray.map_x = (int)cub->player.pos_x;
	cub->ray.map_y = (int)cub->player.pos_y;
	cub->ray.delta_dist_x = fabs(1.0 / cub->ray.ray_dir_x);
	cub->ray.delta_dist_y = fabs(1.0 / cub->ray.ray_dir_y);
	cub->ray.step_x = 1;
	cub->ray.step_y = 1;
	cub->ray.side_dist_x = (cub->ray.map_x + 1.0 - cub->player.pos_x)
		* cub->ray.delta_dist_x;
	cub->ray.side_dist_y = (cub->ray.map_y + 1.0 - cub->player.pos_y)
		* cub->ray.delta_dist_y;
	ft_draw_part1_continuous(cub);
}

void	ft_find_hit_point(t_game *cub)
{
	cub->ray.hit = 0;
	while (cub->map.map_filled[cub->ray.map_y][cub->ray.map_x]
			&& cub->ray.hit == 0)
	{
		if (cub->ray.side_dist_x < cub->ray.side_dist_y)
		{
			cub->ray.side_dist_x += cub->ray.delta_dist_x;
			cub->ray.map_x += cub->ray.step_x;
			cub->ray.side = 0;
		}
		else
		{
			cub->ray.side_dist_y += cub->ray.delta_dist_y;
			cub->ray.map_y += cub->ray.step_y;
			cub->ray.side = 1;
		}
		if (cub->map.map_filled[cub->ray.map_y][cub->ray.map_x] != '0'
				&& cub->map.map_filled[cub->ray.map_y][cub->ray.map_x] != 'O')
			cub->ray.hit = 1;
	}
}

// Reverse texture, ters gorune biler bunsuz, son iki if conditions
void	ft_calculate_vars_values_for_draw_part2(t_game *cub)
{
	if (cub->ray.side == 0)
		cub->ray.perp_wall_dist = (cub->ray.map_x - cub->player.pos_x
				+ (1.0 - cub->ray.step_x) / 2) / cub->ray.ray_dir_x;
	else
		cub->ray.perp_wall_dist = (cub->ray.map_y - cub->player.pos_y
				+ (1.0 - cub->ray.step_y) / 2) / cub->ray.ray_dir_y;
	cub->ray.line_height = (int)(SCREEN_HEIGHT / cub->ray.perp_wall_dist);
	cub->ray.draw_start = -cub->ray.line_height / 2 + SCREEN_HEIGHT / 2;
	if (cub->ray.draw_start < 0)
		cub->ray.draw_start = 0;
	cub->ray.draw_end = cub->ray.line_height / 2 + SCREEN_HEIGHT / 2;
	if (cub->ray.draw_end >= SCREEN_HEIGHT)
		cub->ray.draw_end = SCREEN_HEIGHT - 1;
	if (cub->ray.side == 0)
		cub->ray.wall_x = cub->player.pos_y
			+ cub->ray.perp_wall_dist * cub->ray.ray_dir_y;
	else
		cub->ray.wall_x = cub->player.pos_x
			+ cub->ray.perp_wall_dist * cub->ray.ray_dir_x;
	cub->ray.wall_x -= floor(cub->ray.wall_x);
	cub->ray.tex_x = (int)(cub->ray.wall_x * (double)TEXTURE_WIDTH);
	if (cub->ray.side == 0 && cub->ray.ray_dir_x > 0)
		cub->ray.tex_x = TEXTURE_WIDTH - cub->ray.tex_x - 1;
	if (cub->ray.side == 1 && cub->ray.ray_dir_y < 0)
		cub->ray.tex_x = TEXTURE_WIDTH - cub->ray.tex_x - 1;
}

void	ft_draw(t_game *cub)
{
	ft_set_background(cub);
	ft_set_screen(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img.img, 0, 0);
}
