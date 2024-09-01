#include "../includes/Cub3D.h"

void ft_img_check(t_game *cub, char *path, void **img)
{
	int width;
	int height;

	*img = mlx_xpm_file_to_image(cub->mlx, path, &width, &height);
	if (*img == NULL)
		ft_exit(cub, MLX_IMG, EXIT_FAILURE);
}

void ft_data_check(t_game *cub, void **img, char **data, int *line_length)
{
	*data = mlx_get_data_addr(*img, &cub->img.bits_per_pixel, line_length, &cub->img.endian);
	if (data == NULL)
		ft_exit(cub, MLX_DATA, EXIT_FAILURE);
}

void ft_load_texture(t_game *cub)
{
	cub->img.img = mlx_new_image(cub->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (cub->img.img == NULL)
		ft_exit(cub, MLX_IMG, EXIT_FAILURE);
	ft_img_check(cub, "./textures/blue.xpm", &cub->img.north);
	ft_img_check(cub, "./textures/brick.xpm", &cub->img.south);
	ft_img_check(cub, "./textures/grey.xpm", &cub->img.east);
	ft_img_check(cub, "./textures/wood.xpm", &cub->img.west);
	ft_img_check(cub, "./textures/hitler.xpm", &cub->img.hitler);
	ft_img_check(cub, "./textures/door.xpm", &cub->img.door);
	ft_img_check(cub, "./textures/pistol.xpm", &cub->img.pistol);
	ft_img_check(cub, "./textures/pistol_shoot.xpm", &cub->img.pistol_shoot);
	ft_img_check(cub, "./textures/scope.xpm", &cub->img.scope);
	ft_img_check(cub, "./textures/enemy.xpm", &cub->img.enemy);
	ft_img_check(cub, "./textures/mini_floor.xpm", &cub->img.mini_floor);
	ft_img_check(cub, "./textures/mini_wall.xpm", &cub->img.mini_wall);
	ft_img_check(cub, "./textures/mini_player.xpm", &cub->img.mini_player);
}

void ft_load_texture_data(t_game *cub)
{
	cub->img.addr = mlx_get_data_addr(cub->img.img, &cub->img.bits_per_pixel, &cub->img.line_length, &cub->img.endian);
	if (cub->img.addr == NULL)
		ft_exit(cub, MLX_DATA, EXIT_FAILURE);
	ft_data_check(cub, &cub->img.north, &cub->img.data_north, &cub->img.tex_line_length);
	ft_data_check(cub, &cub->img.south, &cub->img.data_south, &cub->img.tex_line_length);
	ft_data_check(cub, &cub->img.east, &cub->img.data_east, &cub->img.tex_line_length);
	ft_data_check(cub, &cub->img.west, &cub->img.data_west, &cub->img.tex_line_length);
	ft_data_check(cub, &cub->img.hitler, &cub->img.data_hitler, &cub->img.tex_line_length);
	ft_data_check(cub, &cub->img.door, &cub->img.data_door, &cub->img.tex_line_length);
	ft_data_check(cub, &cub->img.pistol, &cub->img.data_pistol, &cub->img.pistol_line_length);
	ft_data_check(cub, &cub->img.pistol_shoot, &cub->img.data_pistol_shoot, &cub->img.pistol_line_length);
	ft_data_check(cub, &cub->img.scope, &cub->img.data_scope, &cub->img.scope_line_length);
	ft_data_check(cub, &cub->img.enemy, &cub->img.data_enemy, &cub->img.tex_line_length);
}