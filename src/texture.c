/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguliyev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:21:16 by iguliyev          #+#    #+#             */
/*   Updated: 2024/09/03 22:24:47 by iguliyev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

void	ft_texture_img_check(t_game *cub, char *path, void **img)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	*img = mlx_xpm_file_to_image(cub->mlx, path, &width, &height);
	if (*img == NULL)
		ft_exit(cub, MLX_IMG, EXIT_FAILURE);
	if (width != 64 || height != 64)
		ft_exit(cub, TEXTURE_SIZE, EXIT_FAILURE);
}

void	ft_img_check(t_game *cub, char *path, void **img)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	*img = mlx_xpm_file_to_image(cub->mlx, path, &width, &height);
	if (*img == NULL)
		ft_exit(cub, MLX_IMG, EXIT_FAILURE);
}

void	ft_data_check(t_game *cub, void **img, char **data, int *line_length)
{
	*data = mlx_get_data_addr(*img, &cub->img.bpp,
			line_length, &cub->img.endian);
	if (data == NULL)
		ft_exit(cub, MLX_DATA, EXIT_FAILURE);
}

void	ft_load_texture(t_game *cub)
{
	cub->img.img = mlx_new_image(cub->mlx,
			SCREEN_WIDTH + EXTRA_WIDTH, SCREEN_HEIGHT);
	if (cub->img.img == NULL)
		ft_exit(cub, MLX_IMG, EXIT_FAILURE);
	ft_texture_img_check(cub, cub->map.north, &cub->img.north);
	ft_texture_img_check(cub, cub->map.south, &cub->img.south);
	ft_texture_img_check(cub, cub->map.east, &cub->img.east);
	ft_texture_img_check(cub, cub->map.west, &cub->img.west);
	ft_texture_img_check(cub, "./textures/eagle.xpm", &cub->img.paper);
	ft_texture_img_check(cub, "./textures/door.xpm", &cub->img.door);
	ft_img_check(cub, "./textures/pistol.xpm", &cub->img.pistol);
	ft_img_check(cub, "./textures/pistol_shoot.xpm", &cub->img.pistol_shoot);
	ft_img_check(cub, "./textures/scope.xpm", &cub->img.scope);
	ft_texture_img_check(cub, "./textures/enemy.xpm", &cub->img.enemy);
	ft_img_check(cub, "./textures/mini_floor.xpm", &cub->img.mini_floor);
	ft_img_check(cub, "./textures/mini_wall.xpm", &cub->img.mini_wall);
	ft_img_check(cub, "./textures/mini_player.xpm", &cub->img.mini_player);
	ft_img_check(cub, "./textures/mini_black.xpm", &cub->img.mini_black);
}

void	ft_load_texture_data(t_game *cub)
{
	cub->img.addr = mlx_get_data_addr(cub->img.img, &cub->img.bpp,
			&cub->img.line_length, &cub->img.endian);
	if (cub->img.addr == NULL)
		ft_exit(cub, MLX_DATA, EXIT_FAILURE);
	ft_data_check(cub, &cub->img.north,
		&cub->img.data_north, &cub->img.t_line_len);
	ft_data_check(cub, &cub->img.south,
		&cub->img.data_south, &cub->img.t_line_len);
	ft_data_check(cub, &cub->img.east,
		&cub->img.data_east, &cub->img.t_line_len);
	ft_data_check(cub, &cub->img.west,
		&cub->img.data_west, &cub->img.t_line_len);
	ft_data_check(cub, &cub->img.paper,
		&cub->img.data_paper, &cub->img.t_line_len);
	ft_data_check(cub, &cub->img.door,
		&cub->img.data_door, &cub->img.t_line_len);
	ft_data_check(cub, &cub->img.pistol,
		&cub->img.data_pistol, &cub->img.pistol_line_length);
	ft_data_check(cub, &cub->img.pistol_shoot,
		&cub->img.data_pistol_shoot, &cub->img.pistol_line_length);
	ft_data_check(cub, &cub->img.scope,
		&cub->img.data_scope, &cub->img.scope_line_length);
	ft_data_check(cub, &cub->img.enemy,
		&cub->img.data_enemy, &cub->img.t_line_len);
}
