// f1.c
// Include le librerie necessarie
#include "f1.h"         // Libreria con le funzioni

/**
 * Inserisce le informazioni reletive ad una gara nella carriera del pilota
 * @param driver [in/out] informazioni relative alla carriera di uno specifico pilota
 * @param race [in] informazioni relative ad una gara
 * @return restituisce il numero di gare disputate dal pilota nella sua carriera fino ad un massimo di MAX_RACES
 *         se la soglia viene superata o se necessario gestire altri errori ritornare 0
**/
int insert_race(Driver *driver, RaceResult race) {
    // Verifica che il puntatore non sia NULL
    if (driver == NULL) {
        return 0;
    }

    // Verifica che il numero di gare non sia superiore al massimo
    if (driver->num_races < MAX_RACES) {
        // Inserisce le informazioni relative alla gara
        driver->races[driver->num_races].position = race.position;
        driver->races[driver->num_races].points = race.points;

        // Incrementa il numero di gare disputate dal pilota
        driver->num_races++;
        // Ritorna il numero di gare disputate dal pilota
        return driver->num_races;
    }

    // Ritorna 0 per segnalare un errore
    return 0;
}

/**
 * Calcola il numero di vittorie ottenute dal pilota
 * @param driver [in] informazioni relative alla carriera di uno specifico pilota
 * @return numero di vittorie ottenute dal pilota
 *        se necessario gestire errori, ritornare -1
**/
int get_victories(Driver *driver) {
// Verifica che il puntatore non sia NULL
    if (driver == NULL) {
        return -1;
    }
    
    // Definire una variabile per contare le vittorie
    int victories = 0;
    // Iterare lungo l'array delle gare
    for (int i = 0; i < driver->num_races; i++) {
        // Se il pilota è arrivato primo
        if (driver->races[i].position == 1) {
            // Incrementare il contatore delle vittorie
            victories++;
        }
    }
    // Ritornare il numero di vittoie ottenute dal pilota
    return victories;
}

/**
 * Calcola il numero di podi ottenuti dal pilota
 * @param driver [in] informazioni relative alla carriera di uno specifico pilota
 * @return numero di podi ottenuti dal pilota
 *        se necessario gestire errori, ritornare -1
**/
int get_podiums(Driver *driver) {
    // Verifica che il puntatore non sia NULL
    if (driver == NULL) {
        return -1;
    }
    
    // Definire una variabile per contare i podi
    int podiums = 0;
    // Iterare lungo l'array delle gare
    for (int i = 0; i < driver->num_races; i++) {
        // Se il pilota è arrivato tra i primi 3
        if (driver->races[i].position > 0 && driver->races[i].position <= 3) {
            // Incrementare il contatore dei podi
            podiums++;
        }
    }
    // Ritornare il numero di podi ottenuti dal pilota
    return podiums;
}

/**
 * Calcola i punti medi per gara ottenuti dal pilota
 * @param driver [in] informazioni relative alla carriera di uno specifico pilota
 * @return punti medi per gara ottenuti dal pilota
 *       se necessario gestire errori, ritornare -1.0
 *       se il pilota non ha disputato nessuna gara, ritornare 0.0 
**/
double get_average_points(Driver *driver) {
    // Verifica che il puntatore non sia NULL
    if (driver == NULL) {
        return -1.0;
    }
    
    // Definire una variabile per la somma dei punti
    int sum = 0;
    // Iterare lungo l'array delle gare
    for (int i = 0; i < driver->num_races; i++) {
        // Aggiungere i punti della gara alla somma
        sum += driver->races[i].points;
    }
    
    // Calcolare la media dei punti
    // verificando che il numero di gare non sia 0
    if (driver->num_races != 0) {
        return (double)sum/(double)(driver->num_races);
    }

    // Ritornare la media dei punti
    return 0.0;
}

/**
 * Calcola una statistica su quanti piloti hanno ottenuto
 * un numero di vittorie superiore ad una determinata soglia
 * @param drivers [in] informazioni relative alla carriera degli piloti
 * @param num_drivers [in] numero di piloti
 * @param threshold [in] soglia rispetto alla quale si vuole ottenere l'informazione
 * @return numero di piloti con il numero di vittorie superiore alla soglia in input
 *        se necessario gestire errori, ritornare -1
**/
int best_winners(Driver *drivers, int num_drivers, int threshold) {
    // Definire una variabile per contare i piloti con un numero di vittorie superiore alla soglia
    int count = 0;
    // Iterare lungo l'array dei piloti
    for (int i = 0; i < num_drivers; i++) {
        // Se il numero di vittorie del pilota è superiore alla soglia
        if (get_victories(&drivers[i]) > threshold) {
            // Incrementare il contatore
            count++;
        }
    }
    // Ritornare il numero di piloti con un numero di vittorie superiore alla soglia
    return count;
}

/**
 * Calcola una statistica su quanti piloti hanno ottenuto
 * un numero di podi minore ad una determinata soglia
 * @param drivers [in] informazioni relative alla carriera degli piloti
 * @param num_drivers [in] numero di piloti
 * @param threshold [in] soglia rispetto alla quale si vuole ottenere l'informazione
 * @return numero di piloti con il numero di podi minore della soglia in input
 *        se necessario gestire errori, ritornare -1
**/
int worst_on_podium(Driver *drivers, int num_drivers, int threshold) {
    // Definire una variabile per contare i piloti con un numero di podi inferiore alla soglia
    int count = 0;
    // Iterare lungo l'array dei piloti
    for (int i = 0; i < num_drivers; i++) {
        // Se il numero di podi del pilota è inferiore alla soglia
        if (get_podiums(&drivers[i]) < threshold) {
            // Incrementare il contatore
            count++;
        }
    }
    // Ritornare il numero di piloti con un numero di podi inferiore alla soglia
    return count;
}

/**
 * Calcola una statistica su quanti piloti hanno ottenuto in media
 * un numero di punti compreso tra due soglie
 * @param drivers [in] informazioni relative alla carriera degli piloti
 * @param num_drivers [in] numero di piloti
 * @param threshold_inf [in] soglia inferiore
 * @param threshold_sup [in] soglia superiore
 * @return numero di piloti con la media di punti superiore compresa tra le due soglie
 *        se necessario gestire errori, ritornare -1
**/
int between_average_points(Driver *drivers, int num_drivers, double threshold_inf, double threshold_sup) {
    // Definire una variabile per contare i piloti
    int count = 0;
    // Iterare lungo l'array dei piloti
    for (int i = 0; i < num_drivers; i++) {
        // calcolare la media dei punti del pilota
        double average = get_average_points(&drivers[i]);
        // Se la media dei punti del pilota è compresa tra le due soglie
        if ((average < threshold_sup) && (average > threshold_inf)) {
            // Incrementare il contatore
            count++;
        }
    }
    // Ritornare il numero ottenuto
    return count;
}