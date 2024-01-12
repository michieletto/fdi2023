// update_invert.c
// Include le librerie necessarie
#include "update_invert.h"      // Libreria con le funzioni

/**
 * 1. Aggiorna il contenuto nel nodo in input
 * @param [inout] node puntatore al nodo da aggiornare
 * @note aggiornare a seconda che il valore del nodo sia:
 *    positivo ---> valore = valore * 2
 *    negativo ---> valore = valore / -2
 *    nullo    ---> valore = 1
**/
void update_node(struct Node* node) {
    // Se il valore del nodo è positivo
    if (node->value > 0) {
        // valore = valore * 2
        node->value *= 2;
    // altrimenti se il valore del nodo è negativo
    } else if (node->value < 0) {
        // valore = valore / -2
        node->value /= -2;
    // altrimenti se il valore del nodo è nullo
    } else {
        // valore = 1
        node->value = 1;
    }
}

/**
 * Alloca un nuovo nodo da inserire nella lista usando la memoria dinamica
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
 * 2. Duplica (usando la memoria dinamica) il nodo in input 
 * @param [in] node puntatore al nodo da duplicare
 * @return puntatore al nodo duplicato
 * @note 
 * il nodo duplicato deve avere lo stesso valore del nodo in input
 * mentre il puntatore al nodo successivo deve essere NULL
**/
struct Node* duplicate_node(struct Node *node) {
    // Alloco un nuovo nodo da inserire nella lista
    struct Node* temp = new_node(node->value);
    // Restituisco il puntatore al nodo creato
    return temp;
}

/**
 * 3. Aggiunge in coda alla lista di input nuovi nodi in modo da
 * raddoppiarne la lunghezza originale; i nuovi nodi vanno in ordine
 * inverso in coda alla lista in input e modificati in base al valore
 * contenuto al loro interno tramite la funzione update_node()
 * @param [inout] head puntatore alla testa della lista concatenata
 * @note La funzione dovrà gestire il caso di lista vuota.
**/
void update_invert(struct Node *head) {
    // Se la lista è vuota
    if (head == NULL) {
        // Termino la funzione
        return;
    }
    
    // Creo 2 puntatori di appoggio
    // Il primo alla testa della nuova lista che creo
    struct Node *mirror_head = NULL;
    // Il secondo per tenere traccia dell'ultimo elemento della lista originale
    struct Node *last = NULL;

    // Finché il puntatore al nodo è diverso da NULL
    while (head != NULL)
    {
        // Duplico il nodo corrente della lista in input
        struct Node* temp = duplicate_node(head);
        // Aggiorno il valore del nodo appena creato
        update_node(temp);
        // Collego il nodo attualmente in testa al nodo appena creato
        temp->next = mirror_head;
        // Aggiorno il puntatore alla testa della nuova lista
        mirror_head = temp;
        // Aggiorno last al nodo corrente
        last = head;
        // Mi sposto al nodo successivo con head
        head = head->next;
        // così quando head == NULL
        // last punta all'ultimo nodo della lista
    }

    // Aggancio la nuova lista in coda a quella in input
    last->next = mirror_head;
}