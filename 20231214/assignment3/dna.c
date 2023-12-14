// dna.c
// Include le librerie necessarie
#include "dna.h"        // Libreria con le funzioni

/**
 * Calcola la correttezza della sequenza di DNA in input
 * @param [in] dnaseq sequenza di DNA
 * @return true se la sequenza è valida, false altrimenti
**/
bool is_valid(char dnaseq[])
{
    // Calcolare il numero di elementi della sequenza
    int n_elem = dnalen(dnaseq);
    // Calcolare la dimensione della matrice
    int size = get_matrix_size(n_elem);
    
    // Stampa di debug
    // printf("n_elem: %d\n", n_elem);
    // printf("size: %d\n", size);

    // Calcolare il numero di test da effettuare
    // come il numero di elementi della sequenza
    // meno la dimensione della matrice più uno
    int n_matrix = n_elem - (size*size) + 1;
    // printf("n_matrix: %d\n", n_matrix);

    // Non è necessario creare una nuova matrice
    // basta usare la sequenza in input come
    // una matrice di dimensione size x size
    // e scorrerla per verificarne la validità
    for (int matrix_index = 0; matrix_index < n_matrix; matrix_index++)
    {
        // Inizializzare un flag per verificare
        // la presenza di righe con ripetizioni
        bool row_repetition;
        // e lo stesso per le colonne
        bool col_repetition;

        // print_matrix(dnaseq, matrix_index, size);

        // Vericare le righe
        for (int row_index = 0; row_index < size; row_index++) {
            // Ipotizzare di avere una ripetizione
            row_repetition = true;
            // e scorrere le colonne per smentire l'ipotesi, partendo dalla
            // seconda colonna in modo da avere un valore precedente
            for (int col_index = 1; col_index < size; col_index++) {
                // Calcolare l'indice corrente all'interno della matrice
                // ad indice matrix_index, selezionando la riga row_index
                // e moltiplcandola per la dimensione della matrice in
                // da spostarsi del numero di blocchi corrispondenti in memoria
                // dopodiché selezionare la colonna col_index per ottenere
                // l'indice della cella corrente
                int current_index = matrix_index + row_index * size + col_index;
                // Verificare se il valore corrente è diverso dal precedente
                if (dnaseq[current_index] != dnaseq[current_index - 1]) {
                    // Ho smentito l'ipotesi di ripetizione
                    row_repetition = false;
                    // posso uscire dal ciclo per questa riga
                    break;
                }
            }
            // Se alla fine del ciclo la riga ha ancora ripetizioni
            // so che almeno una riga presenta ripetizioni
            if (row_repetition) {
                // printf("repetition in row %d\n", row_index);
                // e posso uscire dal ciclo per le righe
                break;
            }
        }

        // printf("row_repetition: %s\n", row_repetition?"true":"false");
        
        // Verificare le colonne
        for (int col_index = 0; col_index < size; col_index++)
        {
            // Ipotizzare di avere una ripetizione
            col_repetition = true;
            // e scorrere le righe per smentire l'ipotesi, partendo dalla
            // seconda riga in modo da avere un valore precedente
            for (int row_index = 1; row_index < size; row_index++)
            {
                // Calcolare l'indice corrente all'interno della matrice
                // ad indice matrix_index esattamente come fatto per le righe
                int current_index = matrix_index + row_index * size + col_index;
                // questa volta però il valore precedente si trova nella riga
                int previous_index = matrix_index + (row_index - 1) * size + col_index;
                // Verificare se il valore corrente è diverso dal precedente
                if (dnaseq[current_index] != dnaseq[previous_index]) {
                    // Ho smentito l'ipotesi di ripetizione
                    col_repetition = false;
                    // posso uscire dal ciclo per questa colonna
                    break;
                }
            }
            // Se alla fine del ciclo la colonna ha ancora ripetizioni
            // so che almeno una colonna presenta ripetizioni
            if (col_repetition) {
                // printf("repetition in column %d\n", col_index);
                // e posso uscire dal ciclo per le colonne
                break;
            }
        }
        
        // printf("col_repetition: %s\n", col_repetition?"true":"false");

        // Se ho trovato ripetizioni in almeno una riga e in una colonna
        if (row_repetition && col_repetition) {
            // la sequenza non è valida
            return false;
        }
    }
    // Se sono arrivato fino a qui, la sequenza è valida
    return true; // Modificare con la soluzione corretta
}