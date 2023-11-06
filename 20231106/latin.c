// Include the standard input/output library
#include <stdio.h>
// Include the standard boolean library
#include <stdbool.h>
// Include the standard math library
#include <math.h>

// Function to check if a square is latin
bool is_latin(int square[], int size) {
    // Define an array of boolean to keep track
    // of the numbers we are finding in the rows
    // The array has size elements, and it varies
    // depending on the actual size of square in input
    // This kind of array is called a variable-length array
    // and it cannot be initialized at declaration
    bool check_rows[size];

    // Check all the rows
    for (int index_row = 0; index_row < size; index_row++) {
        // Initialize the flag array to false
        for (int i=0; i < size; i++) {
            check_rows[i] = false;
        }

        // Check each element in the row
        for (int index_col = 0; index_col < size; index_col++) {
            // Get the value of the element, and subtract 1
            // because the values in the square are in the range [1, size]
            // but the array indexes are in the range [0, size-1]
            int value_row = square[index_row*size+index_col] - 1;
            // Check if the value is out of range or if it has already been found
            if ((value_row<0) || (value_row >= size) || check_rows[value_row]) {
                // If so, the square is not latin
                return false;
            }
            // Otherwise, mark the value as found
            check_rows[value_row] = true;
        }
    }

    // After checking all the rows, we need to do the same for the columns

    // Define an array of boolean to keep track
    // of the numbers we are finding in the columns
    // We could reuse the same array as before, 
    // but for simplicity we define a new one
    bool check_cols[size];

    // Check all the columns
    for (int index_col = 0; index_col < size; index_col++) {
        // Initialize the flag array to false
        for (int i=0; i < size; i++)
        {
            check_cols[i] = false;
        }

        // Check each element in the column
        for (int index_row = 0; index_row < size; index_row++) {
            // Get the value of the element
            // The index of the element  in the matrix
            // is computed in the same way as before
            int value_col = square[index_row*size+index_col] - 1;
            // Check if the value is out of range or if it has already been found
            if ((value_col<0) || (value_col >= size) || check_cols[value_col]) {
                // If so, the square is not latin
                return false;
            }
            // Otherwise, mark the value as found
            check_cols[value_col] = true;
        }
    }

    // If we reach this point, the square is latin
    // since all the rows and columns have been checked
    return true;
}

// Function to swap two rows in a square
void swap_row(int square[], int size, int row_from, int row_to){
    // Define a temporary integer variable
    int temp;

    // Swap each element in the rows
    for (int j = 0; j < size; j++)
    {
        // Swap the element at index j in the two rows
        // one value is stored in the temporary variable
        temp = square[row_from*size+j];
        // The other value is moved to the position of the first
        square[row_from*size+j] = square[row_to*size+j];
        // The value in the temporary variable is moved to the position of the second
        square[row_to*size+j] = temp;
    }
}

// Function to swap two columns in a square
void swap_col(int square[], int size, int col_from, int col_to){
    // Define a temporary integer variable
    int temp;

    // Swap each element in the columns
    for (int i = 0; i < size; i++)
    {
        // Swap the element at index i in the two columns
        // one value is stored in the temporary variable
        temp = square[i*size+col_from];
        // The other value is moved to the position of the first
        square[i*size+col_from] = square[i*size+col_to];
        // The value in the temporary variable is moved to the position of the second
        square[i*size+col_to] = temp;
    }
}

// Function to print a matrix
void print_matrix(int square[], int size) {
    // For each row
    for (int i = 0; i < size; i++)
    {
        // and for each column
        for (int j = 0; j < size; j++)
        {
            // Print the value at the current position
            printf(" %d", square[i*size+j]);
        }
        // Print a newline at the end of each row
        printf("\n");
    }
}

// Function to reduce a latin square
void reduce(int square[], int size) {
    // check each column and swap if necessary
    printf("check cols\n");
    // we use a for loop with an empty update condition
    for (int i = 0; i < size;)
    {
        // debug print
        printf("index: %d     square[%d]: %d\n", i, i, square[i]-1);
        print_matrix(square, size);
        // if the value at index i is i+1, then the column is ok
        if ((square[i]-1) == i) {
            // move to the next column
            i++;
        } else {
            // otherwise, swap the current column with the one containing the value i+1
            swap_col(square, size, i, square[i]-1);
        }
    }
    // check each row and swap if necessary
    // we use a for loop with an empty update condition
    printf("check rows\n");
    for (int i = 1; i < size;)
    {
        // debug print
        printf("index: %d     square[%d]: %d\n", i, i, square[i*size]-1);
        print_reduced(square, size);
        // if the value at index i is i+1, then the row is ok
        if ((square[i*size]-1) == i)
            // move to the next row
            i++;
        else
            // otherwise, swap the current row with the one containing the value i+1
            swap_row(square, size, i, square[i*size]-1);
    }

}

int main() {
    // Define a variable to store the size of the matrix
    int size = 0;

    // Ask the user for the size of the matrix
    for(;;) {
        printf("Size?\n");
        scanf("%d", &size);
        if (size>0) {
            break;
        }
    }
    
    // Define an array to store the input matrix
    // using a variable-length array to define the size
    // of the array at runtime based on the user input
    int square[size*size];

    // Ask the user for the values of the matrix
    // using a nested for loop to traverse the matrix
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("Element at square[%d][%d]: ", i, j);
            scanf("%d", &square[i*size+j]);
        }
        printf("\n");
    }

    // Check if the matrix is latin
    bool valid = is_latin(square, size);

    // Print the result using a ternary operator
    printf("The square is %s\n", valid ? "latin" : "not latin");

    // Reduce the matrix if it is latin
    if (valid) {
        // Call the reduce function
        reduce(square, size);
        // Print the reduced matrix
        printf("\nThe reduced matrix is:\n");
        print_reduced(square, size);
    }    

    return 0;
}