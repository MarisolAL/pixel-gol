# Pixeled Game of Life

This project is an implementation of John Conway's Game of Life using Katsu 2D video game library. The Game of Life is a cellular automaton where cells on a grid can live, die, or multiply based on specific rules. This implementation visualizes the cells by plotting live and dead pixels on the screen.

This project uses [Katsu](https://github.com/fadedled/Katsu) library for rendering graphics. Katsu is a simple and lightweight 2D videogame library designed to provide an easy way to create 2D graphical videogames. Special thanks to the developers of Katsu for providing this tool.

## Rules of the Game

Conway's Game of Life follows four simple rules:

1. Any live cell with fewer than two live neighbors dies by underpopulation.
2. Any live cell with two or three live neighbors lives on to the next generation.
3. Any live cell with more than three live neighbors dies by overpopulation.
4. Any dead cell with exactly three live neighbors becomes a live cell by reproduction.
