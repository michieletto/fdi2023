// universes.c
// Include le librerie necessarie
#include "universes.h"         // Libreria con le funzioni

/**
 * Libera la memoria allocata finora per l'array di Universeman
 * @param [in/out] caps array di Universeman
 * @param [in] num_caps numero di elementi allocati finora in caps
**/
void free_caps(Universeman *caps, int num_caps) {
    // Per tutti gli elementi dell'array
    for(int i=0; i<num_caps; i++) {
        // Verifico se la stringa del nome del capitano è stata allocata
        if (caps[i].name != NULL) {
            // Libero la memoria allocata per il nome del capitano
            free(caps[i].name);
        }
        // Verifico se la stringa del cognome del capitano è stata allocata
        if (caps[i].surname != NULL) {
            // Libero la memoria allocata per il cognome del capitano
            free(caps[i].surname);
        }
    }
    // Libero la memoria allocata per l'array
    free(caps);
}

/**
 * Aprire in lettura il file di cui si riceve il path in input
 * Analizzare il file per estrarre dal testo le informazioni sul capitano
 * Restituire i dati usando un array di Universeman allocato dinamicamente
 * Usare num_caps_ptr per fornire in output il numero di capitani trovati
 * @param [in] filepath path del file formattato contenente le informazioni sui viaggi
 * @param [out] num_caps_ptr numero di dati sui capitani trovati (uno per riga)
 * @return array allocato dinamicamente di Universeman contenente i dati sui capitani
 * Nel caso la lettura del file o l'allocazione di memoria non vadano a buon fine, 
 * azzerare il valore di num_caps_ptr, liberare la memoria allocata e restituire NULL
**/
Universeman* get_caps(char filepath[], int *num_caps_ptr) {
    // Apre il file in lettura
    FILE* f = fopen(filepath, "r");
    
    // Verifica se il file è stato aperto correttamente
    if (f == NULL) {
        *num_caps_ptr = 0;
        return NULL;
    }

    // Variabili di appoggio
    char buffer[MAX_CHARS_PER_ROW] = {0};
    int cap_pos;

    // Leggo il numero di missioni nel file
    // che corrisponde al numero di capitani
    fscanf(f, "%d", num_caps_ptr);

    // Alloco la memoria relativa all'array di Universeman
    Universeman *caps = malloc(sizeof(Universeman)*(*num_caps_ptr));
    // Verifico se l'allocazione è andata a buon fine 
    if (caps == NULL) {
        *num_caps_ptr = 0;
        fclose(f);
        return NULL;
    }

    // Per tutte le righe nel file
    for(int i=0; i<(*num_caps_ptr); i++){
        // Leggo la posizione del capitano all'interno della riga
        fscanf(f, "%d", &cap_pos);
        // Salto i nomi prima di quelli del capitano
        for (int j = 0; j < 2*(cap_pos-1); j++) {
            fscanf(f, "%s", buffer);
        }
        // Leggo il nome del capitano
        fscanf(f, "%s", buffer);
        // Calcolo la lunghezza del nome del capitano
        int cap_name_len = strlen(buffer);
        // Alloco la stringa per copiare il nome del capitano
        caps[i].name = malloc(sizeof(char)*(cap_name_len+1));
        // Verifico se l'allocazione è andata a buon fine
        if (caps[i].name == NULL) {
            // Cancellazione della memoria già allocata
            // se gli studenti non lo fanno, peccato
            free_caps(caps, i);
            caps = NULL;
            // Parte necessaria per gli studenti
            *num_caps_ptr = 0;
            fclose(f);
            return NULL;
        }
        // Copio il nome del capitano nella struttura
        strcpy(caps[i].name, buffer);
        // Leggo il cognome del capitano
        fscanf(f, "%s", buffer);
        /// Calcolo la lunghezza del cognome del capitano
        int cap_surname_len = strlen(buffer);
        // Alloco la stringa per copiare il cognome del capitano
        caps[i].surname = malloc(sizeof(char)*(cap_surname_len+1));
        // Verifico se l'allocazione è andata a buon fine
        if (caps[i].surname == NULL) {
            // Cancellazione della memoria già allocata
            // se gli studenti non lo fanno, peccato
            free_caps(caps, i);
            caps = NULL;
            // Parte necessaria per gli studenti
            *num_caps_ptr = 0;
            fclose(f);
            return NULL;
        }
        // Copio il cognome del capitano nella struttura
        strcpy(caps[i].surname, buffer);
        // Passo alla riga successiva del file
        // le informazioni non vengono utilizzate
        fscanf(f, "%d %s %d", &cap_name_len, buffer, &cap_surname_len);
    }

    fclose(f);
    // Restituisco l'array allocato contenente le informazioni sui capitani
    return caps;
}

/**
 * Verifica se all'interno del vettore di capitani sono presenti duplicati
 * @param [in] caps_ptr array di Universeman
 * @param [in] num_caps numero di elementi allocati in caps_ptr
 * @return true se sono presenti duplicati, false altrimenti
 * Se il numero di elementi è minore o uguale a 1, restituire false
 * Se l'array è NULL, restituire false
**/
bool has_duplicates(Universeman* caps_ptr, int num_caps) {
    // Verifico se l'array è NULL o se il numero di elementi è minore o uguale a 1
    if (caps_ptr == NULL || num_caps <= 1) {
        return false;
    }
    // Per tutti gli elementi dell'array
    for (int i = 0; i < num_caps; i++) {
        // Per tutti gli elementi successivi
        for (int j = i+1; j < num_caps; j++) {
            // Verifico se i due capitani sono uguali
            if (strcmp(caps_ptr[i].name, caps_ptr[j].name) == 0 &&
                strcmp(caps_ptr[i].surname, caps_ptr[j].surname) == 0) {
                // Se sono uguali, restituisco true
                return true;
            }
        }
    }
    // Se non ho trovato duplicati, restituisco false
    return false;
}