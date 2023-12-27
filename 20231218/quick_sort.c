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
 * Partition the array in input using the pivot
 * @param [in] pivot pointer to the pivot
 * @param [in] low pointer to the first element of the array
 * @param [in] high pointer to the last element of the array
 * @return pointer to the pivot
**/
int* partition(int* pivot, int *low, int *high) {
    // Enter an infinite loop
    for(;;) {
        // Increment low while the value pointed
        // is less than the value of the pivot
        while (*low < *pivot) {
            // Increment the pointer
            low++;
        }
        // Decrement high while the value pointed
        // is greater or equal than the value of the pivot
        while (*high >= *pivot) {
            // Decrement the pointer
            high--;
        }
        // if low is less than high
        if (low<high){
            // swap the values pointed by low and high
            swap(low, high);
        // otherwise
        } else {
            // swap the values pointed by low and pivot
            swap(low, pivot);
            // return low
            return low;
        }
    }
}

/**
 * Sort the array in input using the quick sort algorithm
 * @param [in] v array to sort
 * @param [in] size size of the array
 * This function is recursive and uses the partition function
 * to divide the array in two parts and sort them
**/
void quick_sort_ptr(int* pivot, int* low, int* high){
    // if the size of the array is less than 1
    if (low<=high) {
        // compute the pivot using the partition function
        pivot = partition(pivot, low, high);

        // call the function recursively on the two parts
        quick_sort_ptr(pivot-1, low, pivot-2);
        quick_sort_ptr(high+1, pivot+1, high);
    }
}

/**
 * Sort the array in input using the quick sort algorithm
 * @param [in] v array to sort
 * @param [in] size size of the array
 * This function is used to call the recursive function
 * quick_sort_ptr that uses pointers to the array
**/
void quick_sort(int v[], int size) {
    // if the size of the array is less than 1
    if (size <= 1) {
        // terminate the procedure
        return;
    }
    // call the recursive function quick_sort_ptr
    // passing the pointers to the first and last element of the array
    return quick_sort_ptr(v+size-1, v, v+size-2);
}

// Main function
int main(void) {
	// Create the array to sort
    int v[] = {25, 14, 12, 5, 37, 29, 10, 7, 20, 17};
	// Compute the size of the array
    int size = sizeof(v)/sizeof(v[0]);
    printf("===============================================\n");
    printf("             QUICK SORT\n");
    printf("===============================================\n");

	// Print the unsorted array
    printf("Pre-order: ");
	print_array(v, size);

	// Sort the array
	quick_sort(v, size);

	// Print the sorted array
	printf("Post-order:");
	print_array(v, size);

	// Return 0 to indicate success
    return 0;
}