/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:19:11 by iguliyev          #+#    #+#             */
/*   Updated: 2024/09/16 17:21:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

static void	split_and_close(t_game *cub)
{
	int	flag;

	flag = 0;
	cub->map.map_filled = ft_split(cub->map.mapline, '\n');
	cub->map.map_info = ft_split(cub->map.line_cpy, '\n');
	if (!cub->map.map_filled || !cub->map.map_info)
	{
		ft_exit(cub, SPLIT, EXIT_FAILURE);
	}
	flag = close(cub->map.fd);
	if (flag < 0)
		ft_exit(cub, CLOSE, EXIT_FAILURE);
	cub->flag.close_flag = 1;
}

static void	check_map_size(t_game *cub)
{
	int	mapsize;
	int	i;
	int	i2;

	i = -1;
	i2 = -1;
	mapsize = 0;
	while (cub->map.map_filled[++i])
	{
		cub->map.map_row = i;
		mapsize++;
		while (cub->map.map_filled[i][++i2])
		{
			if (cub->map.map_column < i2)
				cub->map.map_column = i2;
		}
		i2 = -1;
	}
	if (mapsize == 0)
		ft_exit(cub, ERROR, EXIT_FAILURE);
}

static int	read_loop(t_game *cub, int line_read)
{
	char	*line;

	while (1)
	{
		line = get_next_line(cub, cub->map.fd);
		if (cub->flag.read_flag == 1)
			ft_exit(cub, READ, EXIT_FAILURE);
		else if (cub->flag.malloc_flag == 1)
			ft_exit(cub, MALLOC, EXIT_FAILURE);
		if (!line)
			break ;
		line_read++;
		if (has_tab(line) == 0)
			return (ft_free(line), ft_exit(cub, ERROR, EXIT_FAILURE), 1);
		if (line[0] == '\n' && cub->flag.mapline_flag == 1)
		{
			ft_free(line);
			ft_exit(cub, ERROR, EXIT_FAILURE);
		}
		join_fileinfo(cub, line);
		ft_free(line);
	}
	return (line_read);
}

static void	ft_map_extension(t_game *cub)
{
	char	*file_extension;
	char	*extension;

	extension = ".cub";
	file_extension = ft_strrchr(cub->map.map_name, '.');
	if (!file_extension)
		ft_exit(cub, ERROR, EXIT_FAILURE);
	if ((ft_strcmp(file_extension, extension)) != 0)
		ft_exit(cub, ERROR, EXIT_FAILURE);
}

void	get_cubfile_info(t_game *cub)
{
	int		line_read;

	line_read = 0;
	cub->map.line_cpy = ft_strdup("");
	cub->map.mapline = ft_strdup("");
	if (!cub->map.line_cpy || !cub->map.mapline)
	{
		ft_exit(cub, MALLOC, EXIT_FAILURE);
	}
	ft_map_extension(cub);
	cub->map.fd = open(cub->map.map_name, O_RDONLY);
	if (cub->map.fd < 0)
	{
		cub->flag.close_flag = 1;
		ft_exit(cub, OPEN, EXIT_FAILURE);
	}
	line_read = read_loop(cub, line_read);
	if (line_read == 0)
		ft_exit(cub, ERROR, EXIT_FAILURE);
	split_and_close(cub);
	check_map_size(cub);
}
