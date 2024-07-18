#include "../includes/Cub3D.h"

int	alloc_structs(t_game *cub)
{
	cub->map = (t_map_data *)malloc(sizeof(t_map_data));
	if (!cub->map)
		return(MALLOC);
	return (SUCCESS);
}

void	init_structs(t_game *cub, char *argv[])
{
	cub->map->fd = 0;
	cub->map->map_name = argv[1];
}

void	check_map(t_game *cub)
{
	int		fd;
	char	*line;
	
	map->line_cpy = ft_strdup("");
	fd = open(cub->map->map_name);
	if (fd < 0)
		ft_exit(cub);
	while (1)
	{
		line = get_next_line(fd);
			ft_map_errors();
		if (!line)
			break ;
		if (line[0] == '\n')
			ft_map_errors();
		map->line_cpy = ft_strjoin_free(map->line_cpy, line);
		if (!map->line_cpy)
			ft_map_errors();
		//map->rows++;
		free(map->line);
	}
	
}

int	main(int argc, char *argv[])
{
	t_game cub;

	if (argc == 2)
	{
		alloc_structs(&cub);
		init_structs(&cub, argv);
		//check_map(&cub);
	}
	else
		ft_putstr_fd(INV_ARGS, 2);
}