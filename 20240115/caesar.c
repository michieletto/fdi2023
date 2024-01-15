// caesar.c
// Include le librerie necessarie
#include "caesar.h"         // Libreria con le funzioni

/**
 * Crea un nodo a partire dal valore in input
 * @param [in] value valore da inserire come dato nel nodo
 * @return puntatore al nodo creato
**/
struct CharNode* new_node(char value) {

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
    
}