// caesar.c
// Include le librerie necessarie
#include "caesar.h"         // Libreria con le funzioni

/**
 * Crea un nodo a partire dal valore in input
 * @param [in] value valore da inserire come dato nel nodo
 * @return puntatore al nodo creato
**/
struct CharNode* new_node(char value) {
    // Allocazione dinamica del nodo
    struct CharNode* node = (struct CharNode*)malloc(sizeof(struct CharNode));
    // Se l'allocazione è andata a buon fine
    if (node != NULL) {      // Imposto
        node->value = value; // valore
        node->next = NULL;   // e link
    }
    return node;
}

/**
 * Crea una lista di caratteri (solo minuscoli) cifrata con il cifrario di Cesare
 * a partire dalla lista di caratteri in input e dalla chiave
 * @param [in] head puntatore alla testa della lista di caratteri
 * @param [in] key chiave di cifratura
 * @return puntatore alla testa della lista di caratteri cifrata
 * @note il cifrario di Cesare è una cifratura monoalfabetica
 *       che consiste nello spostare ogni lettera del messaggio
 *       di un numero di posizioni pari alla chiave
 *      (es. chiave = 3, a -> d, b -> e, ..., z -> c)
**/
struct CharNode* caesar_cipher(struct CharNode *head, int key) {
    // Definisco una variabile di appoggio per
    // tenere traccia del valore da inserire nella lista    
    char cipher_value =  0;
    // Definisco un puntatore alla testa della lista
    struct CharNode* cipher_head = NULL;
    // Definisco un puntatore alla coda della lista
    struct CharNode* cipher_tail = NULL;

    // Scorro la lista di caratteri
    while (head != NULL) {
        // Calcolo il valore da inserire nella lista
        cipher_value = (head->value + key - 'a') % 26 + 'a';
        /* Cosa succede in questa operazione?
        |--------------------------------------abcdef------------z| nella codifica dei caratteri da 'a' a 'z' ogni
        |0................25..................80..................| carattere è rappresentato tramite un valore decimale
        |abcdef------------z                                      | se a questo valore si sottrae 'a', si ottengono valori tra 0 e 25
        |---abcdef------------z                                   | aggiungendo key, tale codifica viene portata in avanti
        |xyzabcdef---------w                                      | con il modulo a 26 "riportiamo" i caratteri al range 0-25
        |--------------------------------------xyzabcdef---------w| aggiungendo di nuovo 'a' otteniamo un alfabeto nella codifica iniziale
                                                                    ma shiftato di key caratteri
        */
        // Creo un nuovo nodo con il valore calcolato
        struct CharNode* cipher_node = new_node(cipher_value);
        // Se il nodo è diverso da NULL
        if (cipher_node != NULL) {
            // Se la lista è vuota
            if (cipher_head == NULL) {
                // Imposto la testa e la coda della lista
                cipher_head = cipher_node;
            // Altrimenti
            } else {
                // Inserisco il nodo in coda alla lista
                cipher_tail->next = cipher_node;
            }
            cipher_tail = cipher_node;
        }
        // Passo al prossimo elemento
        head = head->next;
    }
    // Ritorno il puntatore alla testa della lista
    return cipher_head;
}