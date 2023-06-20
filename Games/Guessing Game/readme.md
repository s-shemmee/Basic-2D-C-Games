# Guessing Game

This is a simple 2D Guessing Game implemented in the C programming language. The game generates a random number between a specified range, and the player needs to guess the correct number within a limited number of attempts.

## How to Play

1. The game will generate a random number between a specified minimum and maximum range.

2. You need to input your guess and press enter.

3. After each guess, the game will provide feedback on whether your guess is too high or too low.

4. Keep guessing until you guess the correct number or reach the maximum number of attempts.

## Getting Started

1. Clone the repository or download the source code file.

2. Compile the C source code using a C compiler. For example:

```shell
gcc guessing_game.c -o guessing_game
```


3. Run the compiled executable:
- For Windows: `guessing_game.exe`
- For Linux/Mac: `./guessing_game`

4. Follow the on-screen instructions to play the game.

## Customization

You can customize the game by modifying the following constants in the source code (`guessing_game.c`):
- `MAX_ATTEMPTS`: Maximum number of attempts allowed to guess the number.
- `MIN_NUMBER`: Minimum value of the random number to be generated.
- `MAX_NUMBER`: Maximum value of the random number to be generated.

Feel free to modify the code and experiment with different game configurations.
