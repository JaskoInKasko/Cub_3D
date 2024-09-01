#include <mlx.h>

void render_map(void *mlx, void *mlx_window, int map[50][50], int player_x, int player_y, int tile_size) {
    int start_x = player_x - 12;
    int start_y = player_y - 12;

    if (start_x < 0) start_x = 0;
    if (start_y < 0) start_y = 0;
    if (start_x > 76) start_x = 76;
    if (start_y > 76) start_y = 76;

    for (int y = 0; y < 24; y++) {
        for (int x = 0; x < 24; x++) {
            int map_value = map[start_y + y][start_x + x];
            // Example: Draw a colored square based on the map value
            int color = map_value == 1 ? 0xFFFFFF : 0x000000; // White or Black
            mlx_pixel_put(mlx, mlx_window, x * tile_size, y * tile_size, color);
        }
    }
}

int main() {
    void *mlx;
    void *mlx_window;
    int map[50][50]; // Your 100x100 map
    int player_x = 50, player_y = 50;
    int tile_size = 10;
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++) {
            if ((i + j) % 2 == 0) {
                map[i][j] = 1; // Example pattern
            } else {
                map[i][j] = 0;
            }
        }
    }
    // Initialize the map with your data...
    
    mlx = mlx_init();
    mlx_window = mlx_new_window(mlx, 24 * tile_size, 24 * tile_size, "Player View");

    render_map(mlx, mlx_window, map, player_x, player_y, tile_size);

    mlx_loop(mlx);
    return 0;
}
