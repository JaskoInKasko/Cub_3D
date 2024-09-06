/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguliyev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:34:36 by iguliyev          #+#    #+#             */
/*   Updated: 2024/09/03 22:23:35 by iguliyev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D_bonus.h"

int	ft_x(t_game *cub)
{
	ft_exit(cub, X_CLOSE, EXIT_SUCCESS);
	return (0);
}

static void	ft_space_pressed(t_game *cub)
{
	int	x;
	int	y;

	x = (int)(cub->player.pos_x + cub->player.dir_x);
	y = (int)(cub->player.pos_y + cub->player.dir_y);
	if (cub->map.map_filled[y][x] == 'C')
		cub->map.map_filled[y][x] = 'O';
	else if (cub->map.map_filled[y][x] == 'O')
		cub->map.map_filled[y][x] = 'C';
}

	// system("aplay ./src/shoot.wav &");
static void	ft_f_pressed(t_game *cub)
{
	double	c_x;
	double	c_y;

	c_x = cub->player.pos_x;
	c_y = cub->player.pos_y;
	cub->flag.shoot_flag = 1;
	mlx_loop_hook(cub->mlx, ft_animation, cub);
	while (cub->map.map_filled[(int)c_y][(int)(c_x)] == '0'
		|| cub->map.map_filled[(int)c_y][(int)(c_x)] == 'O')
	{
		c_x = c_x + cub->player.dir_x;
		c_y = c_y + cub->player.dir_y;
	}
	if (cub->map.map_filled[(int)c_y][(int)(c_x)] == 'D')
		cub->map.map_filled[(int)c_y][(int)(c_x)] = '0';
}

int	ft_key_pressed(int keysym, t_game *cub)
{
	if (keysym == XK_w)
		move(cub, cub->player.dir_x, cub->player.dir_y);
	else if (keysym == XK_s)
		move(cub, -cub->player.dir_x, -cub->player.dir_y);
	else if (keysym == XK_a)
		move(cub, -cub->player.plane_x, -cub->player.plane_y);
	else if (keysym == XK_d)
		move(cub, cub->player.plane_x, cub->player.plane_y);
	else if (keysym == XK_Left)
		rotate(cub, -cub->angle);
	else if (keysym == XK_Right)
		rotate(cub, cub->angle);
	else if (keysym == XK_space)
		ft_space_pressed(cub);
	else if (keysym == XK_f)
		ft_f_pressed(cub);
	else if (keysym == XK_Escape)
		ft_exit(cub, ESC, EXIT_SUCCESS);
	else
		return (0);
	ft_draw(cub);
	return (0);
}
