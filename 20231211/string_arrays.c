// Includes the standard input/output library
#include <stdio.h>
// Includes the string library (for strcpy function)
#include <string.h>
// Includes the standard library (for malloc function)
#include <stdlib.h>

// Defines the maximum length of a color name
#define MAX_COLOR_NAME_LEN 5
// Defines the number of colors
#define NUM_COLORS 6

// Using typedef to define a new type
// string, that is a pointer to a char
typedef char* string;

// Main function
int main() {
    // Defines an array of strings as a matrix of chars
    // by dynamically allocating memory for the matrix 
    // as a single block of memory of total size 
    // NUM_COLORS*(MAX_COLOR_NAME_LEN+1)*sizeof(char)
    // (the +1 is for the null terminator)
    // by doing so, we separate the allocated memory
    // in NUM_COLORS blocks of MAX_COLOR_NAME_LEN+1 chars
    // indipedently of the number of chars in each string
    string color_matrix = (string)malloc(NUM_COLORS*(MAX_COLOR_NAME_LEN+1)*(sizeof(char)));
    // Checks if the allocation was successful
    if (color_matrix == NULL) {
        // If not, terminates the program with error code 1
        return 1;
    }
    // Use strcpy to copy the strings into the allocated memory
    strcpy(color_matrix+0*(MAX_COLOR_NAME_LEN+1), "black");
    strcpy(color_matrix+1*(MAX_COLOR_NAME_LEN+1), "white");
    strcpy(color_matrix+2*(MAX_COLOR_NAME_LEN+1), "red");
    strcpy(color_matrix+3*(MAX_COLOR_NAME_LEN+1), "green");
    strcpy(color_matrix+4*(MAX_COLOR_NAME_LEN+1), "blue");
    strcpy(color_matrix+5*(MAX_COLOR_NAME_LEN+1), "");

    // Defines an array of strings as an array of pointers to chars
    // by dynamically allocating memory for the array of pointers
    // as a single block of memory of total size NUM_COLORS*sizeof(string)
    string *array_of_pointes = (string*)malloc(NUM_COLORS*(sizeof(string)));
    // Checks if the allocation was successful
    if (array_of_pointes == NULL) {
        // If not, terminates the program with error code 1
        return 1;
    }   
    // and then, for each string, by dynamically allocating memory
    // for the string as a single block of memory of exactly the size needed
    // by doing so, we separate the allocated memory in two blocks:
    // the first one is an array of NUM_COLORS pointers to chars
    // the second one is a set of NUM_COLORS blocks of memory of variable size
    for(int i=0; i<NUM_COLORS; i++) {
        // Allocates memory for each string of exactly the size needed 
        // the size needed is the length of the string to copy plus 1 for the null terminator
        // we start from the matrix of chars, and we move to the i-th string
        // then we use the strlen function to get the length of the string
        // that returns the number of chars before the null terminator
        // then we add 1 to get the total size needed (including the null terminator)
        array_of_pointes[i] = (string)malloc(strlen(color_matrix+i*(MAX_COLOR_NAME_LEN+1))+1*(sizeof(char)));
        // Checks if the allocation was successful
        if (array_of_pointes[i] == NULL) {
            // If not, terminates the program with error code 1
            return 1;
        }
        // Use strcpy to copy the strings into the allocated memory
        strcpy(array_of_pointes[i], color_matrix+i*(MAX_COLOR_NAME_LEN+1));
    }
    
    // Prints the strings using the two different methods
    // and some useful information about the strings format
    printf("COLOR MATRIX:\n");
    for(int i=0; i<NUM_COLORS; i++) {
        printf("%d. %s (sizeof: %ld, strlen: %ld)\n", i, color_matrix+i*(MAX_COLOR_NAME_LEN+1), (MAX_COLOR_NAME_LEN+1)*sizeof(char), strlen(color_matrix+i*(MAX_COLOR_NAME_LEN+1)));
    }

    printf("ARRAY OF CHAR POINTERS:\n");
    for(int i=0; i<NUM_COLORS; i++) {
        printf("%d. %s (sizeof: %ld, strlen: %ld)\n", i, array_of_pointes[i], (strlen(array_of_pointes[i])+1)*sizeof(char), strlen(array_of_pointes[i]));
    }
}