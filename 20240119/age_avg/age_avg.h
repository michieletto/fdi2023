#ifndef __AGE_AVG_H__
#define __AGE_AVG_H__

// Include le librerie necessarie
#include <stdio.h>          // Input/output
#include <stdlib.h>         // Standard library
#include <stdbool.h>        // Booleani
#include <string.h>         // Stringhe

// Numero massimo di caratteri per riga nel file
// usare questo valore se serve usare un buffer
// per leggere stringhe dal file
#define MAX_CHARS_PER_ROW 1024

// Calcola l'età media dei soggetti elencati caricandoli da file
float get_age_avg(char *filename);

// Salva su file il valore dell'età media
bool save_age_avg(char *filename, float age_avg);

#endif // __AGE_AVG_H__