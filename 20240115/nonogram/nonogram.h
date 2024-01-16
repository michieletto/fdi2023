#ifndef __NONOGRAM_H__
#define __NONOGRAM_H__

// Include le librerie necessarie
#include <stdio.h>          // Input/output
#include <stdlib.h>         // Standard library
#include <stdbool.h>        // Booleani

// Struttura dati che rappresenta un nodo della lista di interi
typedef struct Node {
    int value;		    // dato
    struct Node *next;	// link
} Node;

// 1. Crea un nodo a partire dal valore in input
struct Node* new_node(int value);

// 2. Scorre ricorsivamente il vettore nonogram per inserire nella lista
//    i valori presenti nel vettore sommando gli 1 consecutivi e seperati da 0
struct Node* fill_list(int *start, int* end);

/*
nonogramrow([]) => []
nonogramrow([0,0,0,0,0]) => []
nonogramrow([1,1,1,1,1]) => [5]
nonogramrow([0,1,1,1,1,1,0,1,1,1,1]) => [5,4]
nonogramrow([1,1,0,1,0,0,1,1,1,0,0]) => [2,1,3]
nonogramrow([0,0,0,0,1,1,0,0,1,0,1,1,1]) => [2,1,3]
nonogramrow([1,0,1,0,1,0,1,0,1,0,1,0,1,0,1]) => [1,1,1,1,1,1,1,1]
*/

#endif // __NONOGRAM_H__