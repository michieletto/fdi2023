// pirates.c
// Include le librerie necessarie
#include <stdio.h>      // Input/output
#include <stdbool.h>    // Booleani
#include <stdlib.h>     // Numeri pseudo-random

// Costanti di gioco
#define SEED 42

// Opzioni a disposizione del giocatore
typedef enum{
    INVALID_OPTION = -1,
    EXPLORE = 1,
    HIDE,
    ENTER_THE_COVE,
    CLIMB_A_PALM,
    LEAVE_THE_ISLAND,
    LAST_GAME_OPTION,
} game_options;

/**
 * Stampa a schermo il menù di gioco 
**/
void print_menu(float tau, float rho, int sigma) // [implementata]
{
    // Creare un array di stringhe contenente le opzioni di gioco
    char *options[] = {
        "EXPLORE",
        "HIDE",
        "ENTER THE COVE",
        "CLIMB A PALM",
        "LEAVE THE ISLAND",
    };
    // Stampare a schermo le opzioni di gioco
    // usando un ciclo per scorrere l'array di stringhe
    printf(">>> Pirate's island: treasure hunt <<<\n");
    printf(">>> Your stats <<<\n");
    printf("Probability to find a treasure: %.2f\n", tau);
    printf("Probability to be robbed: %.2f\n", rho);
    printf("You collected %d gold coins\n", sigma);
    for (int i = EXPLORE; i < LAST_GAME_OPTION; i++)
    {
        printf("%d. %s\n", i, options[i-1] );
    }
    printf("\n");
}

/**
 * Verifica se un evento è avvenuto con una certa probabilità
 * @param [in] tau probabilità che l'evento si verifichi
 * @return true se l'evento è avvenuto, false altrimenti
**/
bool is_event_happened(float probability) // [implementata]
{
    // Generare un numero pseudo-random tra 0 e 1
    float random_number = (float)rand()/(float)RAND_MAX;
    // Verificare se il numero generato è minore della probabilità
    // Se è minore, l'evento è avvenuto
    // Se è maggiore, l'evento non è avvenuto
    return random_number <= probability;
}

/**
 * Chiede all'utente la prossima opzione di gioco
 * Ripete la richiesta finché non si ottiene una risposta valida
 * 
 * @return indice della prossima opzione di gioco
**/
int ask_user() {
    // Inizializzare la variabile che contiene la prossima opzione scelta dall'utente
    int option_num = INVALID_OPTION;

    // Chiedere all'utente quale opzione vuole selezionare
    for(;;) {
        printf("Next option? This will change your stats\n");
        scanf("%d", &option_num);
        // verificare che l'utente inserisca un indice presente nel menù
        // oppure, se è presente un importo in carrello, l'opzione per il pagamento del conto
        if (option_num >= EXPLORE && option_num < LAST_GAME_OPTION) {
            break;
        } else {
            // in caso contrario, stampare un messaggio e ripetere la richiesta
            printf("Invalid option\n");
        }
    }
    return option_num;
}

/**
 * Aggiorna la probabilità di trovare un tesoro
 * @param [in] tau probabilità di trovare un tesoro
 * @param [in] option opzione scelta dal giocatore
 * @return la nuova probabilità di trovare un tesoro
**/
float update_tau(float tau, int option) {
    // Aggiornare la probabilità di trovare un tesoro in base all'opzione scelta
    switch (option)
    {
        // esplorare
        case EXPLORE:
            tau = tau + 0.045f;
            break;
        // nascondersi
        case HIDE:
            tau = 0.87f*tau;
            break;
        // entrare nella grotta
        case ENTER_THE_COVE:
            tau = 1.3f*tau;
            break;
        // arrampicarsi su una palma
        case CLIMB_A_PALM:
            tau = tau - 0.056f;
            break;
    }
    // assicurarsi che la probabilità sia compresa tra 0.05 e 1
    tau = tau < 0.05f ? 0.05f : tau;
    tau = tau > 1.0f ? 1.0f : tau;
    // restituire la nuova probabilità di trovare un tesoro
    return tau;
}

/**
 * Aggiorna la probabilità di essere derubati
 * @param [in] rho probabilità di essere derubati
 * @param [in] option opzione scelta dal giocatore
 * @return la nuova probabilità di essere derubati
**/
float update_rho(float rho, int option) {
    // Aggiornare la probabilità di essere derubati in base all'opzione scelta
    switch (option)
    {
        // esplorare
        case EXPLORE:           
            rho = 1.6f*rho;
            break;
        // nascondersi
        case HIDE:
            rho = rho - 0.091f;
            break;
        // entrare nella grotta
        case ENTER_THE_COVE:
            rho = rho + 0.078f;
            break;
        // arrampicarsi su una palma
        case CLIMB_A_PALM:
            rho = 0.73f*rho;
            break;
    }
    // assicurarsi che la probabilità sia compresa tra 0.05 e 1
    if (rho < 0.05f) {
        rho = 0.05f;
    } else if (rho > 1.0f) {
        rho = 1.0f;
    }
    // restituire la nuova probabilità di essere derubati
    return rho;
}

/**
 * Aggiorna il numero di monete d'oro accumulate
 * @param [in] tau probabilità di trovare un tesoro
 * @param [in] rho probabilità di essere derubati
 * @param [in] sigma numero di monete d'oro accumulate
 * @return il nuovo numero di monete d'oro accumulate
**/
int update_sigma(float tau, float rho, int sigma) // [implementata]
{
    // se il giocatore viene derubato
    if (is_event_happened(rho) && is_event_happened(rho)) {
        printf("The pirates robbed you!\n");
        // sottrarre un numero di monete d'oro random compreso
        // tra 0 e il numero di monete d'oro accumulate
        if (sigma > 0) {
            sigma -= rand()%sigma;
        }
    } 
    // altrimenti, se il giocatore trova un tesoro
    else if (is_event_happened(tau) || is_event_happened(tau)) {
        printf("You found a treasure!\n");
        // aggiungere un numero di monete d'oro random 
        // compreso tra 0 e 100
        sigma+=rand()%100;
    } 
    // altrimenti non è successo nulla
    else {
        printf("Nothing happened\n");
    }
    // Restituire il nuovo numero di monete d'oro accumulate
    return sigma;
}

// Main function
int main() {
    // Inizializzazione del seed pseudo-random per mantenere la ripetibilità
    // Mantenere come prima istruzione del main
    srand(SEED);
    // Inizializzazione delle seguenti variabili:
    // l'indice della prossima opzione scelta dal giocatore a INVALID_OPTION 
    int next_option = INVALID_OPTION;
    // la probabilità di trovare un tesoro a 0.2
    float tau = 0.2f;
    // la probabilità di essere derubati a 0.25
    float rho = 0.25f;
    // il numero di monete d'oro trovate a 0
    int sigma = 0;
    // loop di gioco
    // rimanere nel loop finché l'utente non seleziona l'opzione per lasciare l'isola
    for (;;)
    {
        // mostrare il menù di gioco
        print_menu(tau, rho, sigma);
        // chiedere all'utente quale opzione vuole selezionare
        next_option = ask_user();
        // se l'utente seleziona l'opzione per lasciare l'isola
        if (next_option == LEAVE_THE_ISLAND) {
            // uscire dal loop
            break;
        }
        // negli altri casi
        // aggiornare la probabilità di trovare un tesoro
        tau = update_tau(tau, next_option);
        // aggiornare la probabilità di essere derubati
        rho = update_rho(rho, next_option);
        // aggiornare il numero di monete d'oro accumulate
        sigma = update_sigma(tau, rho, sigma);
    }

    // Gioco terminato
    printf(">>>       GAME OVER       <<<\n");
    printf(">>> YOU WON %d GOLD COINS <<<\n", sigma);

    // uscire dal programma
    return 0;    
}