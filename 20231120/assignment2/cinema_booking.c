// cinema_booking.c
#include <stdio.h>

/**
 * Chiedere quanti posti totali sono disponibili
 * @return il numero di posti totali
**/
int ask_available() {
    int tot_avaible = -1;
    for(;;) {
        // Chiedere quanti posti totali sono disponibili
        printf("What's the total amount of available seats?\n");
        scanf("%d", &tot_avaible);
        // Se il numero di posti totali non è maggiore di 0
        if(tot_avaible>0) {
            break;
        }
        // stampare un messaggio di errore e chiedere di nuovo
        printf("Invalid number of seats. Please, try again.\n");
    }
    return tot_avaible;
}

/** 
 * Chiedere quanti posti possono essere prenotati al massimo in una volta
 * @param [in] tot_available numero di posti totali
 * @return il numero di posti prenotabili in una volta
**/
int ask_max_bookable(int tot_available) {
    int max_bookable = -1;
    for(;;) {
        // Chiedere quanti posti possono essere prenotati al massimo in una volta
        printf("What's the maximum number of available seats?\n");
        scanf("%d", &max_bookable);
        // Se il numero di posti prenotabili in una volta non è maggiore di 0
        // oppure non è minore o uguale al numero di posti totali
        if (max_bookable > 0 && max_bookable<= tot_available) {
            break;
        }
        // stampare un messaggio di errore e chiedere di nuovo
        printf("Invalid number of seats. Please, try again.\n");
    }
    return max_bookable;
}

// Main function
int main() {
    // Inizializzare
    // Totale posti disponibili
    int tot_avaible = ask_available();
    // Massimo di posti prenotabili
    int max_bookable = ask_max_bookable(tot_avaible);
    // Posti da prenotare
    int next_booking = 0;
    // Totale di posti prenotati
    int tot_bookings = 0;
    // Numero di posti disponibili
    int avaible = tot_avaible - tot_bookings;
    
    do {
        // Chiedere quanti posti prenotare
        printf("How many seats do you want to book?\n");
        scanf("%d", &next_booking);
        // Se il numero di posti da prenotare 
        // è maggiore del numero di posti disponibili, oppure
        // è maggiore del massimo numero di posti prenotabili, oppure
        // è minore del numero di posti prenotati
        if (next_booking > avaible ||
            next_booking > max_bookable ||
            next_booking < -tot_bookings) {
            // stampare un messaggio di errore
            printf("Invalid number of seats. Please, try again.\n");
            // e ripartire con il ciclo
            continue;
        }
        // se invece il numero di posti da prenotare è nullo
        if (next_booking == 0) {
            // uscire dal ciclo
            break;
        }
        // altrimenti il numero di prenotazioni è valido
        // aggiornare il numero di posti prenotati
        tot_bookings += next_booking;
        // aggiornare il numero di posti disponibili
        avaible -= next_booking;
        // stampare un messaggio di conferma in base al segno del numero di posti prenotati
        if (next_booking < 0) {
            printf("You have cancelled %d seats.\n", -next_booking);
        } else {
            printf("You have booked %d seats.\n", next_booking);
        }

        // stampare il numero di posti disponibili
        printf("Available seats: %d\n", avaible);
    } while (avaible > 0);
    
    // uscire dal programma
    return 0;
}