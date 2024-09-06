/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguliyev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 22:41:49 by iguliyev          #+#    #+#             */
/*   Updated: 2024/09/03 22:41:51 by iguliyev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D_bonus.h"

int	ft_mouse_move(int x, int y, t_game *cub)
{
	static int	last_x = SCREEN_WIDTH / 2;
	int			center_x;
	int			center_y;
	double		dx;

	(void)y;
	center_x = SCREEN_WIDTH / 2;
	center_y = SCREEN_HEIGHT / 2;
	dx = (double)(x - last_x) / 1000;
	if (dx != 0)
	{
		rotate(cub, dx);
		ft_draw(cub);
	}
	if (x != center_x)
	{
		mlx_mouse_move(cub->mlx, cub->win, center_x, center_y);
		last_x = center_x;
	}
	else
		last_x = x;
	return (0);
}

int	ft_mouse_click(int button, int x, int y, t_game *cub)
{
	double	c_x;
	double	c_y;

	(void)x;
	(void)y;
	if (button == 1)
	{
		c_x = cub->player.pos_x;
		c_y = cub->player.pos_y;
		while (cub->map.map_filled[(int)c_y][(int)(c_x)] == '0'
			|| cub->map.map_filled[(int)c_y][(int)(c_x)] == 'O')
		{
			c_x = c_x + cub->player.dir_x;
			c_y = c_y + cub->player.dir_y;
		}
		if (cub->map.map_filled[(int)c_y][(int)(c_x)] == 'D')
		{
			cub->map.map_filled[(int)c_y][(int)(c_x)] = '0';
			ft_draw(cub);
		}
	}
	return (0);
}
