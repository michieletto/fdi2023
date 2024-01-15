#ifndef __CAESAR_H__
#define __CAESAR_H__

// Include le librerie necessarie
#include <stdio.h>          // Input/output
#include <stdlib.h>         // Standard library
#include <stdbool.h>        // Booleani
#include <string.h>         // Stringhe

// Struttura dati che rappresenta un nodo della lista di caratteri
typedef struct CharNode {
    char value;		        // dato
    struct CharNode *next;	// link
} CharNode;

// Crea una lista di caratteri cifrata con il cifrario di Cesare
// a partire dalla lista di caratteri in input e dalla chiave
struct CharNode* caesar_cipher(struct CharNode *head, int key);

#endif // __CAESAR_H__