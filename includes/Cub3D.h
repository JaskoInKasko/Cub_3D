/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 21:03:29 by jsakanov          #+#    #+#             */
/*   Updated: 2024/07/22 12:48:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_3D_H
# define CUB_3D_H
# include <stdlib.h>
#include <stdio.h>                                                  //remove later
# include "../includes_functions/libft/libft.h"
# include "../includes_functions/ft_printf/ft_printf.h"
# include "../includes_functions/get_next_line/get_next_line.h"
# include "../minilibx-linux/mlx.h"

//      ERROR MANAGEMENT
# define INV_ARGS "Error:\nWrong amount of Arguments. Expected 2!\n"

//		WINDOW MANAGEMENT
# define PXL 100

//		KEYCODE
# define ESC 65307
# define KEY_UP 119
# define KEY_DOWN 115
# define KEY_LEFT 97
# define KEY_RIGHT 100

typedef enum
{
    SUCCESS,
    ERROR,
    MALLOC,
}   num_management;

typedef struct  s_image
{

}	            t_image;

typedef struct	s_addidtion_map_info
{
	char						*direction;
	char						*texture_path;
	char						*rgb_color;
	struct s_addidtion_map_info	*next;
}				t_addidtion_map_info;

typedef struct  s_map_data
{
    int     fd;
    char    *line_cpy;
    char    **map_filled;
    char    *map_name;
	char	*map_line;
	char	**mapfile_info;
}               t_map_data;

typedef struct  s_game
{
    t_image					*img;
	t_addidtion_map_info	*ad_map;
    t_map_data				*map;
}	            t_game;

void	ft_exit(t_game *cub);
void	ft_free(t_game *cub);


#endif
