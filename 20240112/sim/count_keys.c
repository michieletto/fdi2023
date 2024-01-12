// count_keys.c
// Include le librerie necessarie
#include "count_keys.h"     // Libreria con le funzioni

/**
 * 1. Confronta due caratteri per dire se sono la stessa lettera, 
 * la prima minuscola, la seconda maiuscola 
 * @param [in] first primo carattere da confrontare
 * @param [in] second secondo carattere da confrontare
 * @return true se i caratteri sono la stessa lettera, 
 * la prima minuscola, la seconda maiuscola, false altrimenti
**/
bool is_lower_upper(char first, char second) {
    // Verifico se i caratteri sono la stessa lettera
    // la prima minuscola, la seconda maiuscola
    // sottraendo il valore ASCII della lettera 'a' al primo carattere
    // e il valore ASCII della lettera 'A' al secondo carattere
    // e confrontando i risultati
    return (first - 'a') == (second - 'A');        
}

/**
 * 2. Verifica se l'elemento della matrice in input costituisce una key
 * dati i puntatori all'elemento e ai suoi successivi lungo righe e colonne 
 * @param [in] to_check puntatore all'elemento da controllare
 * @param [in] next_rows puntatore all'elemento successivo nella stessa riga
 * @param [in] next_cols puntatore all'elemento successivo nella stessa colonna
 * @return true se l'elemento è una key, false altrimenti
 * @note se gli elementi successivi non sono presenti, i puntatori sono NULL
 * usando la funzione is_lower_upper() è possibile verificare se un elemento è una key
**/
bool is_key(char *to_check, char *next_rows, char* next_cols) {
    // Verifico se l'elemento da controllare è valido
    if (to_check == NULL) {
        // Se non lo è ritorno false
        return false;
    }
    // Verifico se esiste un elemento successivo nella stessa riga
    if (next_rows != NULL) {
        // Se esiste verifico e l'elemento è una key
        if (is_lower_upper(*to_check, *next_rows))
            // Ritorno true
            return true;
    }
    // Verifico se esiste un elemento successivo nella stessa colonna
    if (next_cols != NULL) {
        // Se esiste verifico e l'elemento è una key
        if (is_lower_upper(*to_check, *next_cols))
            // Ritorno true
            return true;
    }
    // Se non sono state trovate key ritorno false
    return false;
}

/**
 * 3. Conta le keys all'interno di una matrice quadrata di caratteri
 * @param [in] matrix matrice quadrata da esaminare
 * @param [in] size dimensione del lato della matrice
 * @return numero di elementi chiave presenti nella matrice
**/
int count_keys(char *matrix, int size) {
    // Imposto il contatore a zero
    int keys = 0;
    // Dichiariamo i puntatori per scorrere la matrice
    char *current = NULL;
    char *next_rows = NULL;
    char *next_cols = NULL;
    // Per ogni riga e per ogni colonna
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            // Calcolo il puntatore all'elemento corrente
            current = &matrix[i*size+j];
            // Calcolo il puntatore all'elemento successivo nella stessa riga
            next_rows = (j < size-1) ? &matrix[i*size+j+1] : NULL;
            // Calcolo il puntatore all'elemento successivo nella stessa colonna
            next_cols = (i < size-1) ? &matrix[(i+1)*size+j] : NULL;
            // Verifico se l'elemento corrente è una key
            if (is_key(current, next_rows, next_cols)) {
                // e nel caso aumento il contatore
                keys++;
            }
        }
    }
    // Ritorno il conteggio finale
    return keys;
}