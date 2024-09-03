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

void	ft_set_pistol_shoot(t_game *cub)
{
	char			*color;
	int				x;
	int				y;
	unsigned int	color_int;

	x = 0;
	y = 0;
	while (y < PISTOL_HEIGHT)
	{
		while (x < PISTOL_WIDTH)
		{
			color = cub->img.data_pistol_shoot
				+ (y * cub->img.pistol_line_length
					+ x * (cub->img.bpp / 8));
			color_int = *(unsigned int *)color;
			if (color_int != 0xFF000000)
				my_mlx_pixel_put(cub, x
					+ (SCREEN_WIDTH - PISTOL_WIDTH) / 2, y
					+ SCREEN_HEIGHT - PISTOL_HEIGHT, color_int);
			x++;
		}
		x = 0;
		y++;
	}
}

void	ft_set_pistol(t_game *cub)
{
	char			*color;
	int				x;
	int				y;
	unsigned int	color_int;

	x = 0;
	y = 0;
	while (y < PISTOL_HEIGHT)
	{
		while (x < PISTOL_WIDTH)
		{
			color = cub->img.data_pistol
				+ (y * cub->img.pistol_line_length
					+ x * (cub->img.bpp / 8));
			color_int = *(unsigned int *)color;
			if (color_int != 0xFF000000)
				my_mlx_pixel_put(cub, x + (SCREEN_WIDTH - PISTOL_WIDTH) / 2,
					y + SCREEN_HEIGHT - PISTOL_HEIGHT, color_int);
			x++;
		}
		x = 0;
		y++;
	}
}

void	ft_set_scope(t_game *cub)
{
	char			*color;
	int				x;
	int				y;
	unsigned int	color_int;

	x = 0;
	y = 0;
	while (y < SCOPE_HEIGHT)
	{
		while (x < SCOPE_WIDTH)
		{
			color = cub->img.data_scope + (y * cub->img.scope_line_length
					+ x * (cub->img.bpp / 8));
			color_int = *(unsigned int *)color;
			if (color_int != 0xFF000000)
				my_mlx_pixel_put(cub, x + (SCREEN_WIDTH - SCOPE_WIDTH) / 2,
					y + (SCREEN_HEIGHT - SCOPE_HEIGHT) / 2, color_int);
			x++;
		}
		x = 0;
		y++;
	}
}
