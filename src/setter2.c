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

#include "../includes/Cub3D.h"

void	my_mlx_pixel_put(t_game *cub, int x, int y, int color)
{
	char	*dst;

	dst = cub->img.addr
		+ (y * cub->img.line_length + x * (cub->img.bpp / 8));
	*(unsigned int *)dst = color;
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
