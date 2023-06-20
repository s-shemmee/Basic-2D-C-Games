#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ATTEMPTS 5
#define MIN_NUMBER 1
#define MAX_NUMBER 100

int main() {
    int numberToGuess;
    int guess;
    int attempts = 0;
    
    // Generate a random number between MIN_NUMBER and MAX_NUMBER
    srand(time(NULL));
    numberToGuess = rand() % (MAX_NUMBER - MIN_NUMBER + 1) + MIN_NUMBER;

    printf("Welcome to the Guessing Game!\n");
    printf("I'm thinking of a number between %d and %d.\n", MIN_NUMBER, MAX_NUMBER);
    printf("Can you guess the number?\n");

    while (1) {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if (guess == numberToGuess) {
            printf("Congratulations! You guessed the correct number in %d attempts!\n", attempts);
            break;
        } else if (guess < numberToGuess) {
            printf("Too low. Try again!\n");
        } else {
            printf("Too high. Try again!\n");
        }

        if (attempts >= MAX_ATTEMPTS) {
            printf("Game over! You have reached the maximum number of attempts.\n");
            printf("The number I was thinking of was: %d\n", numberToGuess);
            break;
        }
    }

    return 0;
}
