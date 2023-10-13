// Include the standard input/output library
#include <stdio.h>

// Function prototype or declaration (dichiarazione)
// two integers as input, an integer as output
int sum(int a, int b);

// Main function
void main() {
    // Define the 3 interger variables
    int a = 1, b = 2, c;

    // Ask the user to input the values of a
    printf("What's a?\n");
    scanf("%d", &a);

    // Ask the user to input the values of b
    printf("What's b?\n");
    scanf("%d", &b);

    // Call the function sum and save the result in c
    c = sum(a, b);
    // Print the result of summing c and 5
    printf("The result is: %d\n", sum(c, 5));
}

// Function definition (implementazione)
int sum(int x, int y)
{
    // Return the sum of x and y
    return x+y;
}