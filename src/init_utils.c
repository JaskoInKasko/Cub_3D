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
	(void)cub;
    while (*(line) != '\0' && *(line + 1) != '\n')
	{
        if (*line != '1' && *line != '0' && *line != 'N' &&
            *line != 'S' && *line != 'W' && *line != 'E' &&
            *line != ' ' && *line != 'D' && *line != 'C' && *line != 'O' && *line != 'H')
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
        cub->flag.mapline_flag = 1;
    }
	else
    {
        if (cub->flag.mapline_flag == 1)
		{
			free(line);
            ft_exit(cub, FILE, EXIT_FAILURE);
		}
		cub->map->line_cpy = ft_strjoin_free(cub->map->line_cpy, line);
    }
	if (!cub->map->line_cpy || !cub->map->mapline)
    {
    	free(line);
		ft_exit(cub, STRJOIN, EXIT_FAILURE);
    }
}

void	split_and_close(t_game *cub)
{
	cub->map->map_filled = ft_split(cub->map->mapline, '\n');
	cub->map->map_info = ft_split(cub->map->line_cpy, '\n');
    if (!cub->map->map_filled || !cub->map->map_info)
	{
        ft_exit(cub, SPLIT, EXIT_FAILURE);
	}
	close(cub->map->fd);
	close(cub->map->fd);
}

void	check_map_size(t_game *cub)
{
	int	mapsize;
	int	i;

	i = -1;
	mapsize = 0;
	while (cub->map->map_filled[++i])
		mapsize++;
	if (mapsize == 0)
		ft_exit(cub, MAP, EXIT_FAILURE);
}

int	read_loop(t_game *cub, int line_read)
{
	char	*line;

	while (1)
	{
		line = get_next_line(cub->map->fd);
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

void	get_cubfile_info(t_game *cub)
{
	int		line_read;
	
	line_read = 0;
	cub->map->line_cpy = ft_strdup("");
	cub->map->mapline = ft_strdup("");
    if (!cub->map->line_cpy || !cub->map->mapline)
	{
        ft_exit(cub, MALLOC, EXIT_FAILURE);
	}
	cub->map->fd = open(cub->map->map_name, O_RDONLY);
	if (cub->map->fd < 0)
	 	ft_exit(cub, OPEN, EXIT_FAILURE);
	line_read = read_loop(cub, line_read);
	if (line_read == 0)
		ft_exit(cub, EMPTY_F, EXIT_FAILURE);
	split_and_close(cub);
	check_map_size(cub);
	// int i = -1;
	// while(cub->map->map_filled[++i])
		// printf("%s\n", cub->map->map_filled[i]);		//remove later
}

void	alloc_new_node(t_game *cub, int istr, t_addidtion_map_info *begin)
{
	t_addidtion_map_info *new_node;

	if (cub->map->map_info[istr + 1])
	{
        new_node = (t_addidtion_map_info *)malloc(sizeof(t_addidtion_map_info));
        if (!new_node)
            ft_exit(cub, MALLOC, EXIT_FAILURE);
        begin->next = new_node;
		free(new_node);
        begin = begin->next;
    }
	else
        begin->next = NULL;
}

void	fill_nodes(t_addidtion_map_info *begin, char **dir)
{
	begin->direction = dir[0];
	if (!ft_strcmp(dir[0], "F") || !ft_strcmp(dir[0], "C"))
	{
		begin->rgb_color = dir[1];
		begin->texture_path = NULL;
	}
	else
	{
		begin->texture_path = dir[1];
		begin->rgb_color = NULL;
	}
}

void    fill_list(t_game *cub)
{
	int						istr;
	char					**dir;
	t_addidtion_map_info	*begin;

	istr = -1;
	begin = cub->ad_map;
    while (cub->map->map_info[++istr])
    {
		dir = ft_split(cub->map->map_info[istr], ' ');
		if (!dir)
			ft_exit(cub, SPLIT, EXIT_FAILURE);
		if (!ft_strcmp(dir[0], "NO") || !ft_strcmp(dir[0], "SO")
			|| !ft_strcmp(dir[0], "WE") || !ft_strcmp(dir[0], "EA")
			|| !ft_strcmp(dir[0], "F") || !ft_strcmp(dir[0], "C"))
			fill_nodes(begin, dir);
		alloc_new_node(cub, istr, begin);
		free_dir(dir);
	}
}