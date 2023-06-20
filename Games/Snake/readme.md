# Snake Game

This is a simple 2D Snake Game implemented in the C programming language. The game features a snake that moves around the screen, eating fruits to grow longer. The objective is to score as many points as possible without colliding with the walls or the snake's own tail.

## How to Play

1. The game starts with a snake consisting of a single character.

2. Use the arrow keys (up, down, left, right) to control the snake's movement.

3. The snake moves continuously in the chosen direction until you change its direction or it collides with the walls or its own tail.

4. The snake can eat fruits that appear randomly on the screen, which increases its length and score.

5. The game ends if the snake collides with the walls or its own tail.

## Getting Started

1. Clone the repository or download the source code file.

2. Compile the C source code using a C compiler. For example:

```shell
gcc snake_game.c -o snake_game
```

3. Run the compiled executable:
- For Windows: `snake_game.exe`
- For Linux/Mac: `./snake_game`

4. Use the arrow keys to control the snake and try to achieve a high score.

## Customization

You can customize the game by modifying the code to add additional features or change the game logic. Feel free to experiment with different board sizes, snake speed, or scoring mechanisms.

## Dependencies

This implementation of the Snake Game relies on the `conio.h` header for keyboard input and the `windows.h` header for the `Sleep` function to introduce a delay. These headers are specific to the Windows operating system and may not be available on other platforms. If you're using a different operating system, you may need to adapt the code or find alternative methods for keyboard input and delay.
