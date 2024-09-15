/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3D_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 21:03:29 by jsakanov          #+#    #+#             */
/*   Updated: 2024/09/09 14:01:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

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

//		DEFAULT_VALUES
# define SCREEN_WIDTH 640
# define SCREEN_HEIGHT 480
# define EXTRA_WIDTH 240
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
# define SPEED 0.2

//		ERROR MANAGEMENT
# define ERROR			"Error: Check map file!\n"
# define INV_ARGS		"Error: Wrong amount of Arguments. Expected 2!\n"
# define MALLOC			"Error: Malloc() function failed!\n"
# define STRDUP			"Error: ft_strdup() function failed!\n"
# define OPEN			"Error: open() function failed!\n"
# define GNL			"Error: get_next_line() function failed!\n"
# define STRJOIN		"Error: ft_strjoin_free() function failed!\n"
# define SPLIT			"Error: ft_split() function failed!\n"
# define MLX_INT		"Error: mlx_init() function failed!\n"
# define MLX_WIN		"Error: mlx_new_window() function failed!\n"
# define MLX_IMG		"Error: mlx_xpm_file_to_image() function failed!\n"
# define MLX_DATA		"Error: mlx_get_data_addr() function failed!\n"
# define MLX_NEW_IMG	"Error: mlx_new_image() function failed!\n"
# define DOOR			"Error: Door has no connecting point between 2 walls!\n"
# define TEXTURE_SIZE	"Error: Texture size is not 64x64!\n"
# define READ			"Error: read() in get_next_line() failed!\n"
# define CLOSE			"Error: close() function failed!\n"

//		INFORMATION
# define ESC		"You pressed ESC. Game Over!\n" 
# define X_CLOSE	"You clicked on the X. Game Over!\n"

typedef struct s_img
{
	void	*img;
	void	*north;
	void	*south;
	void	*east;
	void	*west;
	void	*pistol;
	void	*pistol_shoot;
	void	*scope;
	void	*paper;
	void	*door;
	void	*enemy;
	void	*mini_floor;
	void	*mini_wall;
	void	*mini_player;
	void	*mini_black;
	char	*addr;
	char	*data_south;
	char	*data_north;
	char	*data_east;
	char	*data_west;
	char	*data_pistol;
	char	*data_pistol_shoot;
	char	*data_scope;
	char	*data_paper;
	char	*data_door;
	char	*data_enemy;
	int		bpp;
	int		endian;
	int		line_length;
	int		t_line_len;
	int		pistol_line_length;
	int		scope_line_length;
}				t_img;

typedef struct s_map_data
{
	int		fd;
	char	*line_cpy;
	char	**map_filled;
	char	*map_name;
	char	*mapline;
	char	**map_info;
	int		line_begin_prev;
	int		line_begin_cur;
	int		line_end_prev;
	int		map_row;
	int		map_column;
	char	*north;
	char	*east;
	char	*south;
	char	*west;
	int		f_rgb[3];
	int		c_rgb[3];
	int		f_color;
	int		c_color;
}				t_map_data;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	pos_x_scope;
	double	pos_y_scope;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}				t_player;

typedef struct s_flag
{
	int	door_flag;
	int	move_flag;
	int	mapline_flag;
	int	success_flag;
	int	shoot_flag;
	int	close_flag;
	int	malloc_flag;
	int	read_flag;
}				t_flag;

typedef struct s_tmp
{
	int	i2;
	int	i3;
	int	s_b;
	int	s_a;
	int	n;
	int	i;
}				t_tmp;

typedef struct s_ray
{
	double	new_x;
	double	new_y;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		tex_num;
	double	wall_x;
	int		tex_x;
	int		tex_y;
	double	step;
	char	*color;
	int		color_int;
}				t_ray;

typedef struct s_mini
{
	int	x;
	int	y;
	int	start_x;
	int	start_y;
	int	end_x;
	int	end_y;
	int	original_start_x;
}				t_mini;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	double		angle;
	t_img		img;
	t_map_data	map;
	t_player	player;
	t_flag		flag;
	t_ray		ray;
	t_mini		mini;
	t_tmp		tmp;

}				t_game;

//		INITS_ALLOCS
void	alloc_structs(t_game *cub);
void	init_structs(t_game *cub, char *argv[]);
void	check_for_spaces(t_game *cub, int i);
int		rgb_color_is_valid(t_game *cub, int i);
void	check_rgb_int_value(t_game *cub);

//		INIT_UTILS
void	join_fileinfo(t_game *cub, char *line);
void	get_cubfile_info(t_game *cub);
void	get_addition_mapinfo(t_game *cub);
int		has_tab(char *line);
void	get_int_value(t_game *cub, int i);
int		line_is_valid(t_game *cub, int i);

//		PARSER
void	check_map_walls(t_game *cub);

//		PARSER_UTILS
void	check_map_content(t_game *cub);

//		FINISH
void	ft_exit(t_game *cub, char *msg, int exit_status);
void	ft_free_all(t_game *cub);
void	ft_free_double(char **ptr);
void	ft_free(char *ptr);

//		SET_TEXTURE
void	ft_load_texture(t_game *cub);
void	ft_load_texture_data(t_game *cub);
void	ft_img_check(t_game *cub, char *path, void **img);
void	ft_data_check(t_game *cub, void **img, char **data, int *line_length);

//		START_GAME
void	ft_start_game(t_game *cub);

//		KEYS
int		ft_x(t_game *cub);
int		ft_key_pressed(int keysym, t_game *cub);

int		ft_animation(t_game *cub);
void	ft_draw_mini(t_game *cub);

//		SETTER
void	my_mlx_pixel_put(t_game *cub, int x, int y, int color);
void	ft_set_screen(t_game *cub);
void	ft_set_pistol_shoot(t_game *cub);
void	ft_set_pistol(t_game *cub);
void	ft_set_scope(t_game *cub);
void	ft_set_text(t_game *cub);
void	ft_set_mini_background(t_game *cub);
void	ft_define_pixel_color_for_draw(t_game *cub, int y);

//		DRAW
void	ft_calculate_vars_values_for_draw_part1(t_game *cub);
void	ft_find_hit_point(t_game *cub);
void	ft_calculate_vars_values_for_draw_part2(t_game *cub);
void	ft_draw(t_game *cub);

// 		DESTROY
void	ft_destroy_window_and_display(t_game *cub);
void	ft_destroy_single_img(t_game *cub, void *ptr);
void	ft_destroy_imgs(t_game *cub);

//		MOVE
void	move(t_game *cub, double dir_x, double dir_y);
void	rotate(t_game *cub, double angle);

//		MOUSE
int		ft_mouse_move(int x, int y, t_game *cub);
int		ft_mouse_click(int button, int x, int y, t_game *cub);

char	*get_next_line(t_game *cub, int fd);
char	*ft_strjoin_gnl(t_game *cub, char *s1, char *s2);
size_t	ft_strlen_gnl(const char *str);
char	*ft_strchr_gnl(char *s, int c);
char	*ft_strdup_gnl(t_game *cub, const char *s);

#endif