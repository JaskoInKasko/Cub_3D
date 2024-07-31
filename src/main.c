#include "../includes/Cub3D.h"

int	main(int argc, char *argv[])
{
	t_game cub;

	if (argc == 2)
	{
		alloc_structs(&cub);
		init_structs(&cub, argv);
		check_map(&cub);
		ft_free(&cub);
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
