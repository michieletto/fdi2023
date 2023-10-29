// Include the standard input/output library
#include <stdio.h>
// Include the standard boolean library
#include <stdbool.h>

// Define the roman digits by using an enum
enum roman_digits {
    // Each roman digit is associated to a value
    M = 1000,
    D = 500,
    C = 100,
    L = 50,
    X = 10,
    V = 5,
    I = 1,
    // The last value is used to indicate
    // that the roman digit is not valid
    NOT_VALID = 0,
};

// Function to convert a digit to its corresponding value
enum roman_digits convert_digit_switch(char digit) {
    // We use a switch statement to convert the digit
    switch (digit)
    {
    // each case corresponds to a valid digit
    case 'M':
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
    }
    // If the digit is not valid, return NOT_VALID
    return NOT_VALID;
}

// Function to check if a roman number is valid
// The roman number is passed as a string
// the variable input is an array of characters
// indicated by the square brackets []
// a string is terminated by the end of string character '\0'
// REMEBER
// by hypothesis, our definition of roman number requires
// that higher digits are always on the left of lower digits
bool is_valid(char input[]) {
    // Define an array of valid roman digits
    char valid_digits[] = "MDCLXVI";
    // Index to traverse the input string
    int index_input = 0;
    // Index to traverse the string of the valid digits
    int index_valid=0;
    // Traverse the input string and the valid digits string
    // The loop stops when the end of the input string is reached
    // or when the end of the valid digits string is reached
    while (input[index_input] != '\0' && valid_digits[index_valid] != '\0')
    {
        // Check if the current character of the input string 
        // is equal to the current character of the accepted string
        if (input[index_input] == valid_digits[index_valid]){
            // If so, increment the index of the input string
            index_input++;
        } else {
            // Otherwise, increment the index of the accepted string
            index_valid++;
        }
        // The previous if-else statement can be written in a single line
        // by using the ternary operator (operatore condizionale)
        input[index_input] == valid_digits[index_valid] ? index_input++ : index_valid++;
    }

    // If the input string is finished, then the roman number is valid
    return input[index_input] == '\0';
}

// Function to convert a roman number to its value
int get_roman_value(char input[]) {
    // Index to traverse the input string
    int index_input = 0;
    // Variable to store the value of the roman number
    int roman_value = 0;
    // Variable to store the value of the last digit
    // First option
    enum roman_digits last_digit = M;
    // Second option
    last_digit = NOT_VALID;

    // Traverse the input string
    while (input[index_input] != '\0')
    {
        // Convert the current digit to its value
        enum roman_digits digit_value = convert_digit_switch(input[index_input]);
        // Check if the digit is valid
        // and if it is in the right order compared to the previous digit
        // exepct for the first digit (last_digit == NOT_VALID)
        if ((digit_value == NOT_VALID) || ((last_digit != NOT_VALID) && (digit_value > last_digit)))
        {
            return NOT_VALID;
        }
        // Add the value of the digit to the roman number
        roman_value += digit_value;
        // Update the value of the last digit
        last_digit = digit_value;
        // Increment the index of the input string
        index_input++;
    }   

    // Return the value of the roman number
    return roman_value;
}


// Main function
int main() {
    // Define a string to store the user input
    // The string is initialized with zeros, so it is empty
    char input[256] = {0};
    // Variable to store the value of the roman number
    int roman_value;

    for(;;) {
        // Ask the user to insert a roman number
        printf("Roman: ");
        scanf("%s", input);

        // Check if the roman number is valid
        // by following the first solution suggested in class
        // and print a message to the user accordingly
        if (is_valid(input)) {
            printf("Valid number\n");
        } else {
            printf("Not valid, please insert a new number!\n");
        }
        // Compute the value of the roman number
        // by following the second solution suggested in class
        roman_value = get_roman_value(input);
        // and select the action to perform based on the result
        if (roman_value != NOT_VALID)
            break;
    }

    // Print the value of the roman number
    printf("The value of %s is %d\n", input, roman_value);

    // Return 0 to indicate success
    return 0;
}