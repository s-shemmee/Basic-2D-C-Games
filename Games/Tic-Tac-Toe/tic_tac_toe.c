#include <stdio.h>

#define SIZE 3

void printBoard(char board[SIZE][SIZE]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) {
                printf("|");
            }
        }
        printf("\n");
        if (i < SIZE - 1) {
            printf("---|---|---\n");
        }
    }
    printf("\n");
}

int checkWin(char board[SIZE][SIZE], char symbol) {
    // Check rows
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) {
            return 1;
        }
    }

    // Check columns
    for (int i = 0; i < SIZE; i++) {
        if (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol) {
            return 1;
        }
    }

    // Check diagonals
    if ((board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) ||
        (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol)) {
        return 1;
    }

    return 0;
}

int main() {
    char board[SIZE][SIZE];
    int row, col;
    char currentPlayer = 'X';
    int moves = 0;

    // Initialize the board
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }

    printf("Welcome to the 2D Tic-Tac-Toe Game!\n");
    printf("Player 1: X\n");
    printf("Player 2: O\n");
    printf("Let's start!\n");

    while (1) {
        // Print the board
        printBoard(board);

        // Get the player's move
        printf("Player %c, enter your move (row [1-%d] column [1-%d]): ", currentPlayer, SIZE, SIZE);
        scanf("%d %d", &row, &col);
        row--;
        col--;

        // Check if the move is valid
        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ') {
            // Make the move
            board[row][col] = currentPlayer;
            moves++;

            // Check for a win
            if (checkWin(board, currentPlayer)) {
                // Print the final board
                printBoard(board);
                printf("Player %c wins!\n", currentPlayer);
                break;
            } else if (moves == SIZE * SIZE) {
                // All cells are filled, it's a draw
                printBoard(board);
                printf("It's a draw!\n");
                break;
            }

            // Switch to the next player
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            printf("Invalid move. Try again.\n");
        }
    }

    return 0;
}
