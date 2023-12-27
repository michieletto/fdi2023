#include <stdio.h>       // Library for printf

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
 * Sort the array in input using the selection sort algorithm
 * @param [in] v array to sort
 * @param [in] size size of the array
**/
void selection_sort(int v[], int size) {
	// Iterate over the array from 0 to size-1
	for (int next=0; next < size-1; next++) {
        // Look for the minimum value in the array
		int min_index = next;
		// Iterate over the array from next+1 to size
		for (int i = next+1; i < size; i++) {
			// If the value in position i is less than the value in position min_index
			if (v[i] < v[min_index]){
				// Update the index of the minimum value
				min_index = i;
			}
        }
		// Swap the value in position next with the value in position min_index
		swap(&v[next], &v[min_index]);
	}
}

// Main function
int main(void) {
	// Create the array to sort
    int v[] = {25, 14, 12, 5, 37, 29, 10, 7, 20, 17};
	// Compute the size of the array
    int size = sizeof(v)/sizeof(v[0]);
    printf("===============================================\n");
    printf("             SELECTION SORT\n");
    printf("===============================================\n");

	// Print the unsorted array
    printf("Pre-order: ");
	print_array(v, size);

	// Sort the array
	selection_sort(v, size);

	// Print the sorted array
	printf("Post-order:");
	print_array(v, size);

	// Return 0 to indicate success
    return 0;
}