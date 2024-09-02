#include "../includes/Cub3D.h"

int	has_tab(char *line)
{
	while (*line != '\0')
	{
        if (*line == '\t')
            return 0;
        line++;
    }
    return 1;
}

int is_map_line(const char *line)
{
	int i;

	i = -1;
	if (*line != '1' && *line != '0' && *line != 'N' &&
        *line != 'S' && *line != 'W' && *line != 'E' &&
        *line != ' ' && *line != 'D' && *line != 'C' && 
		*line != 'O' && *line != 'H')
        return (1);
	line++;
    while (*(line) != '\0' && *(line + 1) != '\n')
	{
		if (*line != '1' && *line != '0' && *line != 'N' &&
			*line != 'S' && *line != 'W' && *line != 'E' &&
			*line != ' ' && *line != 'D' && *line != 'C' && 
			*line != 'O' && *line != 'H')
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
            ft_exit(cub, FILE, EXIT_FAILURE);
		}
		cub->map.line_cpy = ft_strjoin_free(cub->map.line_cpy, line);
    }
	if (!cub->map.line_cpy || !cub->map.mapline)
    {
    	free(line);
		ft_exit(cub, STRJOIN, EXIT_FAILURE);
    }
}

void	split_and_close(t_game *cub)
{
	cub->map.map_filled = ft_split(cub->map.mapline, '\n');
	cub->map.map_info = ft_split(cub->map.line_cpy, '\n');
    if (!cub->map.map_filled || !cub->map.map_info)
	{
        ft_exit(cub, SPLIT, EXIT_FAILURE);
	}
	close(cub->map.fd);
	close(cub->map.fd);
}

void	check_map_size(t_game *cub)
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
		while(cub->map.map_filled[i][++i2])
		{
			if (cub->map.map_column < i2)
				cub->map.map_column = i2;
		}
		i2 = -1;
	}
	if (mapsize == 0)
		ft_exit(cub, MAP, EXIT_FAILURE);
}

int	read_loop(t_game *cub, int line_read)
{
	char	*line;

	while (1)
	{
		line = get_next_line(cub->map.fd);
		if (!line)
			break ;
		line_read++;
		if (has_tab(line) == 0)
			ft_exit(cub, TAB, EXIT_FAILURE);
        if (line[0] == '\n' && cub->flag.mapline_flag == 1)
		{
			free(line);
            ft_exit(cub, EMPTY_M, EXIT_FAILURE);
		}
		join_fileinfo(cub, line);
		free(line);
	}
	return (line_read);
}

void	ft_map_extension(t_game *cub)
{
	char	*file_extension;
	char	*extension;

	extension = ".cub";
	file_extension = ft_strrchr(cub->map.map_name, '.');
	if (!file_extension)
		ft_exit(cub, EXTENTION, EXIT_FAILURE);
	if ((ft_strcmp(file_extension, extension)) != 0)
		ft_exit(cub, EXTENTION, EXIT_FAILURE);
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
	 	ft_exit(cub, OPEN, EXIT_FAILURE);
	line_read = read_loop(cub, line_read);
	if (line_read == 0)
		ft_exit(cub, EMPTY_F, EXIT_FAILURE);
	split_and_close(cub);
	check_map_size(cub);
	// int i = -1;
	// while(cub->map.map_info[++i])
	// 	printf("%s\n", cub->map.map_info[i]);		//remove later
}

int		line_is_valid(t_game *cub, int i)
{
	int		i2;
	char	**tmp;

	tmp = ft_split(cub->map.map_info[i], ' ');
	i2 = -1;
	while (tmp[++i2])
		if (i2 > 1)
			return (1);
	i2 = -1;
	while(tmp[++i2])
        free(tmp[i2]);
    free(tmp);
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
		if (tmp[cub->tmp.i2 + 1] == ',')
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

int	rgb_color_is_valid(t_game *cub, int i)
{
	int		i2;
	int		colon;
	char	*tmp;

	i2 = 1;
	colon = 0;
	tmp = cub->map.map_info[i];
	while(tmp[++i2])
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

int create_rgb(int r, int g, int b)
{
    return (r << 16) | (g << 8) | b;
}


void	get_addition_mapinfo_extended(t_game *cub, char *tmp, int i)
{
	if (!ft_strncmp(cub->map.map_info[i], "WE ", 3))
	{
		cub->map.west = cub->map.map_info[i];
		ft_memmove(cub->map.west, tmp + 3, ft_strlen(tmp) - 2);
	}
	else if (!ft_strncmp(cub->map.map_info[i], "EA ", 3))
	{
		cub->map.east = cub->map.map_info[i];
		ft_memmove(cub->map.east, tmp + 3, ft_strlen(tmp) - 2);
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
	}
}

void	check_element_completness(t_game *cub)
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

void	get_rgb_color(t_game *cub)
{
	cub->map.f_color = create_rgb(cub->map.f_rgb[0],\
cub->map.f_rgb[1], cub->map.f_rgb[2]);
	cub->map.c_color = create_rgb(cub->map.c_rgb[0],\
cub->map.c_rgb[1], cub->map.c_rgb[2]);
}

void	get_addition_mapinfo(t_game *cub)
{
	int 	i;
	char	*tmp;

	i = -1;
	check_element_completness(cub);
	while (cub->map.map_info[++i])
	{
		if (line_is_valid(cub, i) == 1)
			ft_exit(cub, TOKEN, EXIT_FAILURE);
		tmp = cub->map.map_info[i];
		if (!ft_strncmp(cub->map.map_info[i], "NO ", 3))
		{
			cub->map.north = cub->map.map_info[i];
			ft_memmove(cub->map.north, tmp + 3, ft_strlen(tmp) - 2);
		}
		else if (!ft_strncmp(cub->map.map_info[i], "SO ", 3))
		{
			cub->map.south = cub->map.map_info[i];
			ft_memmove(cub->map.south, tmp + 3, ft_strlen(tmp) - 2);
		}
        get_addition_mapinfo_extended(cub, tmp, i);
	}
	get_rgb_color(cub);
}