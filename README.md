

# Cub_3D

## What the program does

Cub_3D is a 3D graphics project written in C that creates a simple first-person perspective game using raycasting.

The program renders a three-dimensional view of a map from the player's perspective. It uses raycasting to calculate wall distances and determine which parts of the map should be displayed on the screen.

The project includes:

- **Raycasting:** Casts rays from the player's position to detect walls and calculate their distance.
- **3D rendering:** Displays a first-person view of the environment based on the raycasting calculations.
- **Textured walls:** Applies different textures to walls depending on their orientation and location.
- **Map parsing:** Reads and validates map configuration files containing the environment layout.
- **Player movement:** Allows the player to move through the map and rotate the camera.
- **Collision detection:** Prevents the player from moving through walls.
- **Configuration handling:** Loads texture paths, floor and ceiling colors, and map information from a `.cub` file.

## How to execute the project

Navigate to the project directory:

```bash
cd Cub_3D
```

Compile the project using the Makefile:

```bash
make
```

Run the program with a valid `.cub` map file:

```bash
./cub3D maps/map.cub
```

Replace `maps/map.cub` with the path to your desired map configuration file.

Additional Makefile commands:

```bash
make clean
make fclean
make re
```

