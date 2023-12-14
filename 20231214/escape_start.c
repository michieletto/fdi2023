// Includes the standard input/output library
#include <stdio.h>
// Includes the standard library
#include <stdlib.h>

// Defines the board size
#define BOARD_SIZE 8

// Prints the chessboard
void print_chessboard(int chessboard[], int size) {
    printf("+-+-+-+-+-+-+-+-+\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("|%s", chessboard[i*size+j] ? "O" : "X");
        }
        printf("|\n");
        printf("+-+-+-+-+-+-+-+-+\n");
    }
}

// Randomizes the positions of the coins on the chessboard
void randomize_chessboard(int chessboard[], int size, int random_factor){
    srand(random_factor);
    // Fills the chessboard with random values
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            // Generates a random number between head and tail (0 and 1)
            chessboard[i*size+j] = rand()%2;
        }
    }
}

// Asks the jailer for the magic square
// after randomizing the coins on the chessboard
int jailer(int chessboard[], int size){
    int random_factor = 0;
    int row = -1;
    int col = -1;

    // We use the random factor to generate different chessboards
    printf("Random: ");
    scanf("%d", &random_factor);

    // Call the randomize_chessboard function to generate the coins 
    // on the chessboard based on the random factor 
    randomize_chessboard(chessboard, size, random_factor);
    // and print it
    print_chessboard(chessboard, size);

    // Ask the user for the magic square
    // Row and column are 0-based
    while ((row < 0) || (row>=size))
    {
        printf("Row: ");
        scanf("%d", &row);
    }

    while ((col < 0) || (col>=size))
    {
        printf("Col: ");
        scanf("%d", &col);
    }
    
    // Return the magic square index
    return row*size + col;
}



// Main function
int main() {
    // Creates the chessboard matrix
    int chessboard[BOARD_SIZE*BOARD_SIZE] = {0};

    // Prints the chessboard
    // print_chessboard(chessboard, BOARD_SIZE);

    // Asks the jailer for the magic square
    int magic_square = jailer(chessboard, BOARD_SIZE);

    // Prints the magic square
    printf("The selected magic square is: %d\n", magic_square);

    // Asks the first prisoner to flip a coin

    // Ask the second prisoner to guess the magic square

    // Prints the guessed magic square
    printf("The guessed magic square is: %d\n", guess);

    // Returns 0 to indicate success
    return 0;
}