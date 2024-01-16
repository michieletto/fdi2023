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
    // Caso base: i puntatori al primo o all'ultimo elemento
    // dell'array sono NULL o start "supera" end
    if ((start == NULL) || (end == NULL) || (start >= end)) {
        // Ritorno il puntatore a start
        // Questo caso serve a trovare il minimo quando tra 
        // start e end c'è un unico elemento, inoltre 
        // gestisce il casi in cui l'array sia inconsistente
        return start;
    }
    
    // Ricorsione: chiamo la funzione ricorsivamente 
    // riducendo l'array in input di un elemento 
    // ( avanzo di uno il puntatore a start) e salvando
    // in min_ptr il puntatore al minimo calcolato
    // 0. 10 1 18 22 6 3   min_ptr -> 1
    // 1. 1 18 22 6 3      min_ptr -> 1
    // 2. 18 22 6 3        min_ptr -> 3
    // 3. 22 6 3           min_ptr -> 3
    // 4. 6 3              min_ptr -> 3
    // 5. 3                min_ptr -> 3
    int* min_ptr = recursive_min_index(start+1,end);

    // confronto il valore del minino calcolato dalla ricorsione
    // con il valore di start, che avevo escluso dal processo
    // per restituire il minimo tra i due
    // 0. 10 vs 1      min_ptr -> 1
    // 1. 1  vs 3      min_ptr -> 1
    // 2. 18 vs 3      min_ptr -> 3
    // 3. 22 vs 3      min_ptr -> 3
    // 4. 6  vs 3      min_ptr -> 3
    return (*min_ptr < *start ? min_ptr : start);
}

/**
 * Ordina ricorsivamente un array usando l'algoritmo selection sort
 * @param [in] start puntatore al primo elemento dell'array da ordinare
 * @param [in] end puntatore all'ultimo elemento dell'array da ordinare
 * Se uno dei puntatori in input è NULL, ritornare senza effettuare operazioni
**/
void recursive_selection_sort(int *start, int *end)
{
    // Caso base: i puntatori al primo o all'ultimo elemento
    // dell'array sono NULL o start "supera" end
    if ((start == NULL) || (end == NULL) || (start >= end))
        // Termino la funzione: l'array è composto al massimo
        // di un elemento ed è per forza ordinato
        return;
    
    // Ricorsione: calcolo il minimo
    int* min = recursive_min_index(start, end);
    // Scambio il minimo con l'elemento corrente
    swap(start, min);
    // Chiamo la funzione ricorsivamente 
    // riducendo l'array in input di un elemento
    // ( avanzo di uno il puntatore a start) 
    recursive_selection_sort(start+1, end);
}