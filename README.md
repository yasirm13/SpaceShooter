# SpaceShooter

Console Shooter Game

A simple console-based shooter game written in C++ where players can control a character to shoot enemies descending from the top of the screen.

Table of Contents
- Overview
- Features
- Installation
- Controls
- Game Mechanics
- Code Structure
- License

Overview

This console game allows players to control a character with the goal of shooting down enemies. The player can move left and right and shoot bullets to destroy enemies as they descend. Points are awarded for each enemy hit, and the game ends if an enemy reaches the player's position.

Features

- Player Movement: Control the player character using keyboard inputs.
- Shooting Mechanics: Press the space bar to shoot bullets.
- Enemy Spawning and Movement: Enemies randomly spawn at the top and move down the screen.
- Score System: Earn points for shooting enemies.
- Game Over Condition: Game ends if an enemy reaches the player's position.

Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/console-shooter-game.git
   ```
2. Compile the code using any C++ compiler that supports <conio.h> and Windows-specific libraries (<windows.h>):
   ```bash
   g++ main.cpp -o console_shooter_game
   ```
3. Run the executable:
   ```bash
   ./console_shooter_game
   ```

> Note: This game uses <conio.h> and <windows.h>, so it is currently designed for Windows environments.

Controls

- A: Move Left
- D: Move Right
- Space: Shoot
- X: Exit Game

Game Mechanics

- Player Character (^): Positioned at the bottom of the screen, the player can move left or right.
- Bullets (|): Fired upwards from the player's position, destroying enemies on collision.
- Enemies (E): Spawn at random horizontal positions at the top and descend towards the player. If an enemy reaches the player, the game ends.

Code Structure

- setup(): Initializes the game state.
- draw(): Renders the game board, player, bullets, and enemies in the console.
- input(): Captures player inputs to control movement and shooting.
- logic(): Handles the game logic, such as bullet movement, enemy spawning, collision detection, and game-over conditions.
- main(): Main game loop that calls draw(), input(), and logic() functions.

License

This project is licensed under the MIT License - see the LICENSE file for details.

---

Enjoy playing the Console Shooter Game! Feel free to customize the game, add new features, or improve the code.
