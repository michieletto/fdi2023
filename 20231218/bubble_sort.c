#include <stdio.h>       // Library for printf
#include <stdbool.h>     // Library for boolean variables

/**
 * Print the array on the screen
 * @param [in] v array to print
 * @param [in] size size of the array
**/
void print_array(int v[], int size) {
	// Start the printing with the opening square bracket
	printf("[");
	// Iterate over the array
	for (int i=0; i < size; i++) {
		printf(" %d", v[i]);
	}
	// Close the printing with the closing square bracket
	printf(" ]\n");
}

/**
 * Swap the values of two variables
 * @param [in] a pointer to the first variable
 * @param [in] b pointer to the second variable
 * the values of the two variables can be modified
 * since the pointers are passed and not the values
**/
void swap(int *a, int* b) {
	// Temporary variable to store the value of a
    int temp = *a;
	// Copy the values of b in a
    *a = * b;
	// End the swap by copying the value of a in b
    *b = temp;
}

/**
 * Sort the array in input using the bubble sort algorithm
 * @param [in] v array to sort
 * @param [in] size size of the array
*/
void bubble_sort(int v[], int size) {
    // iterate over the array from 0 to size-1
    for (int step = 0; step < size - 1; step++) {
        // keep track of swapped elements
        bool swapped = false;
        // iterate over the array from 0 to size-step-1
        for (int current = 0; current < size - step - 1; current++) {
            // calculate the index of the next element
            int next = current + 1;
            // if the current element is greater than the next
            if (v[current] > v[next]) {
                // swap the elements
                swap(&v[current], &v[next]);
                // set the flag to true
                swapped = true;
            }
        }
        // if no elements were swapped
        if (!swapped) {
            // terminate the procedure
            return;
        }
    }
}

// Main function
int main(void) {
	// Create the array to sort
    int v[] = {25, 14, 12, 5, 37, 29, 10, 7, 20, 17};
	// Compute the size of the array
    int size = sizeof(v)/sizeof(v[0]);
    printf("===============================================\n");
    printf("             BUBBLE SORT\n");
    printf("===============================================\n");

	// Print the unsorted array
    printf("Pre-order: ");
	print_array(v, size);

	// Sort the array
	bubble_sort(v, size);

	// Print the sorted array
	printf("Post-order:");
	print_array(v, size);

	// Return 0 to indicate success
    return 0;
}