/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguliyev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:07:15 by iguliyev          #+#    #+#             */
/*   Updated: 2024/09/03 22:22:13 by iguliyev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

void	ft_free(char *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}

void	ft_free_double(char **ptr)
{
	int	i;

	i = -1;
	if (ptr)
	{
		while (ptr[++i])
			ft_free(ptr[i]);
		free(ptr);
		ptr = NULL;
	}
}

void	ft_free_all(t_game *cub)
{
	ft_free(cub->flag.backup);
	ft_free(cub->map.line_cpy);
	ft_free(cub->map.mapline);
	ft_free_double(cub->map.map_filled);
	ft_free_double(cub->map.map_info);
}

void	ft_exit(t_game *cub, char *msg, int exit_status)
{
	int	fd;

	fd = 2;
	if (cub->flag.close_flag == 0)
		close(cub->map.fd);
	if (exit_status == EXIT_SUCCESS)
		fd = 1;
	ft_free_all(cub);
	ft_destroy_imgs(cub);
	ft_destroy_window_and_display(cub);
	if (msg)
		write(fd, msg, ft_strlen(msg));
	exit(exit_status);
}
