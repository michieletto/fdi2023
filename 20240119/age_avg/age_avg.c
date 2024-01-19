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
    return 0.0f;
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
    return true;
}