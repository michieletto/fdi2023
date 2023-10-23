// Include the standard input/output library
#include <stdio.h>

// Constant to define the size of the array
#define N 10

// Main function
int main() {
    // Define an array of integers
    int a_casual[N]; // Casual values
    int a_different[N] = {43, 18, 22, 3, 46, 15, 27, 64, 98, 0}; // All different values
    int a_zeros[N] = {0}; // All zeros
    int a_start[N] = {1, 2, 3}; // Just the first three values are initialized, the rest are zeros
    int a[N] = {[1]=1, [4]= 2, [9]=3}; // Just the values at index 1, 4 and 9 are initialized, the rest are zeros

    // Traverse the array
    for (int i = 0; i < N; i++)
    {
        // Print the value of the i-th element
        printf("Before: a[%d] = %d\n", i, a[i]);
        // Update the value of the i-th element
        a[i] = N - i + 1;
        // Print the value of the i-th element (again)
        printf("After: a[%d] = %d\n", i, a[i]);
    }    

    // Return 0 to indicate success
    return 0;
}