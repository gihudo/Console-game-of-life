# Console Game of Life

Console Game of Life is a console text-based implementation of Conway's Game of Life, written in C++ that is really fun to play around! Users can interact with the game and observe the evolution of cellular automata directly in console, try it yourself!

## Table of Contents

- [Introduction](#introduction)
- [Installation](#installation)
- [Preview](#preview)
- [Game Rules and Controls](#game-rules-and-controls)
- [Contributing](#contributing)

## Introduction

Conway's Game of Life is a cellular automaton devised by the mathematician John Horton Conway in 1970. The game is played on a grid of cells, where each cell can be either alive or dead. The game evolves in discrete time steps according to a set of rules.

This implementation brings the game to the console, allowing users to experience the mesmerizing patterns and behavior of this fascinating mathematical simulation.

## Installation

To use Console Game of Life, follow these steps:

1. Clone the repository:

   ```shell
   git clone https://github.com/gihudo/ConsoleGameOfLife.git

2. Navigate to the project directory:
   ```shell
   cd ConsoleGameOfLife
   
3. Build the project.

## Game Rules and Controls
- Any live cell with fewer than two live neighbours dies, as if by underpopulation. <br>
- Any live cell with two or three live neighbours lives on to the next generation. <br>
- Any live cell with more than three live neighbours dies, as if by overpopulation. <br>
- Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction. <br>
  ### Controls
  * Press Space to add new cells. <br>
  * Press Delete to delete cells. <br>

## Contributing
Contributions to Console Game of Life are welcome! If you want to contribute to this project, please follow these steps:

Fork the repository.
1. Create a new branch for your feature or bug fix.
2. Make the necessary changes and commit them.
3. Push your branch to your forked repository.
4. Submit a pull request with a clear description of your changes.

## Preview
<p align="center">
  <img src="https://github.com/gihudo/ConsoleGameOfLife/blob/master/demo.gif" alt="preview" />
</p>
