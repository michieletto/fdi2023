// nonogram_main.c
// Include le librerie necessarie
#include "nonogram.h"

/**
 * Stampa a video gli elementi di un array
 * @param [in] v array di interi
 * @param [in] size numero di elementi dell'array
 **/
static void print_array(int *v, int size) {
	printf("[");
	for (int i=0; i < size; i++) {
		printf(" %d", v[i]);
	}
	printf(" ]\n");
}

/**
 * Visita di ogni nodo all'interno della lista
 * per stampare il contenuto a schermo
 * @param [in] head puntatore alla testa della lista
*/
static void print_list(struct Node *head) {
    // Finché il puntatore al nodo è diverso da NULL
    while (head != NULL) {
        // Stampo a schermo il contenuto del nodo
        printf("%d -> ", head->value);
        // e mi sposto al nodo successivo
        head = head->next;
    }
    // Stampo a schermo che sono arrivato alla fine della lista
    printf("NULL\n");
}

// Main function
int main() {
    // Dichiaro le variabili necessarie
    int num_elems;      // Numero di elementi dell'array
    int temp;           // Variabile di appoggio
    int *v = NULL;      // Puntatore all'array
    int* end = NULL;    // Puntatore all'ultimo elemento dell'array
    // Chiedo all'utente di inserire il numero di elementi dell'array
    printf("Insert the number of elements in the array:\n");
    scanf("%d", &num_elems);
    // Se il numero di elementi è maggiore di 0
    if (num_elems>0) {
        // Alloco l'array dinamicamente
        v = malloc(num_elems*sizeof(int));
        // e ne calcolo il puntatore all'ultimo elemento
        end = v+num_elems-1;
    }
    // Chiedo all'utente di inserire gli elementi dell'array
    printf("Insert the array values sepearated by spaces, to finish press Enter\n");
    for(int i=0; i<num_elems; i++) {
        scanf("%d", &v[i]);
    }
    // Stampo a video l'array iniziale
    printf("Initial array: ");
    print_array(v, num_elems);
    // Richiamo la funzione di ordinamento
    struct Node *head = fill_list(v, end);
    // Stampo a video l'array ordinato
    printf("Nonogram list: ");
    print_list(head);

    // Libero la memoria allocata per l'array
    if (v != NULL)
        free(v);

    // Termino il programma
    return 0;
}