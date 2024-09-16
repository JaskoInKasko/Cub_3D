/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:08:14 by iguliyev          #+#    #+#             */
/*   Updated: 2024/09/16 17:20:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

int	get_mapline_begin(t_game *cub, int i, int i2)
{
	int	begin;

	begin = 0;
	while (cub->map.map_filled[i][++i2] == ' '
		&& cub->map.map_filled[i][i2] != '\0')
		begin++;
	if (cub->map.map_filled[i][i2] == '\0'
		|| cub->map.map_filled[i][i2] != '1')
		ft_exit(cub, ERROR, EXIT_FAILURE);
	return (begin);
}

static void	check_surroundings(t_game *cub, int i, int i2)
{
	if (i == 0 || (i > 0 && cub->map.map_filled[i - 1]
			&& (i2 >= (int)ft_strlen(cub->map.map_filled[i - 1])
				|| !cub->map.map_filled[i - 1][i2]
			|| cub->map.map_filled[i - 1][i2] == ' ')))
		ft_exit(cub, ERROR, EXIT_FAILURE);
	else if (!cub->map.map_filled[i + 1] || (cub->map.map_filled[i + 1]
			&& (i2 >= (int)ft_strlen(cub->map.map_filled[i + 1])
				|| !cub->map.map_filled[i + 1][i2]
			|| cub->map.map_filled[i + 1][i2] == ' ')))
		ft_exit(cub, ERROR, EXIT_FAILURE);
	else if (!cub->map.map_filled[i][i2 + 1]
			|| cub->map.map_filled[i][i2 + 1] == '\0')
		ft_exit(cub, ERROR, EXIT_FAILURE);
	else if (!cub->map.map_filled[i][i2 - 1]
			|| cub->map.map_filled[i][i2 - 1] == ' ')
		ft_exit(cub, ERROR, EXIT_FAILURE);
}

void	loop_through_map(t_game *cub, int i, int i2)
{
	while (cub->map.map_filled[i][++i2])
	{
		if (cub->map.map_filled[i][i2] == '0'
			|| cub->map.map_filled[i][i2] == 'N'
			|| cub->map.map_filled[i][i2] == 'S'
			|| cub->map.map_filled[i][i2] == 'E'
			|| cub->map.map_filled[i][i2] == 'W')
			check_surroundings(cub, i, i2);
	}
}

void	check_map_walls(t_game *cub)
{
	int	i;
	int	i2;
	int	begin;

	i = -1;
	while (cub->map.map_filled[++i])
	{
		i2 = -1;
		begin = get_mapline_begin(cub, i, i2);
		i2 = begin--;
		while (cub->map.map_filled[0][++begin])
			if (cub->map.map_filled[0][begin] == '0')
				ft_exit(cub, ERROR, EXIT_FAILURE);
		loop_through_map(cub, i, i2 - 1);
	}
}
