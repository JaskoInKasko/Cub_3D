/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsakanov <jsakanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 21:03:29 by jsakanov          #+#    #+#             */
/*   Updated: 2024/08/21 18:31:15 by jsakanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_3D_H
# define CUB_3D_H
# include <stdlib.h>
#include <stdio.h>                                                  //remove later
# include "../includes_functions/libft/libft.h"
# include "../includes_functions/ft_printf/ft_printf.h"
# include "../includes_functions/get_next_line/get_next_line.h"
// # include "../minilibx-linux/mlx.h"

//      ERROR MANAGEMENT
# define INV_ARGS	"Error: Wrong amount of Arguments. Expected 2!\n"
# define MALLOC		"Error: Malloc() function failed!\n"
# define STRDUP		"Error: ft_strdup() function failed!\n"
# define OPEN		"Error: open() function failed!\n"
# define GNL		"Error: get_next_line() function failed!\n"
# define STRJOIN	"Error: ft_strjoin_free() function failed!\n"
# define SPLIT		"Error: ft_split() function failed!\n"
# define EMPTY_M	"Error: Empty line in map!\n"
# define FILE		"Error: Map before identifier or invalid character in map!\n"
# define WALL		"Error: Map must be surrounded by walls!\n"
# define TAB		"Error: cubfile contains a Tab!\n"
# define EMPTY_F	"Error: Empty file!\n"
# define MAP		"Error: No map found!\n"
# define PLAYER		"Error: More then one player in the game!\n"

//		WINDOW MANAGEMENT
# define PXL 100

//		KEYCODE
# define ESC 65307
# define KEY_UP 119
# define KEY_DOWN 115
# define KEY_LEFT 97
# define KEY_RIGHT 100

// typedef enum
// {
//     SUCCESS,
//     ERROR,
//     MALLOC,
// }   num_management;

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
	char	*mapline;
	char	**map_info;
	int		line_begin_prev;
	int		line_begin_cur;
	int		line_end_prev;
	int		map_rows;
	int		*map_columns;
}               t_map_data;
typedef struct	s_player
{
	int	player_x;
	int	player_y;
}				t_player;


typedef struct  s_game
{
    t_image					*img;
	t_addidtion_map_info	*ad_map;
    t_map_data				*map;
	t_player				*player;
	int						mapline_flag;
}	            t_game;

//      INITS_ALLOCS
void	alloc_structs(t_game *cub);
void	init_structs(t_game *cub, char *argv[]);

//      INIT_UTILS
int 	is_map_line(t_game *cub, const char *line);
void	join_fileinfo(t_game *cub, char *line);
void	split_and_close(t_game *cub);
void	get_cubfile_info(t_game *cub);
void	fill_list(t_game *cub);

//		PARSER
void    check_map_walls(t_game *cub);

//		PARSER_UTILS
void    check_map_content(t_game *cub);

//      FINISH
void	ft_exit(t_game *cub, char *msg);
void	free_dir(char **dir);
void	ft_free(t_game *cub);

#endif
