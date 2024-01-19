// oo_loop_main.c
#include "oo_loop.h"     // Libreria con le funzioni

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

// Main function
int main() {
    // Variabili d'appoggio
    // Dimensione dell'array
    int size = 0;
    // Capacità dell'array
    int capacity = 0;
    // Array di interi positivi
    int *array = NULL;

    // Legge un array di interi da tastiera
    array = read_array(&size, &capacity);

    // Se l'array è vuoto
    if (array == NULL) {
        // Stampa un messaggio di errore
        printf("Error: empty array\n");
        // e termina il programma
        return 0;
    }

    // Stampa l'array
    print_array(array, array + size - 1);

    // Libera la memoria occupata dall'array
    free(array);
    
    // Termina il programma
    return 0;
}