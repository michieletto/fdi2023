#include <stdio.h>

// Function that sums two integers
// and decrements the first integer
// and returns the sum
// Unfortunatelly this function does not work properly
// because the value of a is not updated
// because the function is working on a copy of the value
// and not on the actual value
// and the copy is destroyed after the function returns
// even though the value of a is decremented
int wrong_sum_and_update(int a, int b) {
    int c = a+ b;
    a--;
    printf("Now the value of a is %d\n", a);
    return c;
}

// Function that sums two integers
// and decrements the first integer
// and returns the sum
// This function works properly
// because the function is working on the actual value
// and not on a copy of the value
// by accessing the address of the variable
int sum_and_update(int *a, int b) {
    int c = (*a) + b;
    (*a)--;
    return c;
}

// Main function
int main() {
    // Declare two integers
    int a = 5;
    int b = 3;

    // WRONG FUNCTION
    // Print the value of the sum of the two integers
    printf("The value of a + b is %d\n", wrong_sum_and_update(a,b));
    // Print the "NEW" value of a
    printf("The NEW value of a is %d\n", a);

    // Print the value of the sum of the two integers
    printf("The value of a + b is %d\n", sum_and_update(&a,b));
    // Print the NEW value of a
    printf("The NEW value of a is %d\n", a);

    // Return 0 to indicate success
    return 0;
}