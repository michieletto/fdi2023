// Includes the standard input/output library
#include <stdio.h>
// Includes the string library (for strcpy function)
#include <string.h>
// Includes the boolean library (for bool type)
#include <stdbool.h>

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

// Search an author in the array of authors
// only by using the author birth day
bool search_author_by_day(Author* author_ptr, Author authors[], int *num_authors_ptr) {
    // Iterate over the array of authors
    for (int i = 0; i < *num_authors_ptr; i++){
        // check if the day in author_ptr is equal to the day in authors[i]
        // NOTE: 
        // 1. the arrow notation is used to access to the struct fields from a pointer
        // 2. the dot notation is used to access to the struct fields from a variable
        //    in particular, the specific author at index i in the array authors
        if(author_ptr->day == authors[i].day){
            // we found the author, or maybe not
            return true;
        }
    }
    // after iterating over the array of authors
    // we did not find the author
    return false;
}

// Search an author in the array of authors
// only by using the author surname
bool search_author_by_surname(Author* author_ptr, Author authors[], int *num_authors_ptr) {
    // Iterate over the array of authors
    for (int i = 0; i < *num_authors_ptr; i++){
        // check if the name in author_ptr is equal to the surname in authors[i]
        // NOTE: we use the strcmp function to compare two strings
        // strcmp return 0 if str1 == str2
        // REMEMBER:
        // author_ptr->surname is equivalent to (*author_ptr).surname
        if(strcmp(author_ptr->surname, authors[i].surname) == 0){
            // we found the author
            return true;
        }
    }
    // after iterating over the array of authors
    // we did not find the author
    return false;
}

// Search an author in the array of authors
// by using the author surname and name
bool search_author(Author* author_ptr, Author authors[], int *num_authors_ptr) {
    // Define a temporary variable to store the full name from author_ptr
    // the dimension of the array is 2 times the maximum length of a text field
    // because we need to store both the surname and the name
    char surname_name[2*MAX_TEXT_CHAR];
    // Copy the surname in the temporary variable
    // Suppose the author is "Fante Alighieri"
    // the array surname_name will contain
    // |A|l|i|g|h|i|e|r|i|\0|
    strcpy(surname_name, author_ptr->surname);
    // Concatenate a space to the temporary variable
    // Now the array surname_name will contain
    // |A|l|i|g|h|i|e|r|i| |\0|
    strcat(surname_name, " ");
    // Concatenate the name to the temporary variable
    // The final array surname_name will contain
    // |A|l|i|g|h|i|e|r|i| |F|a|n|t|e|\0|
    strcat(surname_name, author_ptr->name);

    // Iterate over the array of authors
    for (int i = 0; i < *num_authors_ptr; i++){
        // Define a temporary variable to store the full name from authors[i]
        // we will use the same procedure as before to concatenate the surname and the name
        char array_surname_name[2*MAX_TEXT_CHAR];
        strcpy(array_surname_name, authors[i].surname);
        strcat(array_surname_name, " ");
        strcat(array_surname_name, authors[i].name);
        // to compare the two full names with the strcmp function
        if(strcmp(surname_name, array_surname_name) == 0) {
            return true;
        }
    }
    return false;
}

// Search an author in the ordered array of authors
// by using the author surname and name and
// using the binary search algorithm
// The binary search algorithm is based on the divide and conquer strategy
// and it works only on ordered arrays, in this case ordered by surname and name
// The algorithm is faster than the linear search algorithm
// because it does not need to iterate over all the elements of the array
// but it can skip some elements based on a series of comparisons agaist the search key
// The procedure is similar to search a word in a dictionary
// where you start from the middle of the dictionary
// and then you check if the word you are looking for is before or after the middle word
// and then you repeat the procedure on the half of the dictionary
// where the word you are looking for is located and remove the other half
bool binary_search_author(Author* author_ptr, Author authors[], int *num_authors_ptr) {
    // Define the start, end and middle index
    int start = 0;                     // start index to the first element of the array
    int end = *num_authors_ptr - 1;    // end index to the last element of the array
    int middle = (start + end)/2;      // middle index to the middle element of the array

    // Define a temporary variable to store the full name from author_ptr
    char surname_name[2*MAX_TEXT_CHAR];
    strcpy(surname_name, author_ptr->surname);
    strcat(surname_name, " ");
    strcat(surname_name, author_ptr->name);

    // While the start index is less or equal to the end index
    while (start <= end) {
        // Define a temporary variable to store the full name from authors[middle]
        char array_surname_name[2*MAX_TEXT_CHAR];
        strcpy(array_surname_name, authors[middle].surname);
        strcat(array_surname_name, " ");
        strcat(array_surname_name, authors[middle].name);
        // We now compare the two full names with the strcmp function:
        // strcmp return 0 if str1 == str2
        // strcmp return <0 if str1 < str2
        // strcmp return >0 if str1 > str2
        if (strcmp(surname_name, array_surname_name) == 0) {
            // we found the author
            return true;
        }
        if (strcmp(surname_name, array_surname_name) > 0) {
            // the author is after the middle element
            // so we can skip the first half of the array
            // and we can move the start index to the middle + 1
            start = middle + 1;
        } else {
            // the author is before the middle element
            // so we can skip the second half of the array
            // and we can move the end index to the middle - 1
            end = middle - 1;
        }
        // then we need to update the middle index
        middle = (start + end)/2;
    }
    // once the start index is greater than the end index
    // we did not find the author in the array
    return false;
}

// Search an author in the ordered array of authors
// by using the author surname and name, applying the 
// binary search algorithm and pointers to the array of authors
// instead of using indexes to access to the array elements
bool binary_search_author_ptr(Author* author_ptr, Author *authors, int *num_authors_ptr) {
    // Define the start, end and middle pointers
    // The start pointer to the first element of the array
    // can be defined in two ways:
    // by the address of the first element of the array
    // Author *start = &authors[0];
    // or by the address of the array itself
    Author *start = authors;                
    // The end pointer to the last element of the array
    // can be defined in two ways:
    // by the address of the last element of the array            
    // Author *end = &authors[*num_authors_ptr-1];
    // or by the address of the array itself 
    // plus the number of elements in the array - 1
    Author *end = authors + (*num_authors_ptr-1);
    // The middle pointer to the middle element of the array
    // can be defined by the address of the first element of the array
    // plus the difference between the address of the last element of the array
    // and the address of the first element of the array divided by 2
    Author *middle = start + (end - start)/2;

    // Define a temporary variable to store the full name from author_ptr
    char surname_name[2*MAX_TEXT_CHAR];
    strcpy(surname_name, author_ptr->surname);
    strcat(surname_name, " ");
    strcat(surname_name, author_ptr->name);

    // As before, but referring to the pointers:
    // While the start pointer is less or equal to the end pointer
    while(start <= end) {
        // Define a temporary variable to store the full name from middle pointer
        char array_surname_name[2*MAX_TEXT_CHAR];
        strcpy(array_surname_name, middle->surname);
        strcat(array_surname_name, " ");
        strcat(array_surname_name, middle->name);

        // We now compare the two full names with the strcmp function
        if (strcmp(surname_name, array_surname_name) == 0) {
            // we found the author
            return true;
        }
        if (strcmp(surname_name, array_surname_name) > 0) {
            // the author is after the middle element
            // so we can skip the first half of the array
            // and we can move the start pointer to the middle + 1
            start = middle + 1;
        } else {
            // the author is before the middle element
            // so we can skip the second half of the array
            // and we can move the end pointer to the middle - 1
            end = middle - 1;
        }
        // then we need to update the middle pointer
        middle = start + (end - start)/2;
    }
    // once the start pointer is greater than the end pointer
    // we did not find the author in the array
    return false;
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
    //print_author(&temp);
    
    if(binary_search_author_ptr(&temp, authors, num_authors_ptr)) {
        printf("The author is already present\n");
        return;
    }

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

// Load the authors from the file,
// store them in the array of authors
// update the number of authors
// and return true if the file is loaded correctly
bool load_authors(char filename[], Author authors[], int *num_authors_ptr) {
    // The operation on files can divided into four steps:
    // 1. Opening the file
    // 2. Checking if the file is opened correctly
    // 3. Operating on the content of the file
    // 4. Closing the file
    // OPERATION ON FILES #1: OPENING
    // the FILE pointer is defined in the stdio.h library and
    // it is used to access to the file using the function fopen
    // To open the file you need to specify the filename
    // and the opening modalities: read (r), write (w), append (a)
    // and if the file is binary (b) or not
    FILE *file = fopen(filename, "r"); // Read
    // Other opening modalities are:
    // FILE *file = fopen(filename, "w"); // Write
    // FILE *file = fopen(filename, "a"); // Append
    // FILE *file = fopen(filename, "rb"); // Read binary
    // FILE *file = fopen(filename, "wb"); // Write binary
    // FILE *file = fopen(filename, "ab"); // Append binary

    // OPERATION ON FILES #2: CHECKING
    // If the file cannot be opened for any reason
    // the fopen function will return NULL so we can check it
    // and return false to indicate an error
    if (file == NULL) {
        return false;
    }

    // OPERATION ON FILES #3: OPERATING
    // Once the file is opened we can read the content
    // using the fscanf function that is defined in the stdio.h library
    // fscanf works like scanf but it reads from a file instead of the standard input
    // so if we want to read from the file we need to:
    // 1. pass the file pointer as first argument
    // 2. use the same format string as scanf
    // 3. pass the address of the variables where to store the values read from the file
    fscanf(file, "%d", num_authors_ptr);

    // Now that we know the number of authors
    // we can iterate over the array of authors
    // and read the information from the file
    // The rows in the file are organized as follows:
    // id name surname day month year
    // with a space between each field, for example:
    // 1 Dante Alighieri 1 6 1265
    // and each row is separated by a newline character (\n)
    for(int i=0; i<*num_authors_ptr; i++) {
        fscanf(file, "%d", &authors[i].id);
        fscanf(file, "%s", authors[i].name);
        fscanf(file, "%s", authors[i].surname);
        fscanf(file, "%d", &authors[i].day);
        fscanf(file, "%d", &authors[i].month);
        fscanf(file, "%d", &authors[i].year);
    }

    // The file ends with the EOF character
    // it a constant defined in the stdio.h library
    // and it is used to indicate the end of the file
    // EOF; // End of file

    // OPERATION ON FILES #4: CLOSING
    // Close the file to avoid memory leaks
    // and problems in the next file operations
    fclose(file);

    // Return true to indicate success
    return true;
}

// Main function
int main() {
    // Define a string variable to store the filename
    // NOTE: the filename is relative to the executable file
    // in this case the executable file is in the folder 20231204
    // and the file authors.txt is in the folder data inside 20231204
    // so we need to specify the path to the file as data/authors.txt
    char filename[] = "data/authors.txt";

    // Define an array of authors
    Author authors[NUM_MAX_AUTHORS];
    // Define a variable to store the number of authors
    int num_authors = 0;

    // Load the authors from the file
    if (!load_authors(filename, authors, &num_authors)) {
        // If the file cannot be loaded print an error message
        printf("Error in loading the file\n");
        // Return 1 to indicate an error
        return 1;
    }

    // Print all the authors
    for (int i=0; i < num_authors; i++) {
        print_author(&authors[i]);
    }

    // Ask the user to insert a new author
    // read_author(authors, &num_authors);

    // Print all the authors again to check if
    // the new author has been added correctly
    /*
    for (int i=0; i < num_authors; i++) {
        print_author(&authors[i]);
    }*/

    // Return 0 to indicate success
    return 0;
}