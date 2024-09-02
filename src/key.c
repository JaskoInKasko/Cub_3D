#include "../includes/Cub3D.h"

int	ft_x(t_game *cub)
{
    ft_exit(cub, X_CLOSE, EXIT_SUCCESS);
    return 0;
}

void rotate(t_game *cub, double angle)
{
    double old_dirX;
    double old_dirY;
    double old_planeX;
    double old_planeY;

    old_dirX = cub->player.dirX;
    old_dirY = cub->player.dirY;
    old_planeX = cub->player.planeX;
    old_planeY = cub->player.planeY;

    cub->player.dirX = old_dirX * cos(angle) - old_dirY * sin(angle);
    cub->player.dirY = old_dirX * sin(angle) + old_dirY * cos(angle);
    cub->player.planeX = old_planeX * cos(angle) - old_planeY * sin(angle);
    cub->player.planeY = old_planeX * sin(angle) + old_planeY * cos(angle);
}

void ft_calculate_vars_values_for_move(t_game *cub, double dx, double dy)
{
    cub->ray.newX = cub->player.posX + dx * SPEED;
    cub->ray.newY = cub->player.posY + dy * SPEED;
    cub->ray.stepX = 1;
    cub->ray.stepY = 1;
    cub->ray.hit = 0;
    cub->ray.mapX = (int)cub->player.posX;
    cub->ray.mapY = (int)cub->player.posY;
    cub->ray.deltaDistX = (dx == 0) ? 1e30 : fabs(1.0 / dx);
    cub->ray.deltaDistY = (dy == 0) ? 1e30 : fabs(1.0 / dy);
    cub->ray.sideDistX = (cub->ray.mapX + 1.0 - cub->player.posX) * cub->ray.deltaDistX;
    cub->ray.sideDistY = (cub->ray.mapY + 1.0 - cub->player.posY) * cub->ray.deltaDistY;
    if (dx < 0) 
    {
        cub->ray.stepX = -1;
        cub->ray.sideDistX = (cub->player.posX - cub->ray.mapX) * cub->ray.deltaDistX;
    } 
    if (dy < 0) 
    {
        cub->ray.stepY = -1;
        cub->ray.sideDistY = (cub->player.posY - cub->ray.mapY) * cub->ray.deltaDistY;
    } 
}

void ft_check_if_move_is_possible(t_game *cub)
{
    while (!cub->ray.hit) 
    {
        if (cub->ray.sideDistX < cub->ray.sideDistY) 
        {
            if (cub->ray.sideDistX >= SPEED + 0.2) 
                break;
            cub->ray.sideDistX += cub->ray.deltaDistX;
            cub->ray.mapX += cub->ray.stepX;
        } 
        else 
        {
            if (cub->ray.sideDistY >= SPEED + 0.2) 
                break;
            cub->ray.sideDistY += cub->ray.deltaDistY;
            cub->ray.mapY += cub->ray.stepY;
        }
        if (cub->map.map_filled[cub->ray.mapY][cub->ray.mapX] != '0' && cub->map.map_filled[cub->ray.mapY][cub->ray.mapX] != 'O')
        {
            cub->ray.hit = 1;
        }
    }    
}

void move(t_game *cub, double dx, double dy)
{
    ft_calculate_vars_values_for_move(cub, dx, dy);
    ft_check_if_move_is_possible(cub);
    if (!cub->ray.hit) 
    {
        cub->player.posX = cub->ray.newX;
        cub->player.posY = cub->ray.newY;
    }
}

void ft_sound()
{
    system("aplay ./src/shoot.wav &");
}

void ft_space_pressed(t_game *cub)
{
    int x;
    int y;
    
    x = (int)(cub->player.posX + cub->player.dirX);
    y = (int)(cub->player.posY + cub->player.dirY);
    if(cub->map.map_filled[y][x] == 'C')
        cub->map.map_filled[y][x] = 'O';
    else if(cub->map.map_filled[y][x] == 'O')
        cub->map.map_filled[y][x] = 'C';
}

void ft_f_pressed(t_game *cub)
{
    // ft_sound();
    double c_x = cub->player.posX;
    double c_y = cub->player.posY;
    cub->flag.shoot_flag = 1;
    while(cub->map.map_filled[(int)c_y][(int)(c_x)] == '0' || cub->map.map_filled[(int)c_y][(int)(c_x)] == 'O')
    {
        c_x = c_x + cub->player.dirX;
        c_y = c_y + cub->player.dirY;
    }
    if(cub->map.map_filled[(int)c_y][(int)(c_x)] == 'D')
        cub->map.map_filled[(int)c_y][(int)(c_x)] = '0';
}

int	ft_key_pressed(int keysym, t_game *cub)
{
    if (keysym == XK_w)
        move(cub, cub->player.dirX, cub->player.dirY);
    else if (keysym == XK_s)
        move(cub, -cub->player.dirX, -cub->player.dirY);
    else if (keysym == XK_a)
        move(cub, -cub->player.planeX, -cub->player.planeY);
    else if (keysym == XK_d)
        move(cub, cub->player.planeX, cub->player.planeY);
    else if(keysym == XK_Left)
        rotate(cub, ANGLE);
    else if(keysym == XK_Right)
        rotate(cub, -ANGLE);
    else if(keysym == XK_space)
        ft_space_pressed(cub);
    else if(keysym == XK_f)
        ft_f_pressed(cub);
    else if(keysym ==XK_Escape)
		ft_exit(cub, ESC, EXIT_SUCCESS);
    ft_draw(cub);
    return 0;
}

int ft_mouse_move(int x, int y, t_game *cub)
{
    (void)y;
    static int last_x = SCREEN_WIDTH / 2; // Start with the center of the window
    int center_x;
    int center_y;
    double dx;

    center_x = SCREEN_WIDTH / 2;
    center_y = SCREEN_HEIGHT / 2;
    dx = (double)(x - last_x) / 1000;
    if (dx != 0)
    {
        rotate(cub, -dx);
        ft_draw(cub);
    }
    if (x != center_x)
    {
        mlx_mouse_move(cub->mlx, cub->win, center_x, center_y);
        last_x = center_x;
    }
    else
        last_x = x;
    return 0;
}

int ft_mouse_click(int button, int x, int y, t_game *cub)
{
    (void)x;
    (void)y;

    if (button == 1) // Left mouse button
    {
        double c_x = cub->player.posX;
        double c_y = cub->player.posY;
        while(cub->map.map_filled[(int)c_y][(int)(c_x)] == '0' || cub->map.map_filled[(int)c_y][(int)(c_x)] == 'O')
        {
            c_x = c_x + cub->player.dirX;
            c_y = c_y + cub->player.dirY;
        }
        if(cub->map.map_filled[(int)c_y][(int)(c_x)] == 'D')
        {
            cub->map.map_filled[(int)c_y][(int)(c_x)] = '0';
            ft_draw(cub);
        }
    }
    return 0;
}