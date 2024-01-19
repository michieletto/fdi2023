// age_avg.c
// Include le librerie necessarie
#include "age_avg.h"         // Libreria con le funzioni

/**
 * Calcola l'età media dei soggetti elencati caricandoli da file
 * @param [in] filename nome del file da cui caricare i dati
 * @return età media dei soggetti elencati
 * @note il file è composto da una prima riga contenente il numero di soggetti
 *       (es. "3") e da una successiva serie di righe, ognuna delle quali
 *       contiene il nome e l'età di un soggetto separati da uno spazio
 *       (es. "Mario Rossi 20")
 * @note se il file non esiste o non è leggibile, ritornare 0.0f
**/
float get_age_avg(char *filename) {
    // Apertura del file in lettura
    FILE *file = fopen(filename, "r");
    // Verifica se il file è stato aperto correttamente
    if (file == NULL) {
        return 0.0f;
    }

    // Variabili di appoggio
    // Buffer per la lettura delle stringhe
    char buffer[MAX_CHARS_PER_ROW] = {0};
    // Età
    int age = 0;
    // Numero di soggetti
    int num_subjects = 0;
    // Somma delle età
    int age_sum = 0;
    
    // Lettura del numero di soggetti
    fscanf(file, "%d", &num_subjects);
    // Lettura del resto del file
    for(int i = 0; i < num_subjects; i++) {
        // Lettura del nome
        fscanf(file, "%s", buffer);
        // Lettura del cognome
        fscanf(file, "%s", buffer);
        // Lettura dell'età
        fscanf(file, "%d", &age);
        // Somma delle età
        age_sum += age;
    }

    // Chiusura del file
    fclose(file);

    // Se non ci sono soggetti
    if (num_subjects == 0) {
        return 0.0f;
    }
    // Calcolo dell'età media
    return (float)age_sum / (float)num_subjects;
}

/**
 * Salva su file il valore dell'età media
 * @param [in] filename nome del file su cui salvare i dati
 * @param [in] age_avg età media da salvare
 * @return true se il file è stato salvato correttamente, false altrimenti
 * @note il file deve contenere una sola riga con l'età media
 *      (es. "Average age: 20.5")
**/
bool save_age_avg(char *filename, float age_avg) {
    // Apertura del file in scrittura
    FILE *file = fopen(filename, "w");
    // Verifica se il file è stato aperto correttamente
    if (file == NULL) {
        return false;
    }

    // Scrittura dell'età media
    fprintf(file, "Average age: %f", age_avg);

    // Chiusura del file
    fclose(file);

    return true;
}