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

#include "../includes/Cub3D.h"

int	ft_x(t_game *cub)
{
	ft_exit(cub, X_CLOSE, EXIT_SUCCESS);
	return (0);
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
	else if (keysym == XK_Escape)
		ft_exit(cub, ESC, EXIT_SUCCESS);
	else
		return (0);
	ft_draw(cub);
	return (0);
}
