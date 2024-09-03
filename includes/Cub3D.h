/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsakanov <jsakanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 21:03:29 by jsakanov          #+#    #+#             */
/*   Updated: 2024/09/02 17:57:55 by jsakanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

//		LIBRARIES

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <mlx.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <sys/stat.h>
# include <fcntl.h>

//		INC_LIBRARIES
# include "../includes_functions/libft/libft.h"
# include "../includes_functions/ft_printf/ft_printf.h"
# include "../includes_functions/get_next_line/get_next_line.h"
// # include "../minilibx-linux/mlx.h"

//		DEFAULT_VALUES
# define SCREEN_WIDTH 640
# define SCREEN_HEIGHT 480
# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64
# define MINI_TEX_WIDTH 10
# define MINI_TEX_HEIGHT 10
# define SCOPE_HEIGHT 30
# define SCOPE_WIDTH 30
# define PISTOL_HEIGHT 90
# define PISTOL_WIDTH 90
# define MINIMAP_SIZE 24
# define MINI_TILE_SIZE 10
# define ANGLE M_PI / 64
# define SPEED 0.2

//		COLORS
#define SKY_BLUE 0x87CEEB
#define FLOOR_COLOR 0x8B4513

//      ERROR MANAGEMENT
# define INV_ARGS		"Error: Wrong amount of Arguments. Expected 2!\n"
# define MALLOC			"Error: Malloc() function failed!\n"
# define STRDUP			"Error: ft_strdup() function failed!\n"
# define OPEN			"Error: open() function failed!\n"
# define GNL			"Error: get_next_line() function failed!\n"
# define STRJOIN		"Error: ft_strjoin_free() function failed!\n"
# define SPLIT			"Error: ft_split() function failed!\n"
# define EMPTY_M		"Error: Empty line in map!\n"
# define FILE			"Error: Map before identifier or invalid character in map!\n"
# define WALL			"Error: Map must be surrounded by walls!\n"
# define TAB			"Error: cubfile contains a Tab!\n"
# define EMPTY_F		"Error: Empty file!\n"
# define MAP			"Error: No map found!\n"
# define PLAYER			"Error: More then one player in the game!\n"
# define MLX_INT		"Error: mlx_init() function failed!\n"
# define MLX_WIN		"Error: mlx_new_window() function failed!\n"
# define MLX_IMG		"Error: mlx_xpm_file_to_image() function failed!\n"
# define MLX_DATA		"Error: mlx_get_data_addr() function failed!\n"
# define MLX_NEW_IMG	"Error: mlx_new_image() function failed!\n"
# define TOKEN          "Error: unrecognized token in cubfile!\n"
# define ELEMENT        "Error: Map elements are not complete!\n"
# define MAP_SIZE       "Error: lack of elements in Map!\n"
# define DOOR           "Error: Door has no connecting point between 2 walls!\n"
# define EXTENTION      "Error: Mapfile has wrong extention!\n"
# define RGB			"Error: wrong rgb value!\n"


//      INFORMATION
# define ESC       "You pressed ESC. Game Over!\n" 
# define X_CLOSE   "You clicked on the X. Game Over!\n"

//      Characters
// WALL -> 1
// FLOOR -> 0
// OPEN_GATE -> O (O as a letter)
// CLOSED_GATE -> C
// PLAYER -> P
// PLAYER_DIRECTION -> N, S, E, W
// ENEMY -> D
// PICTURE_ON_WALL -> H

// typedef enum e_sign
// {
// 	FLOOR,
//     WALL_FLAG,
// 	WALL_NORTH,
// 	WALL_SOUTH,
// 	WALL_EAST,
// 	WALL_WEST,
// 	DOOR,
// 	ENEMY,
// 	SPACE,
// 	COLLISION,
//     PLAYER_FLAG
// } t_sign;

typedef struct  s_img
{
    void *img;
    void *north;
    void *south;
    void *east;
    void *west;
    void *pistol;
    void *pistol_shoot;
    void *scope;
    void *hitler;
    void *door;
    void *enemy;
    void *mini_floor;
    void *mini_wall;
    void *mini_player;
    void *mini_black;
    char *addr;
    char *data_south;
    char *data_north;
    char *data_east;
    char *data_west;
    char *data_pistol;
    char *data_pistol_shoot;
    char *data_scope;
    char *data_hitler;
    char *data_door;
    char *data_enemy;
    int  bits_per_pixel;
    int  endian;
    int  line_length;
	int  tex_line_length;
    int  pistol_line_length;
    int  scope_line_length;
}	            t_img;

// typedef struct	s_addidtion_map_info
// {
// 	char						*direction;
// 	char						*texture_path;
// 	char						*rgb_color;
// 	struct s_addidtion_map_info	*next;
// }				t_addidtion_map_info;

typedef struct  s_map_data
{
    int     				fd;
    char    				*line_cpy;
    char    				**map_filled;
    char    				*map_name;
	char					*mapline;
	char					**map_info;
	int						line_begin_prev;
	int						line_begin_cur;
	int						line_end_prev;
	int						map_row;
	int						map_column;
	char					*north;
	char					*east;
	char					*south;
	char					*west;
	int						f_rgb[3];
	int						c_rgb[3];
    int                     f_color;
    int                     c_color;
}               t_map_data;

typedef struct	s_player
{
    double      posX;
    double      posY;
    double      posX_scope;
    double      posY_scope;
    double      dirX;
    double      dirY;
    double      planeX;
    double      planeY;
}				t_player;

typedef struct	s_flag 
{
	int         door_flag;
    int         move_flag;
	int			mapline_flag;
    int         success_flag;
    int         shoot_flag;
}				t_flag;

typedef struct  s_tmp
{
    int         i2;
    int         i3;
    int         n;
}               t_tmp;

typedef struct s_ray
{
    double      newX;
    double      newY;
    double      cameraX;
    double      rayDirX;
    double      rayDirY;
    int         mapX;
    int         mapY;
    double      sideDistX;
    double      sideDistY;
    double      deltaDistX;
    double      deltaDistY;
    double      perpWallDist;
    int         stepX;
    int         stepY;
    int         hit;
    int         side;
    int         lineHeight;
    int         drawStart;
    int         drawEnd;
    int         texNum;
    double      wallX;
    int         texX;
    int         texY;
    double      step;
    double      texPos;
    char        *color;
    int         color_int;
}               t_ray;

typedef struct  s_minimap
{
    int         x;
    int         y;
    int         start_x;
    int         start_y;
    int         end_x;
    int         end_y;
    int         original_start_x;
}               t_minimap;

typedef struct  s_game
{
    void        *mlx;
    void        *win;
    t_img					img;
	// t_addidtion_map_info	*ad_map;
    t_map_data				map;
	t_player				player;
	t_flag					flag;
    t_ray                   ray;    
    t_minimap               minimap;
    t_tmp                   tmp;

}	            t_game;

//      INITS_ALLOCS
void	alloc_structs(t_game *cub);
void	init_structs(t_game *cub, char *argv[]);

//      INIT_UTILS
int 	is_map_line(const char *line);
void	join_fileinfo(t_game *cub, char *line);
void	split_and_close(t_game *cub);
void	get_cubfile_info(t_game *cub);
void	get_addition_mapinfo(t_game *cub);
// void	fill_list(t_game *cub);

//		PARSER
void    check_map_walls(t_game *cub);

//		PARSER_UTILS
void    check_map_content(t_game *cub);

//      FINISH
void	ft_exit(t_game *cub, char *msg, int exit_status);
void	ft_free_all(t_game *cub);

//		SET_TEXTURE
void	ft_load_texture(t_game *cub);
void	ft_load_texture_data(t_game *cub);
void	ft_img_check(t_game *cub, char *path, void **img);
void	ft_data_check(t_game *cub, void **img, char **data, int *line_length);

//		START_GAME
void	ft_start_game(t_game *cub);
void	ft_draw(t_game *cub);

//		DRAW_UTILS
void	my_mlx_pixel_put(t_game *cub, int x, int y, int color);
void	ft_set_background(t_game *cub);
void    ft_set_minimap_background(t_game *cub);
void	ft_set_pistol(t_game *cub);
void    ft_set_pistol_shoot(t_game *cub);
void	ft_set_scope(t_game *cub);
void    ft_set_text(t_game *cub);

//		KEYS
int	ft_x(t_game *cub);
int	ft_key_pressed(int keysym, t_game *cub);
int ft_mouse_move(int x, int y, t_game *cub);
int ft_mouse_click(int button, int x, int y, t_game *cub);

int	ft_animation(t_game *cub);
void ft_set_pistol_shoot(t_game *cub);
void ft_sound();


#endif
