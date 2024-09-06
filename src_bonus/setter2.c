/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setter2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguliyev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 22:24:31 by iguliyev          #+#    #+#             */
/*   Updated: 2024/09/03 22:24:33 by iguliyev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D_bonus.h"

void	ft_set_text(t_game *cub)
{
	mlx_string_put(cub->mlx, cub->win,
		SCREEN_WIDTH + 15, 20, 0x00FFFFFF, "Welcome to Cub3D!");
	mlx_string_put(cub->mlx, cub->win,
		SCREEN_WIDTH + 15, 60, 0x00FFFFFF, "Controls:");
	mlx_string_put(cub->mlx, cub->win,
		SCREEN_WIDTH + 15, 80, 0x00FFFFFF, "Move: W, A, S, D or Mouse");
	mlx_string_put(cub->mlx, cub->win,
		SCREEN_WIDTH + 15, 100, 0x00FFFFFF, "Rotate: Left Arrow, Right Arrow");
	mlx_string_put(cub->mlx, cub->win,
		SCREEN_WIDTH + 15, 120, 0x00FFFFFF, "Exit: ESC or X Button");
	mlx_string_put(cub->mlx, cub->win,
		SCREEN_WIDTH + 15, 140, 0x00FFFFFF, "Shoot: F or Right Click");
	mlx_string_put(cub->mlx, cub->win,
		SCREEN_WIDTH + 15, 160, 0x00FFFFFF, "Open Door: Space");
	mlx_string_put(cub->mlx, cub->win,
		SCREEN_WIDTH + 15, 180, 0x00FFFFFF, "Close Door: Space");
	mlx_string_put(cub->mlx, cub->win,
		SCREEN_WIDTH + 15, 200, 0x00FFFFFF, "Enjoy the game!");
	mlx_string_put(cub->mlx, cub->win,
		SCREEN_WIDTH + 15, SCREEN_HEIGHT / 2 - 10, 0x00FFFFFF,
		"@ Ismayil && Jasmin");
}

static void	ft_pixel_put_background(t_game *cub, int x, int y, int color)
{
	int	m;
	int	n;

	m = 0;
	while (m < 10)
	{
		n = 0;
		while (n < 10)
		{
			my_mlx_pixel_put(cub, x + n, y + m, color);
			n++;
		}
		m++;
	}
}

void	ft_set_mini_background(t_game *cub)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < MINIMAP_SIZE)
	{
		while (x < MINIMAP_SIZE)
		{
			ft_pixel_put_background(cub, x * MINI_TEX_WIDTH + SCREEN_WIDTH,
				y * MINI_TEX_HEIGHT + (SCREEN_HEIGHT / 2), 0x000000);
			x++;
		}
		x = 0;
		y++;
	}
}

void	ft_set_background(t_game *cub)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (++y < SCREEN_HEIGHT)
	{
		if (y < SCREEN_HEIGHT / 2)
		{
			while (++x < SCREEN_WIDTH)
				my_mlx_pixel_put(cub, x, y, cub->map.c_color);
		}
		else
		{
			while (++x < SCREEN_WIDTH)
				my_mlx_pixel_put(cub, x, y, cub->map.f_color);
		}
		x = 0;
	}
}

	// if (cub->ray.side == 1)
	// 	cub->ray.color_int = (cub->ray.color_int >> 1) & 8355711;
	// Give x and y sides different brightness
	// if (cub->ray.side == 1) { cub->ray.color_int = cub->ray.color_int / 2; }
void	ft_define_pixel_color_for_draw(t_game *cub, int y)
{
	cub->ray.tex_y = (((y * 256 - SCREEN_HEIGHT * 128 + cub->ray.line_height
					* 128) * TEXTURE_HEIGHT) / cub->ray.line_height) / 256;
	if (cub->map.map_filled[cub->ray.map_y][cub->ray.map_x] == 'D')
		cub->ray.color = cub->img.data_enemy + (cub->ray.tex_y
				* cub->img.t_line_len + cub->ray.tex_x * (cub->img.bpp / 8));
	else if (cub->map.map_filled[cub->ray.map_y][cub->ray.map_x] == 'C')
		cub->ray.color = cub->img.data_door + (cub->ray.tex_y
				* cub->img.t_line_len + cub->ray.tex_x * (cub->img.bpp / 8));
	else if (cub->ray.side == 1 && cub->ray.ray_dir_y > 0)
		cub->ray.color = cub->img.data_south + (cub->ray.tex_y
				* cub->img.t_line_len + cub->ray.tex_x * (cub->img.bpp / 8));
	else if (cub->ray.side == 1 && cub->ray.ray_dir_y < 0)
		cub->ray.color = cub->img.data_north + (cub->ray.tex_y
				* cub->img.t_line_len + cub->ray.tex_x * (cub->img.bpp / 8));
	else if (cub->ray.side == 0 && cub->ray.ray_dir_x > 0)
		cub->ray.color = cub->img.data_east + (cub->ray.tex_y
				* cub->img.t_line_len + cub->ray.tex_x * (cub->img.bpp / 8));
	else if (cub->map.map_filled[cub->ray.map_y][cub->ray.map_x] == 'H')
		cub->ray.color = cub->img.data_paper + (cub->ray.tex_y
				* cub->img.t_line_len + cub->ray.tex_x * (cub->img.bpp / 8));
	else if (cub->ray.side == 0 && cub->ray.ray_dir_x < 0
		&& cub->map.map_filled[cub->ray.map_y][cub->ray.map_x] == '1')
		cub->ray.color = cub->img.data_west + (cub->ray.tex_y
				* cub->img.t_line_len + cub->ray.tex_x * (cub->img.bpp / 8));
	cub->ray.color_int = *(unsigned int *)cub->ray.color;
}
