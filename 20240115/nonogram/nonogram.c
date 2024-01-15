// nonogram.c
// Include le librerie necessarie
#include "nonogram.h"

/**
 * 1. Crea un nodo a partire dal valore in input
 * @param [in] value valore da inserire come dato nel nodo
 * @return puntatore al nodo creato
**/
struct Node* new_node(int value) {
    // Allocazione dinamica del nodo
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    // Se l'allocazione è andata a buon fine
    if (node != NULL) {      // Imposto
        node->value = value; // valore
        node->next = NULL;   // e link
    }
    return node;
}

/**
 * 2. Scorre ricorsivamente il vettore nonogram per inserire nella lista
 * i valori presenti nel vettore sommando gli 1 consecutivi e seperati da 0
 * @param [in] nonogram vettore di interi
 * @param [in] size numero di elementi del vettore
 * @return puntatore alla testa della lista
 * @note la funzione deve essere ricorsiva
**/
struct Node* fill_list(int *start, int* end) {
    
}