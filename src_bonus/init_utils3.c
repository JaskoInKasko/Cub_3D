/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguliyev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:43:38 by iguliyev          #+#    #+#             */
/*   Updated: 2024/09/03 22:23:10 by iguliyev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D_bonus.h"

static int	create_rgb(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

static void	get_addition_mapinfo_extended(t_game *cub, char *tmp, int i)
{
	if (!ft_strncmp(cub->map.map_info[i], "WE ", 3))
	{
		cub->map.west = ft_substr(tmp, cub->tmp.s_b, cub->tmp.s_a);
		if (cub->map.west == NULL)
			ft_exit(cub, MALLOC, EXIT_FAILURE);
	}
	else if (!ft_strncmp(cub->map.map_info[i], "EA ", 3))
	{
		cub->map.east = ft_substr(tmp, cub->tmp.s_b, cub->tmp.s_a);
		if (cub->map.east == NULL)
			ft_exit(cub, MALLOC, EXIT_FAILURE);
	}
	else if (!ft_strncmp(cub->map.map_info[i], "F ", 2)
		|| !ft_strncmp(cub->map.map_info[i], "C ", 2))
	{
		if (rgb_color_is_valid(cub, i) == 1)
			ft_exit(cub, TOKEN, EXIT_FAILURE);
		cub->tmp.i2 = 0;
		cub->tmp.i3 = 0;
		cub->tmp.n = 0;
		get_int_value(cub, i);
		check_rgb_int_value(cub);
	}
}

static void	get_rgb_color(t_game *cub)
{
	cub->map.f_color = create_rgb(cub->map.f_rgb[0], \
cub->map.f_rgb[1], cub->map.f_rgb[2]);
	cub->map.c_color = create_rgb(cub->map.c_rgb[0], \
cub->map.c_rgb[1], cub->map.c_rgb[2]);
}

static void	check_element_completness(t_game *cub)
{
	int	i;
	int	completness_flag;

	i = -1;
	completness_flag = 0;
	while (cub->map.map_info[++i])
	{
		if (!ft_strncmp(cub->map.map_info[i], "NO ", 3)
			|| !ft_strncmp(cub->map.map_info[i], "SO ", 3)
			|| !ft_strncmp(cub->map.map_info[i], "WE ", 3)
			|| !ft_strncmp(cub->map.map_info[i], "EA ", 3)
			|| !ft_strncmp(cub->map.map_info[i], "F ", 2)
			|| !ft_strncmp(cub->map.map_info[i], "C ", 2))
			completness_flag++;
	}
	if (completness_flag != 6)
		ft_exit(cub, ELEMENT, EXIT_FAILURE);
}

void	get_addition_mapinfo(t_game *cub)
{
	int		i;
	char	*tmp;

	i = -1;
	check_element_completness(cub);
	while (cub->map.map_info[++i])
	{
		if (line_is_valid(cub, i) == 1)
			ft_exit(cub, TOKEN, EXIT_FAILURE);
		tmp = cub->map.map_info[i];
		check_for_spaces(cub, i);
		if (!ft_strncmp(cub->map.map_info[i], "NO ", 3))
		{
			cub->map.north = ft_substr(tmp, cub->tmp.s_b, cub->tmp.s_a);
			if (cub->map.north == NULL)
				ft_exit(cub, MALLOC, EXIT_FAILURE);
		}
		else if (!ft_strncmp(cub->map.map_info[i], "SO ", 3))
		{
			cub->map.south = ft_substr(tmp, cub->tmp.s_b, cub->tmp.s_a);
			if (cub->map.south == NULL)
				ft_exit(cub, MALLOC, EXIT_FAILURE);
		}
		get_addition_mapinfo_extended(cub, tmp, i);
	}
	get_rgb_color(cub);
}
