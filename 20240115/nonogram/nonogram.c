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
    // Considero il caso di lista vuota
    if (start ==  NULL || end == NULL)
        return NULL;
    // Definisco una variabile di appoggio per
    // tenere traccia del valore da inserire nella lista    
    int temp_value =  0;
    // Scarto gli 0 iniziali
    while ((start <= end) && (*start == 0)) {
        // Passo al prossimo elemento
        start++;
    }
    // Calcolo il valore da inserire nella lista   
    while((start <= end) && (*start == 1)) {
        // Incremento il valore temporaneo
        temp_value++;
        // Passo al prossimo elemento
        start++;
    }
    // Se il vettore è vuoto
    if (temp_value == 0) { // (start > end)) {
        // Termina la funzione senza inserire 
        // nessun nodo nella lista
        return NULL;
    }
    // Altrimenti
    // Creo un nuovo nodo con il valore calcolato
    struct Node* head = new_node(temp_value);
    // Se il nodo è diverso da NULL
    if (head != NULL) {
        // Inserisco ricorsivamente i successivi elementi del vettore
        // dopo il nodo creato
        head->next = fill_list(start, end);
    }
    // Ritorno il puntatore alla testa della lista
    return head;
}