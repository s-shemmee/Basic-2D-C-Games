#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define GRID_SIZE 20

// Structure to represent a position on the grid
struct position {
  int x;
  int y;
};

// Function prototypes
void init_grid(char grid[GRID_SIZE][GRID_SIZE]);
void print_grid(char grid[GRID_SIZE][GRID_SIZE]);
struct position get_move(struct position snake[], int length);
bool is_valid_move(struct position pos, char grid[GRID_SIZE][GRID_SIZE]);
void update_grid(char grid[GRID_SIZE][GRID_SIZE], struct position snake[], int length, struct position food);
void place_food(char grid[GRID_SIZE][GRID_SIZE], struct position *food);

int main() {
  char grid[GRID_SIZE][GRID_SIZE];
  struct position snake[GRID_SIZE * GRID_SIZE] = {{0, 0}};  // Initial position of the snake
  int length = 1;  // Initial length of the snake
  struct position food;  // Position of the food on the grid

  // Seed the random number generator
  srand(time(0));

  // Initialize the grid
  init_grid(grid);

  // Set the initial position of the snake on the grid
  grid[snake[0].x][snake[0].y] = 'S';

  // Place the food on the grid
  place_food(grid, &food);

  while (1) {
    // Print the grid
    print_grid(grid);

    // Get the player's next move
    snake[0] = get_move(snake, length);

    // Check if the move is valid
    if (!is_valid_move(snake[0], grid)) {
      printf("Game over! You lost.\n");
      break;
    }

    // Update the rest of the snake's position based on the head's position
    int i;
    for (i = length - 1; i > 0; i--) {
      snake[i] = snake[i - 1];
    }

    // Update the grid with the new positions of the snake
    update_grid(grid, snake, length, food);

    // Check if the snake has eaten the food
    if (snake[0].x == food.x && snake[0].y == food.y) {
      // If the snake has eaten the food, increase its length and place a new piece of food
      length++;
      place_food(grid, &food);
    }
  }

  return 0;
}

// Initializes the grid with '.' characters
void init_grid(char grid[GRID_SIZE][GRID_SIZE]) {
  int i, j;

  for (i = 0; i < GRID_SIZE; i++) {
    for (j = 0; j < GRID_SIZE; j++) {
      grid[i][j] = '.';
    }
  }
}

// Prints the grid to the console
void print_grid(char grid[GRID_SIZE][GRID_SIZE]) {
  int i, j;

  for (i = 0; i < GRID_SIZE; i++) {
    for (j = 0; j < GRID_SIZE; j++) {
      printf("%c ", grid[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

// Gets the player's next move
struct position get_move(struct position snake[], int length) {
  struct position pos = snake[0];
  char move;

  printf("Enter your move (w, a, s, d): ");
  scanf(" %c", &move);

  switch (move) {
    case 'w':
      pos.x--;
      break;
    case 'a':
      pos.y--;
      break;
    case 's':
      pos.x++;
      break;
    case 'd':
      pos.y++;
      break;
  }

  return pos;
}

// Checks if the player's move is valid
bool is_valid_move(struct position pos, char grid[GRID_SIZE][GRID_SIZE]) {
  // Check if the move is out of bounds
  if (pos.x < 0 || pos.x >= GRID_SIZE || pos.y < 0 || pos.y >= GRID_SIZE) {
    return false;
  }

  // Check if the move is on top of the snake
  if (grid[pos.x][pos.y] == 'S') {
    return false;
  }

  return true;
}

// Updates the grid with the new positions of the snake
void update_grid(char grid[GRID_SIZE][GRID_SIZE], struct position snake[], int length, struct position food) {
  // Clear the grid
  init_grid(grid);

  // Place the snake on the grid
  int i;
  for (i = 0; i < length; i++) {
    grid[snake[i].x][snake[i].y] = 'S';
  }

  // Place the food on the grid
  grid[food.x][food.y] = 'F';
}

// Places a piece of food on the grid
void place_food(char grid[GRID_SIZE][GRID_SIZE], struct position *food) {
  do {
    food->x = rand() % GRID_SIZE;
    food->y = rand() % GRID_SIZE;
  } while (grid[food->x][food->y] == 'S');
}
