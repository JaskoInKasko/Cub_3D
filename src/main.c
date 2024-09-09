/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguliyev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:56:34 by iguliyev          #+#    #+#             */
/*   Updated: 2024/09/03 22:23:44 by iguliyev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

void	ft_start_game(t_game *cub)
{
	cub->mlx = mlx_init();
	if (cub->mlx == NULL)
		ft_exit(cub, MLX_INT, EXIT_FAILURE);
	cub->win = mlx_new_window(cub->mlx,
			SCREEN_WIDTH, SCREEN_HEIGHT, "Wolfenstein 3D");
	if (cub->win == NULL)
		ft_exit(cub, MLX_WIN, EXIT_FAILURE);
	ft_load_texture(cub);
	ft_load_texture_data(cub);
	ft_draw(cub);
	mlx_hook(cub->win, DestroyNotify, DestroyAll, &ft_x, cub);
	mlx_hook(cub->win, KeyPress, KeyPressMask, &ft_key_pressed, cub);
	mlx_loop(cub->mlx);
}

int	main(int argc, char *argv[])
{
	t_game	cub;

	if (argc == 2)
	{
		ft_bzero(&cub, sizeof(t_game));
		init_structs(&cub, argv);
		check_map_walls(&cub);
		check_map_content(&cub);
		// ft_start_game(&cub);
		ft_exit(&cub, NULL, EXIT_SUCCESS);
	}
	else
		ft_putstr_fd(INV_ARGS, 2);
	return (0);
}
