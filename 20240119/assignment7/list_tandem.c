#include "list_tandem.h"

/**
 * Verifica se due nodi contengono lo stesso carattere
 * @param [in] node_1 puntatore al primo nodo su cui fare il confronto
 * @param [in] node_2 puntatore al secondo nodo su cui fare il confronto
 * @return true se i nodi contengono lo stesso carattere, false altrimenti
**/ 
bool compare_char(struct CharNode* node_1, struct CharNode* node_2){
    // Confronto il valore contenuto nei due nodi
    return node_1->value == node_2->value;
}

/**
 * Calcola la lunghezza della lista in input
 * @param [in] head puntatore alla testa della lista
 * @return numero di elementi che compone la lista
**/
int list_len(struct CharNode *head) {
    // Inizializzo la lunghezza a zero
    int len = 0;
    // Finché il puntatore al nodo è diverso da NULL
    while (head != NULL) {
        // Incremento il numero di nodi
        len++;
        // e mi sposto al nodo successivo
        head = head->next;
    }
    // Ritorno la lunghezza calcolata
    return len;
}

/**
 * Verifica se la lista in input costituisce un tandem
 * @param [in] head puntatore alla testa della lista
 * @return true se la lista rappresenta un tandem, false altrimenti
**/ 
bool is_tandem(struct CharNode *head){
    // Calcolo la lunghezza della lista
    int len = list_len(head);
    
    // Per lunghezze inferiori a 2 la lista 
    // rappresenta un tandem per definizione
    if (len < 2)
        return true;
    
    // Creo un secondo puntatore
    struct CharNode *second_half = head;
    // e avanzo nella lista fino a puntare al primo nodo della seconda metà
    for(int i=0; i<(len+1)/2; i++)
        second_half = second_half->next;
    
    // Confronto il contenuto delle due metà per vedere se costituisce un  tandem
    bool still_tandem = true;
    // Per tutti gli elementi fino a metà (escluso l'eventuale carattere centrale)
    // oppure finché non trovo due caratteri diversi all'interno delle due metà
    for(int i=0; still_tandem && (i<len/2); i++) {
        // Verifica se due nodi contengono lo stesso carattere
        still_tandem =  compare_char(head, second_half);
        // Avanzo nella prima metà
        head = head->next;
        // Avanzo nella seconda metà
        second_half = second_half->next;
    }

    // Restituisco il risultato del confronto
    return still_tandem;
}

/**
 * Se la lista in input costituisce un tandem la trasforma in un palindromo
 * @param [in] head puntatore alla testa della lista
 * @param [out] palindrome array di caratteri preallocato per salvare la stringa palindroma
 * @return true se la conversione è avvenuta correttamente, false altrimenti
 * Il processo di conversione dovrà avvenire mantenendo inalterata 
 * la prima ripetizione della sottostringa e invertendo la seconda
**/
bool tandem_2_palindrome(struct CharNode *head, char palindrome[]){
    // Calcolo la lunghezza della lista
    int len = list_len(head);

    // Verifico se rappresenta un tandem
    if (!is_tandem(head))
        return false;

    // Mi assicuro che la stringa termini correttamente
    palindrome[len]='\0';
    // Per tutti i nodi fino a raggiungere la seconda metà della stringa
    for(int i=0; i<(len+1)/2; i++) {
        // Copio il valore del nodo nella stringa a i caratteri dall'inizio
        palindrome[i] = head->value;
        // Copio il valore del nodo nella stringa a i caratteri dalla fine
        palindrome[len-1-i] = head->value;
        // Avanzo al nodo successivo
        head=head->next;
    }

    // Restituisco true, dato che la conversione è avvenuta correttamente
    return true;
}