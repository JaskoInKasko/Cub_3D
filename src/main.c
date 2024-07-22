#include "../includes/Cub3D.h"

int	alloc_structs(t_game *cub)
{
	cub->map = (t_map_data *)malloc(sizeof(t_map_data));
	cub->ad_map = (t_addidtion_map_info *)malloc(sizeof(t_addidtion_map_info));
	if (!cub->map || !cub->ad_map)
		return (ft_exit(cub), MALLOC);
	return (SUCCESS);
}

int is_map_line(const char *line)
{
    while (*line)
	{
        if (*line != '1' && *line != '0' && *line != 'N' &&
            *line != 'S' && *line != 'W' && *line != 'E' &&
            *line != ' ' && *line != '\n')
            return 1;
        line++;
    }
    return 0;
}

void	get_map(t_game *cub)
{
	int		fd;
	char	*line;

	cub->map->map_line = ft_strdup("");
	if (!cub->map->map_line)
        ft_exit(cub);
	fd = open(cub->map->map_name, O_RDONLY);
	if (fd < 0)
	 	ft_exit(cub);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
        if (is_map_line(line) == 0)
        {
            cub->map->map_line = ft_strjoin_free(cub->map->map_line, line);
            if (!cub->map->map_line)
            {
                free(line);
			    ft_exit(cub);
            }
        }
		free(line);
	}
	cub->map->map_filled = ft_split(cub->map->map_line, '\n');
    if (!cub->map->map_filled)
        ft_exit(cub);
	close (fd);
	free(cub->map->map_line);
}

void	get_cubfile_info(t_game *cub)
{
	int		fd;
	char	*line;
	
	get_map(cub);
	cub->map->line_cpy = ft_strdup("");
    if (!cub->map->line_cpy)
        ft_exit(cub);
	fd = open(cub->map->map_name, O_RDONLY);
	if (fd < 0)
	 	ft_exit(cub);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (is_map_line(line) == 1)
			cub->map->line_cpy = ft_strjoin_free(cub->map->line_cpy, line);
		if (!cub->map->line_cpy)
        {
        	free(line);
			ft_exit(cub);
        }
		free(line);
	}
	close (fd);
	fill_list(cub);
	free(cub->map->line_cpy);
}

// void    fill_list(t_game *cub)
// {
//     int i;
//     char line;

//     i = -1;
//     line = cub->map->line_cpy;
//     while(line[++i] != '\0')
//     {
//         if (!ft_strncmp(line, "NO"))
//             cub->ad_map->direction =
//     }
// }

void	init_structs(t_game *cub, char *argv[])
{
	cub->map->fd = 0;
	cub->map->line_cpy = NULL;
	cub->map->map_filled = NULL;
	cub->map->map_name = argv[1];
	get_cubfile_info(cub);
}

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
// int main()
// {
//     void *mlx;
//     void *win;

//     mlx = mlx_init();
//     win = mlx_new_window(mlx, 640, 480, "Hello, MinilibX!");
//     mlx_loop(mlx);
//     return (0);
// }
