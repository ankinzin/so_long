# so_long

Welcome to my So_Long project for 42 School! This project is part of the curriculum of the Graphics branch, and its goal is to create a simple 2D game using the MiniLibX library.

# Game Description

So_Long is a game where the player controls a character in a maze and must collect all the collectibles (represented by a sprite) before reaching the exit (also represented by a sprite). The player must avoid enemies (also represented by a sprite), which move randomly around the maze.

# Installation and Usage

To install and run this game on your machine, please follow these steps:

# Clone this repository onto your local machine.

Make sure that you have the MiniLibX library installed.
Run the command make to compile the game.
Run the game with the command ./so_long [map_path], where map_path is the path to the map file you want to use (maps are located in the maps directory).

# Controls

The game is controlled using the arrow keys on the keyboard. The player can move up, down, left, and right.

# Map Creation

If you want to create your own maps, you can do so by following these rules:

Maps must be rectangular.
Maps must have at least one player, one exit, and one collectible.
Maps can have walls (represented by the character 1), empty spaces (represented by the character 0), players (represented by the character P), exits (represented by the character E), and collectibles (represented by the character C).
Maps must be saved as a .ber file in the maps directory.

# Acknowledgements

I would like to thank the 42 School for providing me with the opportunity to work on this project and learn more about graphics programming. I would also like to thank the MiniLibX team for creating such a powerful and easy-to-use library.
