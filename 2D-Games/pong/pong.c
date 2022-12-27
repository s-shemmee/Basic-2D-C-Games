#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>

#define GRID_SIZE 20

// Structure to represent a position on the grid
struct position {
  int x;
  int y;
};

// Function prototypes
void init_grid(char grid[GRID_SIZE][GRID_SIZE]);
void print_grid(char grid[GRID_SIZE][GRID_SIZE]);
int get_paddle_move(int paddle_pos);
struct position update_ball(struct position ball, int paddle1_pos, int paddle2_pos);
bool is_valid_move(struct position pos, char grid[GRID_SIZE][GRID_SIZE]);
void update_grid(char grid[GRID_SIZE][GRID_SIZE], struct position ball, int paddle1_pos, int paddle2_pos);

int main() {
  char grid[GRID_SIZE][GRID_SIZE];
  struct position ball = {GRID_SIZE / 2, GRID_SIZE / 2};  // Initial position of the ball
  int paddle1_pos = GRID_SIZE / 2;  // Initial position of player 1's paddle
  int paddle2_pos = GRID_SIZE / 2;  // Initial position of player 2's paddle
  int player1_score = 0, player2_score = 0;  // Scores for each player

  // Seed the random number generator
  srand(time(0));

  // Initialize the grid
  init_grid(grid);

  while (1) {
    // Print the grid
    print_grid(grid);

    // Get player 1's move
    printf("Player 1: ");
    paddle1_pos += get_paddle_move(paddle1_pos);

    // Get player 2's move (AI)
    paddle2_pos = ball.y;

    // Update the ball's position
    ball = update_ball(ball, paddle1_pos, paddle2_pos);

    // Check if the ball has gone off the left or right side of the screen
    if (ball.x < 0) {
      // Player 2 scores a point
      player2_score++;
      printf("Player 2 scores a point!\n");
      ball = (struct position){GRID_SIZE / 2, GRID_SIZE / 2};
    } else if (ball.x >= GRID_SIZE) {
      // Player 1 scores
      player1_score++;
      printf("Player 1 scores a point!\n");
      ball = (struct position){GRID_SIZE / 2, GRID_SIZE / 2};
    }

    // Update the grid with the new positions of the ball and paddles
    update_grid(grid, ball, paddle1_pos, paddle2_pos);

    // Print the scores
    printf("Player 1: %d\tPlayer 2: %d", player1_score, player2_score);

    // Wait for 0.1 seconds
    usleep(100000);
  }

  return 0;
}

// Initialize the grid
void init_grid(char grid[GRID_SIZE][GRID_SIZE]) {
  int i, j;
  for (i = 0; i < GRID_SIZE; i++) {
    for (j = 0; j < GRID_SIZE; j++) {
      grid[i][j] = ' ';
    }
  }
}

// Print the grid
void print_grid(char grid[GRID_SIZE][GRID_SIZE]) {
  int i, j;
  for (i = 0; i < GRID_SIZE; i++) {
    for (j = 0; j < GRID_SIZE; j++) {
      printf("%c ", grid[i][j]);
    }
    printf("\n");
  }
}

// Get the player's move
int get_paddle_move(int paddle_pos) {
  char move;
  scanf("%c", &move);
  if (move == 'w' && paddle_pos > 0) {
    return -1;
  } else if (move == 's' && paddle_pos < GRID_SIZE - 1) {
    return 1;
  } else {
    return 0;
  }
}

// Update the ball's position
struct position update_ball(struct position ball, int paddle1_pos, int paddle2_pos) {
  // Get a random number between -1 and 1
  int x_dir = rand() % 3 - 1;
  int y_dir = rand() % 3 - 1;

  // Update the ball's position
  ball.x += x_dir;
  ball.y += y_dir;

  // Check if the ball has hit the top or bottom of the screen
  if (ball.y < 0 || ball.y >= GRID_SIZE) {
    ball.y -= y_dir;
  }

  // Check if the ball has hit a paddle
  if (ball.x == 1 && is_valid_move(ball, paddle1_pos)) {
    ball.x -= x_dir;
  } else if (ball.x == GRID_SIZE - 2 && is_valid_move(ball, paddle2_pos)) {
    ball.x -= x_dir;
  }

  return ball;
}

// Check if the ball's position is valid
bool is_valid_move(struct position pos, char grid[GRID_SIZE][GRID_SIZE]) {
  if (grid[pos.x][pos.y] == ' ') {
    return true;
  } else {
    return false;
  }
}

// Update the grid with the new positions of the ball and paddles
void update_grid(char grid[GRID_SIZE][GRID_SIZE], struct position ball, int paddle1_pos, int paddle2_pos) {
  // Clear the grid
  init_grid(grid);

  // Update the grid with the new positions of the ball and paddles
  grid[ball.x][ball.y] = 'O';
  grid[0][paddle1_pos] = '|';
  grid[GRID_SIZE - 1][paddle2_pos] = '|';
}
