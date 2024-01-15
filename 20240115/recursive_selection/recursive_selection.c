#include "recursive_selection.h"

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
 * Trova ricorsivamente il minimo all'interno di un array da ordinare
 * @param [in] start puntatore al primo elemento dell'array da ordinare
 * @param [in] end puntatore all'ultimo elemento dell'array da ordinare
 * @return puntatore al minimo elemento dell'array
 * Se uno dei puntatori in input è NULL, ritornare il puntatore start
**/
int *recursive_min_index(int *start, int *end) {
    if (start == NULL  || end == NULL || start >= end) {
        return start;
    }

    int* min_ptr = recursive_min_index(start+1,end);

    return (*min_ptr < *start ? min_ptr : start);
}

/**
 * Ordina ricorsivamente un array usando l'algoritmo selection sort
 * @param [in] start puntatore al primo elemento dell'array da ordinare
 * @param [in] end puntatore all'ultimo elemento dell'array da ordinare
 * Se uno dei puntatori in input è NULL, ritornare senza effettuare operazioni
**/
void recursive_selection_sort(int *start, int *end) {
    if (start == NULL  || end == NULL || start >= end) {
        return;
    }

    int* min_ptr = recursive_min_index(start, end);

    swap(start, min_ptr);

    recursive_selection_sort(start+1, end);
}
