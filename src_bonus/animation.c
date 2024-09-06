/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguliyev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 18:49:12 by iguliyev          #+#    #+#             */
/*   Updated: 2024/09/03 22:21:42 by iguliyev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D_bonus.h"

int	ft_animation(t_game *cub)
{
	size_t	i;

	i = 0;
	if (cub->flag.shoot_flag == 1)
	{
		ft_draw(cub);
		while (1)
		{
			if (i == 1000000000)
			{
				cub->flag.shoot_flag = 0;
				ft_draw(cub);
				return (0);
			}
			i++;
		}
	}
	return (0);
}
