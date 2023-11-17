// Include the standard input/output library
#include <stdio.h>

// Define the number of elements in the array
#define NUM_ELEMS 10

// Get the maximum value in the array
// using a pointer to element in the array
int* get_max(int numbers[], int size) {
    // Define a pointer to the first element in the array
    int* max_ptr = &numbers[0];
    // Print the value pointed by the pointer
    printf("*max_ptr: %d\n", *max_ptr);
    // Print the address saved in the pointer
    printf("max_ptr: %p\n", max_ptr);
    
    // Iterate over the array
    for (int i = 1; i < size; i++) {
        // If the value of the current element is greater
        // than the value pointed by max_ptr
        // aka the maximum value in the array so far
        if (numbers[i] > *max_ptr) {
            // Assign the address of the current element
            max_ptr = &numbers[i];
            // Print the value pointed by the pointer
            printf("*max_ptr: %d\n", *max_ptr);
            // Print the address saved in the pointer
            printf("max_ptr: %p\n", max_ptr);
        }
    }
    // Print the value pointed by the pointer
    printf("*max_ptr: %d\n", *max_ptr);
    // Print the address saved in the pointer
    printf("max_ptr: %p\n", max_ptr);

    // Return the pointer to the maximum value in the array
    return max_ptr;
}

// Main function
int main() {
    // Declare an array of integers
    int a[NUM_ELEMS] = {0, 25, 10, 18, 44, 16, 33};

    // Get the pointer to the maximum value in the array
    int* max_ptr = get_max(a, NUM_ELEMS);
    // Print the value pointed by the pointer
    printf("*max_ptr: %d\n", *max_ptr);
    // Print the address saved in the pointer
    printf("max_ptr: %p\n", max_ptr);

    return 0;
}