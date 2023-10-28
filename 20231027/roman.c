// Include the standard input/output library
#include <stdio.h>

// Define the roman digits using an enum so that
// at each digit we can associate the corresponding value
enum roman_digits {
    // M is 1000, 
    M = 1000,
    // D is 500
    D = 500,
    // C is 100
    C = 100,
    // L is 50
    L = 50,
    // X is 10
    X = 10,
    // V is 5
    V = 5,
    // I is 1
    I = 1,
    // plus a special value for not valid digits
    // we use 0 because it is not a valid value for a digit
    // another option would be to use -1 or any other negative value
    NOT_VALID = 0,
}; // <-- Don't forget the semicolon!

// Function to print all the values of the enum
void print_all_values(){
    // Just print the values of each option of the enum
    // Note that we can use the enum values as integers
    printf("The value of M is %d\n", M);
    printf("The value of D is %d\n", D);
    printf("The value of C is %d\n", C);
    printf("The value of L is %d\n", L);
    printf("The value of X is %d\n", X);
    printf("The value of V is %d\n", V);
    printf("The value of I is %d\n", I);
    // so we can also print the value of NOT_VALID
    printf("The value of NOT_VALID is %d\n", NOT_VALID);
}

// Function to convert a digit to its corresponding value
// We use a char as input because we want to convert a single digit
// We use an enum as output because we want to return the corresponding value
enum roman_digits convert_digit(char digit) {
    // We try using a for loop to convert the digit
    // We use a string to store the valid digits
    char valid_digits[] = "MDCLXVI";
    // and an array to store the corresponding values
    int converted_digits[] = {1000, 500, 100, 50, 10, 5, 1};

    // We all the valid digits
    for (int i = 0; i < 7; i++)
    {
        // If the digit is found
        if (digit == valid_digits[i]) {
            // return the corresponding value
            return converted_digits[i];
        }
        // Otherwise, continue the loop
    }
    
    // If the digit is not found, return 0
    return 0;
}

// Function to convert a digit to its corresponding value
// This time we use a switch statement
// but input and output are the same as before
// The switch statement is more efficient than the for loop
// because it does not need to check all the digits
// plus it is more readable and usually easier to understand
// It is often used when we have an enum 
enum roman_digits convert_digit_switch(char digit) {
    // We use a switch statement to convert the digit
    switch (digit)
    {
    // each case corresponds to a valid digit
    case 'M':
        // and returns the corresponding value in the enum
        return M;
    case 'D':
        return D;
    case 'C':
        return C;
    case 'L':
        return L;
    case 'X':
        return X;
    case 'V':
        return V;
    case 'I':
        return I;
    // if the digit is not found in the valid cases
    default:
        // return the special value NOT_VALID
        return NOT_VALID;
    }
}

// Main function
int main() {
    // Print all the values of the enum
    print_all_values();

    // Define a digit to test the conversion functions
    char c = 'X';
    
    // Print the value of the digit
    // using the first conversion function (for loop)
    printf("\n\nThe value of %c is %d\n", c, convert_digit(c));
    // using the second conversion function (switch statement)
    printf("\n\nThe value of %c is %d\n", c, convert_digit_switch(c));

    // Return 0 to indicate success
    return 0;
}