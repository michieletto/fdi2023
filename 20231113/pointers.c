// Include the standard input/output library
#include <stdio.h>

// Main function
int main() {
    // Declare two integers
    int a = 5;
    int b = 3;

    // Declare two pointers to integers
    // The pointers are initialized with the addresses of the integers
    // the operator & returns the address of the variable
    int* a_ptr = &a;
    int* b_ptr = &b;

    // Declare a pointer to an integer
    // and initialize it with the address 
    // contained in the pointer b_ptr
    // Now the pointer other_ptr points to the same integer as b_ptr
    int* other_ptr = b_ptr;

    // Print value and address of the pointers
    // by using the pointer as starting point
    printf("The address of a is %p and its value is %d\n", 
        a_ptr,      // Indirizzo contenuto nella variabile a_ptr
        *a_ptr);    // Valore contenuto all'indirizzo nella variabile a_ptr
    // Print value and address of the pointers
    // by using the value as starting point
    printf("The address of a is %p and its value is %d\n", 
        &a,         // Indirizzo della variabile a
        a);         // Valore della variabile a
    // Print value and address of the pointers
    // by using the value as starting point
    printf("The address of b is %p and its value is %d\n",
        &b,         // Indirizzo della variabile b
        b);         // Valore della variabile b
    
    // The value other_ptr is now assigned to b_ptr
    b_ptr = other_ptr;
    // and its value is updated
    *b_ptr = *a_ptr + *other_ptr;
    // Print the NEW value and address of b
    printf("The NEW address of b is %p and its NEW value is %d\n",
        &b,         // Indirizzo della variabile b
        b);         // Valore della variabile b
    // Print the NEW value and address of b_ptr        
    printf("The value of b_ptr is %p and the value pointed by b_ptr is %d\n",
        b_ptr,      // Indirizzo contenuto nella variabile b_ptr
        *b_ptr);    // Valore contenuto all'indirizzo nella variabile b_ptr
    // Print the NEW value and address of other_ptr
    printf("The value of other_ptr is %p and the value pointed by other_ptr is %d\n",
        other_ptr,      // Indirizzo contenuto nella variabile other_ptr
        *other_ptr);    // Valore contenuto all'indirizzo nella variabile other_ptr

    // Return 0 to indicate success
    return 0;
}