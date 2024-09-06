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

void	my_mlx_pixel_put(t_game *cub, int x, int y, int color)
{
	char	*dst;

	dst = cub->img.addr
		+ (y * cub->img.line_length + x * (cub->img.bpp / 8));
	*(unsigned int *)dst = color;
}

void	ft_set_screen(t_game *cub)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (++x < SCREEN_WIDTH)
	{
		cub->ray.camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
		ft_calculate_vars_values_for_draw_part1(cub);
		ft_find_hit_point(cub);
		ft_calculate_vars_values_for_draw_part2(cub);
		y = cub->ray.draw_start;
		while (y < cub->ray.draw_end)
		{
			ft_define_pixel_color_for_draw(cub, y);
			my_mlx_pixel_put(cub, x, y, cub->ray.color_int);
			y++;
		}
	}
}
