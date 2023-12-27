#include <stdio.h>       // Library for printf
#include <string.h>      // Library for memcpy

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
 * Merge two sorted arrays
 * @param [in] v1 first array to merge
 * @param [in] size1 size of the first array
 * @param [in] v2 second array to merge
 * @param [in] size2 size of the second array
**/
void merge_again(int* v1, int size1, int *v2, int size2) {
    // Create two temporary arrays
    int v1_tmp[size1];
    int v2_tmp[size2];
    // Copy the content of the arrays in the temporary arrays
    memcpy(&v1_tmp, v1, size1*sizeof(int));
    memcpy(&v2_tmp, v2, size2*sizeof(int));

    // Keep track of the index of the first, second, and merge array
    int first=0, second=0, merge=0;
    // Iterate over the arrays until one of them is finished
    while(first<size1 && second<size2) {
        // If the value in the first array is less than the value in the second array
        if(v1_tmp[first] < v2_tmp[second]) {
            // Copy the value in the first array in the merge array
            v1[merge] = v1_tmp[first];
            // Increment the index of the first array
            first++;
        // Otherwise
        } else {
            // Copy the value in the second array in the merge array
            v1[merge] = v2_tmp[second];
            // Increment the index of the second array
            second++;
        }
        // Increment the index of the merge array in any case
        merge++;
    }
    // If the first array is not finished
    if(first<size1) {
        // Copy the remaining values in the merge array
        memcpy(v1+merge, v1_tmp+first, (size1-first)*sizeof(int));
    }
    // If the second array is not finished
    if(second<size2) {
        // Copy the remaining values in the merge array
        memcpy(v1+merge, v2_tmp+second, (size2-second)*sizeof(int));
    }
}

/**
 * Merge sort the array in input
 * @param [in] start pointer to the first element of the array
 * @param [in] end pointer to the last element of the array
 * the function is recursive and it is called dividing the array in two parts
 * until the size of the array is less than 2
**/
void merge_sort_ptr(int* start, int* end){
    // If the size of the array is less than 2
    if (start<end) {
        // Compute the middle of the array
        int *middle = start + (end-start)/2;
        // Call the function recursively on the two parts
        merge_sort_ptr(start, middle);
        merge_sort_ptr(middle+1, end);
        
        // Merge the two parts once they are sorted
        merge_again(start, middle-start+1, middle+1, end-middle);
    }
}

/**
 * Sort the array in input using the merge sort algorithm
 * @param [in] v array to sort
 * @param [in] size size of the array
 * This function is used to call the merge_sort_ptr function
 * that is recursive and uses pointers to the array to sort it
**/
void merge_sort(int v[], int size) {
    // If the size of the array is less than 2
    if (size <= 1) {
        // Return immediately since the array is already sorted
        return;
    }
    // Call the function that uses pointers to the array
    return merge_sort_ptr(v, v+size-1);
}

// Main function
int main(void) {
	// Create the array to sort
    int v[] = {25, 14, 12, 5, 37, 29, 10, 7, 20, 17};
	// Compute the size of the array
    int size = sizeof(v)/sizeof(v[0]);
    printf("===============================================\n");
    printf("             MERGE SORT\n");
    printf("===============================================\n");

	// Print the unsorted array
    printf("Pre-order: ");
	print_array(v, size);

	// Sort the array
	merge_sort(v, size);

	// Print the sorted array
	printf("Post-order:");
	print_array(v, size);

	// Return 0 to indicate success
    return 0;
}