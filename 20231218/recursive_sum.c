#include <stdio.h>       // Library for printf

/**
 * Recursively sum two numbers
 * @param [in] a first number
 * @param [in] b second number
 * @return the sum of the two numbers
 * @note this function is recursive
 * so it calls itself inside the function body
 * by changing the input parameters to go towards the base case
 * @note the base case is when b is equal to 0
**/
int sum(int a, int b) {
    // base case: b is equal to 0
    // so no sum is needed 
    if (b == 0) {
        // and the result is a
        return a;
    }

    // step case: b is not equal to 0
    // so we need to modify the input parameters
    // to go towards the base case
    // we can do this by increasing a and decreasing b
    a++;
    b--;

    // recursion: we have modified the input parameters
    // and we can return the result of the function
    // called again with the new parameters
    return sum(a,b);
}

// Main function
int main() {
    // Print the sum of 3 and 2
    printf("3+2 = %d\n", sum(3,2));

    // Return 0 to indicate success
    return 0;
}
