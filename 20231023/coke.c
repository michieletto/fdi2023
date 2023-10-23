// Include the standard input/output library
#include <stdio.h>
// Include the standard boolean library
#include <stdbool.h>

int main() {
    // Ogni bibita costa 50
    float amount_due = 50.0f; // f indica un valore di tipo float
                    // 50 -> indica un valore di tipo int
                    // 50.0 -> indica un valore di tipo double
    // le monete accettare sono 5/10/25
    // Altro modo per inizializzare un array, senza specificare 
    // la dimensione che viene calcolata automaticamente
    // in base al numero di elementi inizializzati
    float valid_amounts[] = {5.0f, 10.0f, 25.0f}; 
    // Valore della moneta inserita dall'utente
    float inserted_amount = 0.0f;
    // Il procedimento si ripete fino a raggiungere l’importo dovuto 
    while (amount_due > 0.0f)
    {
        // Il distributore espone l’importo dovuto
        printf("L'importo dovuto è %g\n", amount_due);
        // attende che l’utente inserisca una moneta valida
        while (true)
        {    
            // Flag per indicare se la moneta inserita è valida
            bool is_valid = false;
            // Chiede all'utente di inserire una moneta
            printf("Inserire una moneta\n");
            // Attende che l'utente inserisca una moneta
            scanf("%f", &inserted_amount);
            // Per tutte le monete nell'array delle monete valide
            for (int i = 0; i < 3; i++)
            {
                // Controllare se la moneta inserita corrissponde
                // all'elemento corrente (i) dell'array
                if (inserted_amount == valid_amounts[i])
                {
                    // Aggiornare il flag
                    is_valid = true;
                    // Uscire dal ciclo for
                    break;
                }
            }
            // Se la moneta è valida 
            if(is_valid) {
                // Uscire dal ciclo while
                break;
            }
            // le monete non accettate sono scartate
            printf("La moneta inserita non è valida!\n");
        }
        // l’importo dovuto viene aggiornato
        // amount_due = amount_due - inserted_amount;
        amount_due -= inserted_amount;
    }
    // Il distributore espone il resto (0 se non presente)
    printf("Il resto è %g\n", -amount_due);
    // ed eroga la bibita
    printf("La bibita è stata erogata\n");
}