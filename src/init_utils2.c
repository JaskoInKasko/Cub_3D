/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:43:33 by iguliyev          #+#    #+#             */
/*   Updated: 2024/09/14 19:07:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

int	has_tab(char *line)
{
	while (*line != '\0')
	{
		if (*line == '\t')
			return (0);
		line++;
	}
	return (1);
}

static int	is_map_line(const char *line)
{
	if (*line != '1' && *line != '0' && *line != 'N'
		&& *line != 'S' && *line != 'W' && *line != 'E'
		&& *line != ' ')
		return (1);
	line++;
	while (*(line) != '\0' && *(line + 1) != '\n')
	{
		if (*line != '1' && *line != '0' && *line != 'N'
			&& *line != 'S' && *line != 'W' && *line != 'E'
			&& *line != ' ')
			return (1);
		line++;
	}
	return (0);
}

void	join_fileinfo(t_game *cub, char *line)
{
	if (is_map_line(line) == 0)
	{
		cub->map.mapline = ft_strjoin_free(cub->map.mapline, line);
		cub->flag.mapline_flag = 1;
	}
	else
	{
		if (cub->flag.mapline_flag == 1)
		{
			free(line);
			ft_exit(cub, ERROR, EXIT_FAILURE);
		}
		cub->map.line_cpy = ft_strjoin_free(cub->map.line_cpy, line);
	}
	if (!cub->map.line_cpy || !cub->map.mapline)
	{
		free(line);
		ft_exit(cub, STRJOIN, EXIT_FAILURE);
	}
}

int	line_is_valid(t_game *cub, int i)
{
	int		i2;
	char	**tmp;

	tmp = ft_split(cub->map.map_info[i], ' ');
	if (!tmp)
		ft_exit(cub, MALLOC, EXIT_FAILURE);
	i2 = -1;
	while (tmp[++i2])
		if (i2 > 1)
			return (ft_free_double(tmp), 1);
	if (i2 == 1)
		return (ft_free_double(tmp), 1);
	ft_free_double(tmp);
	return (0);
}

void	get_int_value(t_game *cub, int i)
{
	char	*tmp;

	tmp = cub->map.map_info[i];
	while (tmp[cub->tmp.i2] && tmp[cub->tmp.i2] == ' ')
		cub->tmp.i2++;
	cub->tmp.i2++;
	while (tmp[cub->tmp.i2] && tmp[cub->tmp.i2] == ' ')
		cub->tmp.i2++;
	while (tmp[cub->tmp.i2])
	{
		if (tmp[cub->tmp.i2] >= '0' && tmp[cub->tmp.i2] <= '9')
			cub->tmp.n = cub->tmp.n + tmp[cub->tmp.i2] - 48;
		if (tmp[cub->tmp.i2 + 1] >= '0' && tmp[cub->tmp.i2 + 1] <= '9')
			cub->tmp.n *= 10;
		if (tmp[cub->tmp.i2 + 1] == ',' || tmp[cub->tmp.i2 + 1] == '\0')
		{
			if (!ft_strncmp(cub->map.map_info[i], "F ", 2))
				cub->map.f_rgb[cub->tmp.i3] = cub->tmp.n;
			else if (!ft_strncmp(cub->map.map_info[i], "C ", 2))
				cub->map.c_rgb[cub->tmp.i3] = cub->tmp.n;
			cub->tmp.i3++;
			cub->tmp.n = 0;
		}
		cub->tmp.i2++;
	}
}
