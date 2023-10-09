// include the standard input/output header file
#include <stdio.h>

// Main function
void main() {
    // Define 2 integer variables 
    int a = 1;
    int b = 6;

    // Ask the user to input the value of a
    printf("What's the value of a?\n");
    scanf("%d", &a);

    // Ask the user to input the value of b
    printf("What's the value of b?\n");
    scanf("%d", &b);

    // Sum a and b and store the result in c
    int c = a + b;

    /* Print the result of sum 
       between a and b
    */    
    printf("The result of the sum between a:%d and b:%d is c:%d\n", a, b, a+b);
}