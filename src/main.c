#include "../includes/Cub3D.h"

int	alloc_structs(t_game *cub)
{
	cub->map = (t_map_data *)malloc(sizeof(t_map_data));
	cub->ad_map = (t_addidtion_map_info *)malloc(sizeof(t_addidtion_map_info));
	if (!cub->map || !cub->ad_map)
		return (/*ft_free(cub),*/MALLOC);
	return (SUCCESS);
}

int content_is_map(char *line)
{
	int i;

	i = -1;
	while(line[++i] != '\0')
	{
		if (line[i] != '1')
			return (ft_printf("1: %s\n", line), 1);
	}
	ft_printf("2: %s\n", line);
	return (0);
}

void	get_cubfile_info(t_game *cub)
{
	int		fd;
	char	*line;
	
	cub->map->line_cpy = ft_strdup("");
	fd = open(cub->map->map_name, O_RDONLY);
	// if (fd < 0)
		//ft_exit(cub);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (content_is_map(line) == 0)
			break ; 
		cub->map->line_cpy = ft_strjoin_free(cub->map->line_cpy, line);
		//if (!cub->map->line_cpy)
			//ft_free();
		free(line);
	}
	//ft_printf("%s", cub->map->line_cpy);
	close (fd);
	free(cub->map->line_cpy);
}

void	init_structs(t_game *cub, char *argv[])
{
	cub->map->fd = 0;
	cub->map->line_cpy = NULL;
	cub->map->map_filled = NULL;
	cub->map->map_name = argv[1];
	get_cubfile_info(cub);
	//fill_list(cub);
}

// void	check_map(t_game *cub)
// {
// 	int		fd;
// 	char	*line;
	
// 	cub->map->line_cpy = ft_strdup("");
// 	fd = open(cub->map->map_name);
// 	if (fd < 0)
// 		ft_exit(cub);
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (!line)// && map->rows == 0)
// 			ft_map_errors();
// 		if (!line)
// 			break ;
// 		if (line[0] == '\n')
// 			ft_map_errors();
// 		cub->map->line_cpy = ft_strjoin_free(cub->map->line_cpy, line);
// 		if (!cub->map->line_cpy)
// 			ft_map_errors();
// 		//map->rows++;
// 		free(line);
// 	}
	
// }

int	main(int argc, char *argv[])
{
	t_game cub;

	if (argc == 2)
	{
		alloc_structs(&cub);
		init_structs(&cub, argv);
		// check_map(&cub);
	}
	else
		ft_putstr_fd(INV_ARGS, 2);
}