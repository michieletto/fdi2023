// Includes the header for author structure
// and the related function prototypes
#include "authors.h"
// Includes the standard input/output library
#include <stdio.h>

// Print the author information
void print_author(struct Author author) {
    // To access to the struct fields
    // you need to use the dot notation
    printf("\n==========================\n");
    printf("ID: %u\n", author.id);
    printf("NAME: %s\n", author.name);
    printf("SURNAME: %s\n", author.surname);
    printf("DATE OF BIRTH: %d/%d/%d\n", author.day, author.month, author.year);
}

// Return the id of the author
unsigned int get_id(Author author) {
    // The value of the id field
    // is directly returned
    // as output of the function
    return author.id;
}