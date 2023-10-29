// Define an enum for the categories
// available for the publishing house
enum categories {
    HORROR = 0,
    DRAMA,
    STORIC,
};

// Define an alias for the enum
// it can be used as a type
// to make it easier to use the enum
// or to better specify its meaning
typedef enum categories writing_cats;

// Define a struct for the authors
// it contains several fields
// each field has a specific type
// depending on the information it contains
// the struct stores the necessary information
// representing an author for the publishing house
struct Authors {
    int id;
    char name[50];
    int day;
    int month;
    int year;
    writing_cats cat;
};

// typedef can be used to define an alias for 
// structs too in the same way as for the enum
typedef struct Authors Authors;
