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

/**
 * Compute the parity of the chessboard
 * @param chessboard[in] The chessboard as set by the jailer
 * @param size[in] The size of the chessboard
 * @return The parity of the chessboard
 * Compute the parity of the chessboard as the sum of the 
 * number of coins in each row and column modulo 2
 * The parity is a number between 0 and 63
*/
int parity(int chessboard[], int size) {

}

/**
 * Flip a coin on the chessboard
 * @param chessboard[inout] The chessboard as set by the jailer
 * @param size[in] The size of the chessboard
 * @param to_flip[in] The index of the coin to flip
 * Flip the coin on the chessboard at the given index (to_flip)
*/
void flip(int chessboard[], int size, int to_flip) {
    
}

/**
 * Ask the first prisoner to flip a coin
 * @param chessboard[inout] The chessboard as set by the jailer
 * @param size[in] The size of the chessboard
 * @param magic_square[in] The magic square as set by the jailer
 * Modify the chessboard to flip a coin and let the second 
 * prisoner guess the magic square
**/
void first_prisoner(int chessboard[], int size, int magic_square) {

}

/**
 * Ask the second prisoner to guess the magic square
 * @param chessboard[in] The chessboard as modified by the first prisoner
 * @param size[in] The size of the chessboard
 * @return The guessed magic square
 * Guess the magic square based on the changes made by the first prisoner
**/ 
int second_prisoner(int chessboard[], int size) {

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
    first_prisoner(chessboard, BOARD_SIZE, magic_square);

    // Ask the second prisoner to guess the magic square
    int guess = second_prisoner(chessboard, BOARD_SIZE);

    // Prints the guessed magic square
    printf("The guessed magic square is: %d\n", guess);

    // Returns 0 to indicate success
    return 0;
}