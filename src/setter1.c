/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setter1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguliyev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 18:51:10 by iguliyev          #+#    #+#             */
/*   Updated: 2024/09/03 22:24:25 by iguliyev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

static void	ft_helper_for_set_screen(t_game *cub, int a, int x, int color_int)
{
	a = cub->ray.draw_end - 1;
	if (cub->ray.draw_end != SCREEN_HEIGHT - 1)
	{
		while (a++ <= SCREEN_HEIGHT - 1)
			my_mlx_pixel_put(cub, x, a, color_int);
	}
}

void	ft_set_screen(t_game *cub)
{
	int	x;
	int	y;
	int	a;

	x = -1;
	y = -1;
	a = -1;
	while (++x < SCREEN_WIDTH)
	{
		a = -1;
		cub->ray.camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
		ft_calculate_vars_values_for_draw_part1(cub);
		ft_find_hit_point(cub);
		ft_calculate_vars_values_for_draw_part2(cub);
		y = cub->ray.draw_start;
		while (++a < cub->ray.draw_start)
			my_mlx_pixel_put(cub, x, a, cub->map.c_color);
		while (y <= cub->ray.draw_end)
		{
			ft_define_pixel_color_for_draw(cub, y);
			my_mlx_pixel_put(cub, x, y, cub->ray.color_int);
			y++;
		}
		ft_helper_for_set_screen(cub, a, x, cub->map.f_color);
	}
}
