// cart_discount.c
#include <stdio.h>

// Main function
int main() {
    // inizializza a 0 il numero di articoli acquistati
    int num_articoli = 0;
    // la spesa totale a 0, corrispondete al carrello vuoto;
    int tot_spesa = 0;
    // lo sconto applicato a 0%, corrispondete a nessuno sconto
    int sconto = 0;
    // crea una variabile per salvare il prezzo dell'articolo più costoso
    int prezzo_massimo = 0;
    // il numero totale di articoli
    printf("Numero articoli:\n");
    scanf("%d", &num_articoli);
    // la spesa totale prima dello sconto
    printf("Totale (pre-sconto):\n");
    scanf("%d", &tot_spesa);
    // chiedere all’utente di inserire il prezzo del prossimo articolo
    printf("Prezzo massimo:\n");
    scanf("%d", &prezzo_massimo);
    // se il prezzo massimo è maggiore a 100
    if (prezzo_massimo > 100) {    
        // aggiorna lo sconto applicato al 10%
        sconto = 10;
    }
    // se il numero di articoli acquistati è maggiore a 5
    if (num_articoli > 5) {
        // aggiunge uno sconto del 5%
        sconto += 5;
    }
    // se la spesa totale è maggiore a 500
    if (tot_spesa > 500) {
        // aggiunge uno sconto del 15%
        sconto += 15;
    // altrimenti se la spesa totale è maggiore a 300
    } else if(tot_spesa > 300) {
        // aggiunge uno sconto del 10%
        sconto += 10;
    // altrimenti se la spesa totale è maggiore a 200
    } else if(tot_spesa > 200) {
        // aggiunge uno sconto del 5%
        sconto += 5;
    // altrimenti se la spesa totale è maggiore a 150
    } else if (tot_spesa > 150) {
        // aggiunge uno sconto del 1%
        sconto += 1;
    }
    // Mostra all'utente
    // lo sconto totale
    printf("Sconto:\n%d%%\n", sconto);
    // la spesa totale dopo lo sconto
    printf("Totale (post-sconto):\n%d\n", tot_spesa - (tot_spesa * sconto / 100));

    // uscire dal programma
    return 0;
}