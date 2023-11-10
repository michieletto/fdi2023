// Define the file guard
// to avoid multiple inclusion
// of the same header file
// in the same compilation unit
// if the compiler cannot find the definition
// of the file guard (AUTHOR_H_), it will define it
// and include the content of the header file
// otherwise it will skip the inclusion
#ifndef AUTHOR_H_
#define AUTHOR_H_

// Define the maximum length of the name
#define MAX_NAME_LEN 50

// Define the struct Author
// with the fields id, name, surname, day, month, year
struct Author {
    unsigned int id;
    char name[MAX_NAME_LEN];
    char surname[MAX_NAME_LEN];
    int day;
    int month;
    int year;
};

// Use typedef to define a new type Author
// that is an alias for struct Author
typedef struct Author Author;

// Print the author information
void print_author(struct Author author);

// Return the id of the author
unsigned int get_id(Author author);

// End of the file guard
#endif /* AUTHOR_H_ */