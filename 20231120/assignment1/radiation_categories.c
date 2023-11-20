// radiation_categories.c
#include <stdio.h>

int main()
{
    // inizializzare le variabili necessarie
    float value = 0.0f;
    int n_ionizzanti_dirette = 0;
    int n_non_ionizzanti_dirette = 0;
    int n_ionizzanti_indirette = 0;
    int n_non_ionizzanti_indirette = 0;

    // Creare un ciclo infinito
    for (;;)
    {
        // Acquisire il livello di radiazioni di un campione di terreno
        printf("Valore campione (0 per terminare): ");
        scanf("%f", &value);
        // se il valore inserito è nullo
        if (value == 0.0f) {
            // uscire dal ciclo
            break;
        }
        // incrementare il numero relativo alla categoria corrispondente
        // radiazione ionizzante diretta (valore > 1.0)
        if (value > 1.0f) {
            n_ionizzanti_dirette++;
        // radiazione non ionizzante diretta (0.0 < valore <= 1.0)
        } else if (value > 0.0f) {
            n_non_ionizzanti_dirette++;
        // radiazione non ionizzante indiretta (-1.0 <= valore < 0.0)
        } else if (value >= -1.0f) {
            n_non_ionizzanti_indirette++;
        // radiazione ionizzante indiretta (valore < -1.0)
        } else {
            n_ionizzanti_indirette++;
        }
    }
    // stampare il numero di campioni per ogni categoria
    printf("\nCategorie di radiazione\n");
    printf("- Ionizzante diretta: %d\n", n_ionizzanti_dirette);
    printf("- Non ionizzante diretta: %d\n", n_non_ionizzanti_dirette);
    printf("- Non ionizzante indiretta: %d\n", n_non_ionizzanti_indirette);
    printf("- Ionizzante indiretta: %d\n", n_ionizzanti_indirette);

    // uscire dal programma
}