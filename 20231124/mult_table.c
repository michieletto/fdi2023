// mult_table.c
// Include the necessary libraries
#include <stdio.h>      // Input/output

// Define the minimum and maximum size of the table
#define MIN_SIZE 1
#define MAX_SIZE 10

/**
 * Ask the user for a size between MIN and MAX
 * @return the size
 * @note ask again until the user enters a number inside the range
**/
int ask_size() {
    // Declare a variable to hold the size
    int size;
    for(;;) {
        // Ask the user for a size between MIN and MAX
        printf("Enter a size between %d and %d: ", MIN_SIZE, MAX_SIZE);
        scanf("%d", &size);

        // If the size is inside the range
        if (!(size < MIN_SIZE || size > MAX_SIZE) ){
            // Return the size
            return size;
        }
        // Otherwise, print an error message and ask again
        printf("Size out of range\n");
    }
}

/**
 * Fill the multiplication table
 * @param [inout] table the table to fill
 * @param [in] size the size of the table
**/
void fill_table(int table[], int size) {
    // For each row
    for (int i = 0; i < size; i++) {
        // For each column
        for (int j = 0; j < size; j++) {
            // Fill the table
            table[i*size + j] = (i+1)*(j+1);
        }
    }
}

/**
 * Print the multiplication table
 * @param [in] table the table to print
 * @param [in] size the size of the table
**/
void print_table(int table[], int size) {
    // For each row
    for (int i = 0; i < size; i++) {
        // For each column
        for (int j = 0; j < size; j++) {
            // Print the value
            printf("%d\t", table[i*size + j]);
        }
        // Print a new line at the end of the row
        printf("\n");
    }
}

// Main function
int main() {
    // Declare a variable to hold the size
    int size = ask_size();

    // Declare an array to hold the table
    int table[size*size];

    // Fill the table
    fill_table(table, size);

    // Print the table
    print_table(table, size);

    // Return 0 to indicate success
    return 0;
}