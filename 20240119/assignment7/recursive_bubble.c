// recursive_bubble.c
// Include le librerie necessarie
#include "recursive_bubble.h"       // Libreria con le funzioni

/**
 * Sbambia il valore di due interi in input
 * @param [inout] a puntatore al primo intero in input
 * @param [inout] b puntatore al secondo intero in input
*/
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * Ordina ricorsivamente un array usando l'algoritmo bubble sort
 * @param [in] start puntatore al primo elemento dell'array da ordinare
 * @param [in] end puntatore all'ultimo elemento dell'array da ordinare
 * Se uno dei puntatori in input è NULL, ritornare senza effettuare operazioni
**/
void recursive_bubble_sort(int *start, int *end) {
    if ((start == NULL) || (end == NULL) || (start >= end)) {
        return;
    }

    bool swapped = false;

    for (int *i = start; i < end; i++) {
        if(*i > *(i+1)) {
            swap(i, i+1);
            swapped = true;
        }
    }
    
    if (!swapped) {
        return;
    }

    recursive_bubble_sort(start, end-1);
}
 // recursive_bubble.c
// Include le librerie necessarie
#include "recursive_bubble.h"       // Libreria con le funzioni

/**
 * Sbambia il valore di due interi in input
 * @param [inout] a puntatore al primo intero in input
 * @param [inout] b puntatore al secondo intero in input
*/
void swap(int* a, int* b) {
    // Creo una variabile di appoggio
    // e salvo il valore di a
    int temp = *a;
    // Copio in a il valore di b
    *a = *b;
    // Copio in b il vecchio valore di a
    // prendendolo dalla variabile di appoggio
    *b = temp;
}

/**
 * Ordina ricorsivamente un array usando l'algoritmo bubble sort
 * @param [in] start puntatore al primo elemento dell'array da ordinare
 * @param [in] end puntatore all'ultimo elemento dell'array da ordinare
 * Se uno dei puntatori in input è NULL, ritornare senza effettuare operazioni
**/
void recursive_bubble_sort(int *start, int *end)
{
    // Caso base: i puntatori al primo o all'ultimo elemento
    // dell'array sono NULL o start "supera" end
    if ((start == NULL) || (end == NULL) || (start >= end))
        // Termino la funzione: l'array è composto al massimo
        // di un elemento ed è per forza ordinato
        return;

    // Tengo traccia degli scambi effettuati
    bool swapped = false;

    // Itero lungo l'array da ordinare (start -> end)
    // in modo da spostare il valore più grande alla fine
    for (int *i = start; i < end; i++) {
        // Se il valore corrente è maggiore del successivo
        if (*i > *(i+1)) {
            // Scambio i valori
            swap(i, i+1);
            // Segnalo che ho effettuato uno scambio
            swapped = true;              
        }
    }

    // Se non ho effettuato scambi
    if (!swapped){
        // Termino la funzione: l'array è ordinato
        return;
    }

    // Ricorsione:
    // Chiamo la funzione ricorsivamente 
    // riducendo l'array in input di un elemento
    // ( avanzo di uno il puntatore a start) 
    recursive_bubble_sort(start, end-1);
}