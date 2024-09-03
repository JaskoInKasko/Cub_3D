/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguliyev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:01:36 by iguliyev          #+#    #+#             */
/*   Updated: 2024/09/03 22:23:57 by iguliyev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

void	ft_dir_help(t_game *cub, double plane_x, double plane_y)
{
	cub->player.plane_x = plane_x;
	cub->player.plane_y = plane_y;
}

void	ft_define_direction(t_game *cub, char c)
{
	if (c == 'N')
	{
		cub->player.dir_x = 0;
		cub->player.dir_y = -1;
		ft_dir_help(cub, 0.66, 0);
	}
	else if (c == 'S')
	{
		cub->player.dir_x = 0;
		cub->player.dir_y = 1;
		ft_dir_help(cub, -0.66, 0);
	}
	else if (c == 'W')
	{
		cub->player.dir_x = -1;
		cub->player.dir_y = 0;
		ft_dir_help(cub, 0, -0.66);
	}
	else if (c == 'E')
	{
		cub->player.dir_x = 1;
		cub->player.dir_y = 0;
		ft_dir_help(cub, 0, 0.66);
	}
}

int	map_content_loop(t_game *cub, int i, int i2, int full_content)
{
	while (cub->map.map_filled[++i])
	{
		while (cub->map.map_filled[i][++i2])
		{
			if (cub->map.map_filled[i][i2] == '1' && full_content == 0)
				full_content = 1;
			if (cub->map.map_filled[i][i2] == 'N'
					|| cub->map.map_filled[i][i2] == 'S'
					|| cub->map.map_filled[i][i2] == 'E'
					|| cub->map.map_filled[i][i2] == 'W')
			{
				if (full_content == 1)
					full_content = 2;
				if (cub->player.pos_x != 0 || cub->player.pos_y != 0)
					ft_exit(cub, PLAYER, EXIT_FAILURE);
				ft_define_direction(cub, cub->map.map_filled[i][i2]);
				cub->player.pos_x = i2 + 0.51;
				cub->player.pos_y = i + 0.51;
				cub->map.map_filled[i][i2] = '0';
			}
		}
		i2 = -1;
	}
	return (full_content);
}

void	check_map_content(t_game *cub)
{
	int	i;
	int	i2;
	int	full_content;

	i = -1;
	i2 = -1;
	full_content = 0;
	full_content = map_content_loop(cub, i, i2, full_content);
	if (full_content != 2)
		ft_exit(cub, MAP_SIZE, EXIT_FAILURE);
}
