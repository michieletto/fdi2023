// Includes the header for author structure
// and the related function prototypes
#include "authors.h"
// Includes the standard input/output library
#include <stdio.h>

int main() {
    // Define and initialize an array of authors
    // as a set of struct Author
    // each one initialized with 
    // a struct initializer
    struct Author authors[3] = {
        { 1, "Dante",  "Alighieri",  22, 1, 2004},
        { 2, "Ken",  "Follet",  15, 8, 1964},
        { 3, "Italo",  "Calvino",  22, 1, 2004},
    }; 

    // Print all the authors
    for (int i=0; i <3; i++) {
        // Call the function print_author
        // passing the struct Author
        // related to the current iteration
        // in a similar way as we did with
        // an array of int or float
        print_author(authors[i]);

        // Here we test the function get_id
        // that returns the id of the author
        printf("\nAuthor ID: %u\n", get_id(authors[i]));

        // We just print the second char of the name
        // to show how to use the array notation
        // to access to a certain author in the array
        // or to a certain char in the name of the author
        printf("\nThe second char in %s is %c\n", authors[i].name, authors[i].name[1]);
    }

    return 0;
}