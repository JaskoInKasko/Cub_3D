/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguliyev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 22:21:53 by iguliyev          #+#    #+#             */
/*   Updated: 2024/09/03 22:21:55 by iguliyev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

static void	ft_calculate_start_and_end_for_mini_part2(t_game *cub)
{
	if (cub->mini.end_x > cub->map.map_column + 1)
	{
		cub->mini.end_x = cub->map.map_column + 1;
		if (cub->map.map_column + 1 < MINIMAP_SIZE)
			cub->mini.start_x = 0;
		else
			cub->mini.start_x = cub->map.map_column + 1 - MINIMAP_SIZE;
	}
	if (cub->mini.end_y > cub->map.map_row + 1)
	{
		cub->mini.end_y = cub->map.map_row + 1;
		if (cub->map.map_row + 1 < MINIMAP_SIZE)
			cub->mini.start_y = 0;
		else
			cub->mini.start_y = cub->map.map_row + 1 - MINIMAP_SIZE;
	}
}

static void	ft_calculate_start_and_end_for_mini_part1(t_game *cub)
{
	cub->mini.start_x = cub->player.pos_x - (MINIMAP_SIZE / 2);
	cub->mini.start_y = cub->player.pos_y - (MINIMAP_SIZE / 2);
	cub->mini.end_x = cub->player.pos_x + (MINIMAP_SIZE / 2);
	cub->mini.end_y = cub->player.pos_y + (MINIMAP_SIZE / 2);
	if (cub->mini.start_x < 0)
	{
		cub->mini.start_x = 0;
		cub->mini.end_x = MINIMAP_SIZE;
	}
	if (cub->mini.start_y < 0)
	{
		cub->mini.start_y = 0;
		cub->mini.end_y = MINIMAP_SIZE;
	}
}

static void	ft_put_image_to_window_for_mini(t_game *cub)
{
	if ((int)cub->player.pos_x == cub->mini.start_x
		&& (int)cub->player.pos_y == cub->mini.start_y)
		mlx_put_image_to_window(cub->mlx, cub->win, cub->img.mini_player,
			cub->mini.x * MINI_TEX_WIDTH + SCREEN_WIDTH,
			cub->mini.y * MINI_TEX_HEIGHT + (SCREEN_HEIGHT / 2));
	else if (cub->map.map_filled[cub->mini.start_y][cub->mini.start_x] == '0'
		|| cub->map.map_filled[cub->mini.start_y][cub->mini.start_x] == 'O')
		mlx_put_image_to_window(cub->mlx, cub->win, cub->img.mini_floor,
			cub->mini.x * MINI_TEX_WIDTH + SCREEN_WIDTH,
			cub->mini.y * MINI_TEX_HEIGHT + (SCREEN_HEIGHT / 2));
	else if (cub->map.map_filled[cub->mini.start_y][cub->mini.start_x] != ' ')
		mlx_put_image_to_window(cub->mlx, cub->win, cub->img.mini_wall,
			cub->mini.x * MINI_TEX_WIDTH + SCREEN_WIDTH,
			cub->mini.y * MINI_TEX_HEIGHT + (SCREEN_HEIGHT / 2));
	else
		mlx_put_image_to_window(cub->mlx, cub->win, cub->img.mini_black,
			cub->mini.x * MINI_TEX_WIDTH + SCREEN_WIDTH,
			cub->mini.y * MINI_TEX_HEIGHT + (SCREEN_HEIGHT / 2));
}

void	ft_draw_mini(t_game *cub)
{
	if (!cub->flag.shoot_flag)
		ft_set_mini_background(cub);
	ft_calculate_start_and_end_for_mini_part1(cub);
	ft_calculate_start_and_end_for_mini_part2(cub);
	cub->mini.x = 0;
	cub->mini.y = 0;
	cub->mini.original_start_x = cub->mini.start_x;
	while (cub->map.map_filled[cub->mini.start_y]
		&& cub->mini.start_y < cub->mini.end_y)
	{
		cub->mini.start_x = cub->mini.original_start_x;
		while (cub->map.map_filled[cub->mini.start_y][cub->mini.start_x]
			&& cub->mini.start_x < cub->mini.end_x)
		{
			ft_put_image_to_window_for_mini(cub);
			cub->mini.x++;
			cub->mini.start_x++;
		}
		cub->mini.start_y++;
		cub->mini.x = 0;
		cub->mini.y++;
	}
}
