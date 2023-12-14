// currency.c
#include "currency.h"        // Libreria con le funzioni

/**
 * Converte un quantitativo di denaro da una valuta di partenza
 * a una valuta di destinazione
 * @param [in] amount quantitativo di denaro da convertire
 * @param [in] conversion_matrix matrice di conversione
 * @param [in] num_currency numero di valute
 * @param [in] start_currency valuta di partenza
 * @param [in] end_currency valuta di destinazione
 * @return quantitativo di denaro convertito
**/
float convert(float amount, float conversion_matrix[], int num_currency, int start_currency, int end_currency) {
    // Identifica il tasso di cambio
    // tra la valuta di partenza e quella di destinazione
    // selezionando l'elemento corrispondente
    // alla riga start_currency e colonna end_currency
    float conversion_rate = conversion_matrix[start_currency*num_currency+end_currency];
    // e lo moltiplca per il quantitativo di denaro
    return amount * conversion_rate;
}