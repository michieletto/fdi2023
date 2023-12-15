#include "list.h"
#include <stdio.h>

int main() {
    struct Node *n1;
    struct Node *n2;
    struct Node *n3;

    n1 = new_node(10);
    n2 = new_node(20);
    n3 = new_node(30);
    
    n1->next = n2;
    n2->next = n3;
    n3->next = NULL;

    print_list(n1);

    delelte_list(n1);

    return 0;
}