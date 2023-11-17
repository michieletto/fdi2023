// Include the standard input/output library
#include <stdio.h>

// Print the array in reverse order
// Iterate over the array in reverse order
// using the size as the index
// and decrementing it at each iteration
void print_reverse(int array[], int size) {
    printf("[ ");
    for (; size > 0; size--) {
        printf("%d ", array[size-1]);
    }
    printf("]\n");
}

// Print the array in reverse order
// using a pointer to the array
// the rest of the code is the same
// as the previous function
void print_reverse_ptr(int *array, int size) {
    printf("[ ");
    for (; size > 0; size--) {
        printf("%d ", array[size-1]);
    }
    printf("]\n");
}

// Print the array in reverse order
// using a pointer to the array
// but this time we use the pointer math
// to iterate over the array
void print_ptr_reverse_ptr(int *array_ptr, int size) {
    printf("[ ");
    // we define a pointer to the end of the array
    // and we decrement it at each iteration
    // until we reach the beginning of the array
    // the operator -- moves the pointer to the previous element
    // in memory by subtracting the size of the element each time
    // the operator >= compares the address of the pointers
    // and returns true if the first pointer is greater or equal
    // to the second pointer, which is located at the beginning of the array
    // this allows us to iterate over the array in reverse order
    for (int* array_end = array_ptr + size - 1; array_end >= array_ptr; array_end--) {
        printf("%d ", *array_end);
    }
    printf("]\n");
}

// Print the array in reverse order
// by passing the array as usual
// the rest of the code is the same
// as the previous function
// so we use the pointer math 
// and apply it to the array
void print_ptr_reverse(int array_ptr[], int size) {
    printf("[ ");
    int* array_end = NULL;
    if(array_ptr != NULL)
        array_end = array_ptr + size;
    for (; array_end > array_ptr; array_end--) {
        printf("%d ", *(array_end-1));
    }
    printf("]\n");
}

// Main function
int main() {
    // Define a generic integer array
    int array[] = {5, 18, 42, 13, 9, 4, 61};
    // Get the size of the array
    // by using the sizeof operator
    // which returns the size of the array in bytes
    // and divide it by the size of an integer
    // to get the number of elements in the array
    int size = sizeof(array)/sizeof(int);
    // Print the size of the array to check if it's correct
    printf("The size of the array is %d\n", size);
    // Print the array in reverse order
    // by using the different functions
    // defined above to see the differences
    print_reverse(array, size);
    print_reverse_ptr(array, size);
    print_ptr_reverse_ptr(array, size);
    print_ptr_reverse(array, size);

    // Return 0 to indicate success
    return 0;
}