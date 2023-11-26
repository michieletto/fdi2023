// Includes the standard input/output library
#include <stdio.h>
// Includes the string library (for strcpy function)
#include <string.h>

// Define the maximum length of text fields
#define MAX_TEXT_CHAR 30

// Define the maximum number of authors
#define NUM_MAX_AUTHORS 10

// Define the struct Author
// with the fields id, name, surname, day, month, year
typedef struct {
    unsigned int id;
    char name[MAX_TEXT_CHAR];
    char surname[MAX_TEXT_CHAR];
    int day;
    int month;
    int year;
} Author;

// Print the author information
void print_author(Author *author_ptr) {
    // To access to the struct fields
    // by using a pointer to the variable
    // you need to use the arrow notation (->)
    printf("\n==========================\n");
    // The arrow notation is equivalent to
    // accessing to the value at the address
    // pointed by the pointer and then
    // using the dot notation to access to the field
    // printf("ID: %u\n", (*author_ptr).id);
    printf("ID: %u\n", author_ptr->id);
    printf("NAME: %s\n", author_ptr->name);
    printf("SURNAME: %s\n", author_ptr->surname);
    printf("DATE OF BIRTH: %d/%d/%d\n", author_ptr->day, author_ptr->month, author_ptr->year);
}

// Read the author information
// to add a new author in the array
void read_author(Author authors[], int* num_authors_ptr) {
    // Get the author information from the user
    // and store it in a temporary variable
    Author temp;
    temp.id = *num_authors_ptr + 1;
    printf("Insert author's info\n");
    printf("Name: ");
    scanf("%s", temp.name);
    printf("Surname: ");
    scanf("%s", temp.surname);
    printf("Day: ");
    scanf("%d", &temp.day);
    printf("Month: ");
    scanf("%d", &temp.month);
    printf("Year: ");
    scanf("%d", &temp.year);
    print_author(&temp);

    // Move the new author to the array of authors
    authors[*num_authors_ptr].id = temp.id;
    // To copy a string from a variable to another
    // you need to use the strcpy function
    // that is defined in the string.h library
    // and copy the content of the source string (second argument)     
    // to the destination string (first argument)
    strcpy(authors[*num_authors_ptr].name, temp.name);
    strcpy(authors[*num_authors_ptr].surname, temp.surname);
    authors[*num_authors_ptr].day = temp.day;
    authors[*num_authors_ptr].month = temp.month;
    authors[*num_authors_ptr].year = temp.year;

    // After adding the new author
    // increase the number of authors
    // by using the pointer to the variable
    // doing this to the pointer will affect
    // the value of the variable in the main function
    // because the pointer is pointing to the same address
    // of the variable num_authors defined in the main function
    // Passing the int variable by value will not work
    // because the function will receive a copy of the variable
    // and any change to the variable will not be reflected
    // in the variable defined in the main function
    (*num_authors_ptr)++;
}

// Main function
int main() {
    // Define and initialize an array of authors
    // as a set of struct Author
    // each one initialized with 
    // a struct initializer
    Author authors[NUM_MAX_AUTHORS] = {
        { 1, "Dante",  "Alighieri",  22, 1, 2004},
        { 2, "Ken",  "Follet",  15, 8, 1964},
        { 3, "Italo",  "Calvino",  22, 1, 2004},
    };

    // Define a variable to store the actual number of authors
    int num_authors = 3;

    // Print all the authors
    for (int i=0; i < num_authors; i++) {
        print_author(&authors[i]);
    }

    // Ask the user to insert a new author
    read_author(authors, &num_authors);

    // Print all the authors again to check if
    // the new author has been added correctly
    for (int i=0; i < num_authors; i++) {
        print_author(&authors[i]);
    }

    // Return 0 to indicate success
    return 0;
}