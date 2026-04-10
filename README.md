
*This project has been created as part of the 42 curriculum by chbenhiz.*
# 🐬 so_long

*"And thanks for all the fish!"*

This project is a small 2D game created for the 42 school curriculum. The objective is to learn and work with window management, event handling, textures, and basic gameplay elements using the school's internal graphic library: **MiniLibX**.

## 🎯 Objective
The player's goal is to navigate through a map, collect all the items (collectibles), and escape through the exit door while minimizing the total number of movements.

## ✨ Key Features
- **Robust Parsing**: Strict validation of the `.ber` map format, checking for rectangular shape, closed walls, and valid characters.
- **Pathfinding Validation**: Implements a **Flood Fill** algorithm to ensure there is a valid, unobstructed path to all collectibles and the exit before the game starts.
- **Memory Safe**: Strictly tested with Valgrind.
- **Dynamic Resolution**: Automatically checks the host's screen size using `mlx_get_screen_size` to prevent the program from launching if the map exceeds the display resolution.
- **Custom Library**: Uses a personalized `libft` including custom implementations of `get_next_line` and `ft_printf`.

## 🛠️ Compilation

The project is built using a `Makefile`. The following rules are available:

- `make` : Compiles the `libft`, the MiniLibX, and the `so_long` executable.
- `make clean` : Removes object files (`.o`).
- `make fclean` : Removes object files and the executable.
- `make re` : Executes `fclean` followed by `make`.

## 🚀 Usage

To start the game, run the executable with a valid map file as the first argument:

./so_long maps/level1.ber

### 🎮 Controls
- **W / Up Arrow** : Move Up
- **A / Left Arrow** : Move Left
- **S / Down Arrow** : Move Down
- **D / Right Arrow** : Move Right
- **ESC / Window Cross** : Quit the game cleanly

*(The total number of movements is updated in real-time in the standard output).*

## 🗺️ Map Format (.ber)
Custom maps can be created inside the `maps/` directory. They must be saved with the `.ber` extension and follow these strict rules:

- Must be completely surrounded by walls.
- Must be rectangular.
- Must contain exactly 1 Player (`P`).
- Must contain exactly 1 Exit (`E`).
- Must contain at least 1 Collectible (`C`).

**Allowed characters:**
- `1` : Wall
- `0` : Empty space
- `C` : Collectible
- `E` : Exit
- `P` : Player

**Valid Map Example:**

    1111111111111
    1P000000000C1
    1011111011101
    101C000000001
    11111111E1111
    1111111111111