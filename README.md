# Labyrinth - Finding the Shortest Path

## Project Description

**Labyrinth** is a simple game written in C, where the player must find the shortest path from the starting point (S) to the goal (G) on a grid-based maze. The maze is loaded from a text file, and the player can move using arrow keys, WASD keys, and diagonal movement shortcuts. The objective is to reach the goal while avoiding dangerous fields marked as 'X'.

Each maze is stored in a separate text file, and the program automatically loads the appropriate file based on the user's selection.

## Controls

- **W, Up Arrow** – move up
- **S, Down Arrow** – move down
- **A, Left Arrow** – move left
- **D, Right Arrow** – move right
- **Q** – move diagonally up-left
- **E** – move diagonally up-right
- **Z** – move diagonally down-left
- **C** – move diagonally down-right

## Game Files

The mazes are stored in text files. Each file contains a square grid where:

- **S** marks the starting point
- **G** marks the goal
- **X** marks impassable (dangerous) fields



## How the Game Works
- The game will ask the player to choose a maze (1-4) based on the available maze files.
- The maze is displayed on the screen, with the player starting at position 'S'.
- The player moves using the arrow keys or WASD and can use diagonal moves (Q, E, Z, C).
- The game checks each move for validity, ensuring the player doesn't land on a dangerous field ('X').
- If the player reaches the goal ('G'), the game congratulates them and ends.

## Dependencies
This project requires a C compiler and terminal access for execution. It has been tested with gcc and may work on other compilers as well.
