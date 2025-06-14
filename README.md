# Pixeled Game of Life

This project is an implementation of John Conway's Game of Life using Katsu 2D video game library. The Game of Life is a cellular automaton where cells on a grid can live, die, or multiply based on specific rules. This implementation visualizes the cells by plotting live and dead pixels on the screen.

This project uses [Katsu](https://github.com/fadedled/Katsu) library for rendering graphics. Katsu is a simple and lightweight 2D videogame library designed to provide an easy way to create 2D graphical videogames. Special thanks to the developers of Katsu for providing this tool.

## Rules of the Game

Conway's Game of Life follows four simple rules:

1. Any live cell with fewer than two live neighbors dies by underpopulation.
2. Any live cell with two or three live neighbors lives on to the next generation.
3. Any live cell with more than three live neighbors dies by overpopulation.
4. Any dead cell with exactly three live neighbors becomes a live cell by reproduction.

## Compilation and Execution

This project is written in C and must be compiled before running. The program is split into two parts:

* `gol.c` : the Game of Life logic.

* `main.c` : the entry point, which uses the 2D graphics library to visualize the simulation.

### Requirements

* A C compiler (e.g. `gcc`)

* Katsu library requirements


### Steps to execute and compile

1. Compile the Game of Life logic

```bash
gcc -Wall -c gol.c
```
This creates `gol.o`, which contains the compiled logic for the Game of Life.

2. Compile and link the full program

Once `gol.o` is ready, compile the full program using

```bash
gcc main.c -o gol_simulation \
  -I./include \
  -I/usr/include/pipewire-0.3 \
  -I/usr/include/spa-0.2 \
  -D_REENTRANT \
  -L./lib \
  -lGL -lpipewire-0.3 -lX11 -lm -ldl -lkatsu \
  gol.o
```

3. After compiling run the simulation with:

```bash
./gol_simulation
```
