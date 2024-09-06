/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits_allocs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguliyev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:26:44 by iguliyev          #+#    #+#             */
/*   Updated: 2024/09/03 22:23:23 by iguliyev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D_bonus.h"

void	check_for_spaces(t_game *cub, int i)
{
	int	i2;

	cub->tmp.s_b = 0;
	cub->tmp.s_a = 0;
	i2 = 0;
	while (cub->map.map_info[i][i2] != ' ')
		i2++;
	while (cub->map.map_info[i][i2] == ' ')
		i2++;
	cub->tmp.s_b = i2;
	while (cub->map.map_info[i][++i2] && cub->map.map_info[i][i2] != ' ')
		cub->tmp.s_a++;
	cub->tmp.s_a++;
}

int	rgb_color_is_valid(t_game *cub, int i)
{
	int		i2;
	int		colon;
	char	*tmp;

	i2 = 1;
	colon = 0;
	tmp = cub->map.map_info[i];
	while (tmp[++i2])
	{
		if (!((tmp[i2] >= '0' && tmp[i2] <= '9')
				|| tmp[i2] == ',' || tmp[i2] == ' '))
			return (1);
		if (tmp[i2] == ',')
			colon++;
	}
	if (colon != 2)
		return (1);
	return (0);
}

void	check_rgb_int_value(t_game *cub)
{
	int	i;

	i = -1;
	while (++i < 3)
	{
		if ((cub->map.f_rgb[i] < 0 || cub->map.f_rgb[i] > 255)
			|| (cub->map.c_rgb[i] < 0 || cub->map.c_rgb[i] > 255))
			ft_exit(cub, RGB, EXIT_FAILURE);
	}
}

void	init_structs(t_game *cub, char *argv[])
{
	cub->map.map_name = argv[1];
	cub->angle = M_PI / 64;
	get_cubfile_info(cub);
	get_addition_mapinfo(cub);
}
