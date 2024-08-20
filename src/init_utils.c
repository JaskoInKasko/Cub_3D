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

int is_map_line(t_game *cub, const char *line)
{
    while (*(line + 1) != '\n' && *(line) != '\0')
	{
        if (*line != '1' && *line != '0' && *line != 'N' &&
            *line != 'S' && *line != 'W' && *line != 'E' &&
            *line != ' ')
            return 1;
        line++;
    }
    return 0;
}

void	join_fileinfo(t_game *cub, char *line)
{
	if (is_map_line(cub, line) == 0)
    {
		cub->map->mapline = ft_strjoin_free(cub->map->mapline, line);
        cub->mapline_flag = 1;
    }
	else
    {
        if (cub->mapline_flag == 1)
		{
			free(line);
            ft_exit(cub, FILE);
		}
		cub->map->line_cpy = ft_strjoin_free(cub->map->line_cpy, line);
    }
	if (!cub->map->line_cpy || !cub->map->mapline)
    {
    	free(line);
		ft_exit(cub, STRJOIN);
    }
}

void	split_and_close(t_game *cub)
{
	cub->map->map_filled = ft_split(cub->map->mapline, '\n');
	cub->map->map_info = ft_split(cub->map->line_cpy, '\n');
    if (!cub->map->map_filled || !cub->map->map_info)
        ft_exit(cub, SPLIT);
	close(cub->map->fd);
	close(cub->map->fd);
}

void	get_cubfile_info(t_game *cub)
{
	char	*line;
	
	cub->map->line_cpy = ft_strdup("");
	cub->map->mapline = ft_strdup("");
    if (!cub->map->line_cpy || !cub->map->mapline)
        ft_exit(cub, MALLOC);
	cub->map->fd = open(cub->map->map_name, O_RDONLY);
	if (cub->map->fd < 0)
	 	ft_exit(cub, OPEN);
	while (1)
	{
		line = get_next_line(cub->map->fd);
		if (!line)
			break ;
		if (has_tab(line) == 0)
			ft_exit(cub, TAB);
        if (line[0] == '\n' && cub->mapline_flag == 1)
		{
			free(line);
            ft_exit(cub, EMPTY);
		}
		join_fileinfo(cub, line);
		free(line);
	}
	split_and_close(cub);
	int i = -1;
	while(cub->map->map_filled[++i])
		printf("%s\n", cub->map->map_filled[i]);
}

void    fill_list(t_game *cub)
{
	int						itsr;
	char					**dir;
	t_addidtion_map_info	*begin;

	itsr = -1;
	begin = cub->ad_map;
    while (cub->map->map_info[++itsr])
    {
		dir = ft_split(cub->map->map_info[itsr], ' ');
		if (!dir)
			ft_exit(cub, SPLIT);
		if (!ft_strcmp(dir[0], "NO") || !ft_strcmp(dir[0], "SO")
			|| !ft_strcmp(dir[0], "WE") || !ft_strcmp(dir[0], "EA")
			|| !ft_strcmp(dir[0], "F") || !ft_strcmp(dir[0], "C"))
		{
			begin->direction =  dir[0];
			if (!ft_strcmp(dir[0], "F") || !ft_strcmp(dir[0], "C"))
				begin->rgb_color = dir[1];
			else
				begin->texture_path = dir[1];
		}
		free_dir(dir);
	}
}