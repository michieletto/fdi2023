// caesar.c
// Include le librerie necessarie
#include "caesar.h"         // Libreria con le funzioni

/**
 * Crea un nodo a partire dal valore in input
 * @param [in] value valore da inserire come dato nel nodo
 * @return puntatore al nodo creato
**/
struct CharNode* new_node(char value) {
    struct CharNode* node = (struct CharNode*)malloc(sizeof(struct CharNode));
    if (node != NULL) {
        node->value = value;
        node->next = NULL;
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
    char cipher_value = 0;
    struct CharNode* cipher_head = NULL;
    struct CharNode* cipher_tail = NULL;

    while (head != NULL) {
        cipher_value = (head->value + key - 'a') % 26 + 'a';
        /* Cosa succede in questa operazione?
        |--------------------------------------abcdef------------z|
        |0................25..................80..................|
        |abcdef------------z
        |---abcdef------------z
        |xyzabcdef---------w
        |--------------------------------------xyzabcdef---------w|
        */
        struct CharNode *cipher_node = new_node(cipher_value);
        if (cipher_node != NULL) {
            if (cipher_head == NULL) {
                cipher_head = cipher_node;
            } else  {
                cipher_tail->next = cipher_node;
            }
            cipher_tail = cipher_node;
        }  else {
            return NULL;
        }
        head = head->next;
    }
    return cipher_head;
}