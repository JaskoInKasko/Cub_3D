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

void move(t_game *cub, double dx, double dy)
{
    double newX = cub->player.posX + dx * SPEED;
    double newY = cub->player.posY + dy * SPEED;

    int mapX = (int)cub->player.posX;
    int mapY = (int)cub->player.posY;

    double deltaDistX = (dx == 0) ? 1e30 : fabs(1.0 / dx);
    double deltaDistY = (dy == 0) ? 1e30 : fabs(1.0 / dy);

    double sideDistX;
    double sideDistY;

    int stepX, stepY;

    if (dx < 0) {
        stepX = -1;
        sideDistX = (cub->player.posX - mapX) * deltaDistX;
    } else {
        stepX = 1;
        sideDistX = (mapX + 1.0 - cub->player.posX) * deltaDistX;
    }

    if (dy < 0) {
        stepY = -1;
        sideDistY = (cub->player.posY - mapY) * deltaDistY;
    } else {
        stepY = 1;
        sideDistY = (mapY + 1.0 - cub->player.posY) * deltaDistY;
    }
    int hit = 0;
    while (!hit) {
        if (sideDistX < sideDistY) {
            if (sideDistX >= SPEED + 0.2) break;
            sideDistX += deltaDistX;
            mapX += stepX;
        } else {
            if (sideDistY >= SPEED + 0.2) break;
            sideDistY += deltaDistY;
            mapY += stepY;
        }
       if (cub->map.map_filled[mapY][mapX] != '0' && cub->map.map_filled[mapY][mapX] != 'O') {
            hit = 1;
        }
    }
    if (!hit) {
        cub->player.posX = newX;
        cub->player.posY = newY;
    }
}

void ft_sound()
{
    system("aplay ./src/shoot.wav &");
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
    {
        int x = (int)(cub->player.posX + cub->player.dirX);
        int y = (int)(cub->player.posY + cub->player.dirY);
        if(cub->map.map_filled[y][x] == 'C')
        {
            cub->map.map_filled[y][x] = 'O';
            cub->flag.door_flag = 1;
        }
        else if(cub->map.map_filled[y][x] == 'O')
        {
            cub->map.map_filled[y][x] = 'C';
            cub->flag.door_flag = 1;
        }
    }
    else if(keysym == XK_f)
    {
        ft_sound();
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
    else if(keysym ==XK_Escape)
		ft_exit(cub, ESC, EXIT_SUCCESS);
    ft_draw(cub);
    return 0;
}

int ft_mouse_move(int x, int y, t_game *cub)
{
    (void)y;
    static int last_x = SCREEN_WIDTH / 2; // Start with the center of the window
    int center_x = SCREEN_WIDTH / 2;
    int center_y = SCREEN_HEIGHT / 2;
    double dx;

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
    {
        last_x = x;
    }
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