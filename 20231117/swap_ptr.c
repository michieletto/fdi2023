// Include the standard input/output library
#include <stdio.h>

// Wrong implementation of the swap function
// using the values of the integers
// instead of their addresses
// even though the function swaps the values
// the values of the integers in the main function
// are not swapped because the function
// is working on copies of the values
// and not on the actual values
// and the copies are destroyed after the function returns
void wrong_swap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

// Wrong implementation of the swap function using pointers
// even though the function swaps the values of the pointers
// the values of the pointers in the main function are not swapped
// because the function is working on copies of the pointers
// and not on the actual pointers
// plus swapping the pointers does not swap the values
// in the array because the pointers are not pointing to the array
void wrong_swap_ptr(int *a_ptr, int *b_ptr) {
    int *temp_ptr = a_ptr;
    a_ptr = b_ptr;
    b_ptr = temp_ptr;
}


// Swap two integers using pointers
void swap_ptr(int* a_ptr, int* b_ptr) {
    // We use a temporary variable to store the value of the first integer
    int temp = *a_ptr;
    // We assign the value of the second integer to the first integer
    *a_ptr = *b_ptr;
    // We assign the value of the temporary variable to the second integer
    *b_ptr = temp;
}

// Print the array
void print_array(int a[], int size) {
    printf("[ ");
    for (size_t i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("]\n");
}

// Main function
int main() {
    // Declare an array of integers
    int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    // and get its size
    int size = sizeof(array)/sizeof(array[0]);

    // Print the array before swapping
    print_array(array, size);
    // Iterate over the first half of the array
    // otherwise we will swap the elements twice
    for (int i = 0; i < size/2; i++) {
        // Swap the current element with the element
        // at the opposite index in the array
        swap_ptr(&array[i], &array[size-1-i]);
    }
    // Print the array after swapping
    print_array(array, size);

    // Return 0 to indicate success
    return 0;
}