// pointer_array.c
// Include le librerie necessarie
#include "pointer_array.h"         // Libreria con le funzioni

/**
 * Stampa un array di interi da start a end
 * @param [in] start puntatore al primo elemento dell'array
 * @param [in] end puntatore all'ultimo elemento dell'array
 * @note stampa gli elementi dell'array nel formato:
 *      [elemento1 elemento2 ... elementoN]
**/
void print_array(int *start, int *end) {
    // Stampa le parentesi quadre aperte
    printf("[");
    // Stampa gli elementi dell'array
    for(int *i = start; i <= end; i++) {
        printf(" %d", *i);
    }
    // Stampa le parentesi quadre chiuse
    printf(" ]\n");
}

/**
 * Raddoppia il valore degli elementi di un array da start a end
 * @param [in] start puntatore al primo elemento dell'array
 * @param [in] end puntatore all'ultimo elemento dell'array
 * @note modifica gli elementi dell'array raddoppiandoli
 *      (es. [1 2 3] -> [2 4 6])
**/
void twice_array(int *start, int *end) {
    // Raddoppia il valore di ogni elemento dell'array
    for(int *i = start; i <= end; i++) {
        *i *= 2;
    }
}

/**
 * Restituisce la somma degli elementi di un array da start a end
 * @param [in] start puntatore al primo elemento dell'array
 * @param [in] end puntatore all'ultimo elemento dell'array
 * @return somma degli elementi dell'array
 * @note se l'array è vuoto, restituisce 0
**/
int sum_array(int *start, int *end) {
    // Variabile di appoggio per la somma
    int sum = 0;
    // Somma gli elementi dell'array
    for(int *i = start; i <= end; i++) {
        sum += *i;
    }
    // Restituisce la somma
    return sum;
}

/**
 * Inverte l'ordine degli elementi di un array da start a end
 * @param [in] start puntatore al primo elemento dell'array
 * @param [in] end puntatore all'ultimo elemento dell'array
 * @note inverte l'ordine degli elementi dell'array
 *     (es. [1 2 3] -> [3 2 1])
**/
void reverse_array(int *start, int *end) {
    // Variabile di appoggio per lo scambio
    int tmp = 0;
    // Inverte l'ordine degli elementi dell'array
    // incrementando il puntatore di inizio e decrementando
    // il puntatore di fine finchè non si incontrano
    for(int *i = start, *j = end; i < j; i++, j--) {
        tmp = *i;
        *i = *j;
        *j = tmp;
    }
}

/**
 * Trova un elemento in un array da start a end
 * @param [in] start puntatore al primo elemento dell'array
 * @param [in] end puntatore all'ultimo elemento dell'array
 * @param [in] value valore da cercare
 * @return puntatore all'elemento trovato, NULL se non trovato
 * @note se l'elemento è presente più volte, restituisce una delle occorrenze
**/
int *find_array(int *start, int *end, int value) {
    // Cerca l'elemento nell'array
    for(int *i = start; i <= end; i++) {
        if (*i == value) {
            return i;
        }
    }
    // Se non è stato trovato, restituisce NULL
    return NULL;
}