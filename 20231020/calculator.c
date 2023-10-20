// Include the standard input/output library
#include <stdio.h>

// Main function
int main() {
    // Define a character variable
    // to store the user input
    char next_operation;
    // Ask the user for the next operation
    printf("What's next operation? (+,-,*,/,%%)\n");
    scanf("%c", &next_operation);

    // Define two integer variables
    int x, y;
    //  Ask the user for x
    printf("What's x?\n");
    scanf("%d", &x);
    //  Ask the user for y
    printf("what's y?\n");
    scanf("%d", &y);

    // Define a variable to store the result
    int res = 0;
    
    // Compute the result based on the required operation
    // using a cascade of if-else statements
    if(next_operation == '+') {
        res = x + y;
    } else if(next_operation == '?') {
        res = x - y;
    }else if(next_operation == '-') {
        res = x - y;
    } else if(next_operation == '*') {
        res = x * y;
    } else if(next_operation == '/') {
        res = x / y;
    } else if(next_operation == '%') {
        res = x % y;
    }

    // Print the result obtained by using if-else statements
    printf("[IF]The result of x %c y = %d\n", next_operation, res);

    // Compute the result based on the required operation
    // using a switch statement
    // next_operation is the variable to switch on
    // and it needs to be an integer-based type
    switch (next_operation)
    {
    // Each case is a possible value of next_operation
    case '+':    
        // the code after the case is executed 
        // if next_operation is EQUAL to the value
        res = x + y;
        // the break statement is used to exit the switch
        break;
    case '?':
        // if no break is used, the code continues
        // to the next case until a break is found
        // or the end of the switch is reached
    case '-':
        res = x - y;
        break;
    case '*':
        res = x*y;
        break;
    case '/':
        res = x/y;
        break;
    case '%':
        res = x%y;
        break;
    // the default case is executed if no other case is matched
    default:
        res = 0;
        break;
    }

    // Print the result obtained by using a switch statement
    printf("[SWITCH]The result of x %c y = %d\n", next_operation, res);

    // Return 0 to indicate success
    return 0;
}