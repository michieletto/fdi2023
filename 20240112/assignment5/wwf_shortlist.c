// wwf_shortlist.c
// Include le librerie necessarie
#include "wwf_shortlist.h"       // Libreria con le funzioni

// Main function
int main() {
    // Definire un array di specie
    Species wwf_shortlist[NUM_SPECIES] = {
        {"Sumatran Orangutan", "Pongo abelii", 7500, 1},
        {"Amur Leopard", "Panthera pardus orientalis", 120, 2},
        {"Vaquita", "Phocoena sinus", 10, 3},
        {"Javan Rhino", "Rhinoceros sondaicus", 70, 4},
        {"Northern White Rhino", "Ceratotherium simum cottoni", 2, 5},
        {"Cross River Gorilla", "Gorilla gorilla diehli", 300, 6},
        {"Saola", "Pseudoryx nghetinhensis", 100, 7},
        {"Hawksbill Turtle", "Eretmochelys imbricata", 40, 8},
        {"South China Tiger", "Panthera tigris amoyensis", 30, 9},
        {"Mountain Gorilla", "Gorilla beringei beringei", 1000, 10},
        {"Philippine Eagle", "Pithecophaga jefferyi", 400, 11},
        {"Western Lowland Gorilla", "Gorilla gorilla gorilla", 600, 12},
    };

    /*************************************/
    /*  INIZIO  PARTE DA INIZIALIZZARE   */
    /*************************************/

    Species *common_asc[NUM_SPECIES] = {    // Ordinamento per nome comune in ordine crescente
        &wwf_shortlist[1],                  // 1. Amur Leopard
        &wwf_shortlist[5],                  // 2. Cross River Gorilla
        &wwf_shortlist[7],                  // 3. Hawksbill Turtle
        &wwf_shortlist[3],                  // 4. Javan Rhino
        &wwf_shortlist[9],                  // 5. Mountain Gorilla
        &wwf_shortlist[4],                  // 6. Northern White Rhino
        &wwf_shortlist[10],                 // 7. Philippine Eagle
        &wwf_shortlist[6],                  // 8. Saola
        &wwf_shortlist[8],                  // 9. South China Tiger
        &wwf_shortlist[0],                  // 10. Sumatran Orangutan
        &wwf_shortlist[2],                  // 11. Vaquita
        &wwf_shortlist[11],                 // 12. Western Lowland Gorilla
    };
    Species *common_des[NUM_SPECIES] = {    //  Ordinamento per nome comune in ordine decrescente
        &wwf_shortlist[11],                 // 1. Western Lowland Gorilla
        &wwf_shortlist[2],                  // 2. Vaquita
        &wwf_shortlist[0],                  // 3. Sumatran Orangutan
        &wwf_shortlist[8],                  // 4. South China Tiger
        &wwf_shortlist[6],                  // 5. Saola
        &wwf_shortlist[10],                 // 6. Philippine Eagle
        &wwf_shortlist[4],                  // 7. Northern White Rhino
        &wwf_shortlist[9],                  // 8. Mountain Gorilla
        &wwf_shortlist[3],                  // 9. Javan Rhino
        &wwf_shortlist[7],                  // 10. Hawksbill Turtle
        &wwf_shortlist[5],                  // 11. Cross River Gorilla
        &wwf_shortlist[1],                  // 12. Amur Leopard
    };
    Species *scientific_asc[NUM_SPECIES] = {    // Ordinamento per nome scientifico in ordine crescente
        &wwf_shortlist[4],                      // 1. Ceratotherium simum cottoni
        &wwf_shortlist[7],                      // 2. Eretmochelys imbricata
        &wwf_shortlist[9],                      // 3. Gorilla beringei beringei
        &wwf_shortlist[5],                      // 4. Gorilla gorilla diehli
        &wwf_shortlist[11],                     // 5. Gorilla gorilla gorilla
        &wwf_shortlist[1],                      // 6. Panthera pardus orientalis
        &wwf_shortlist[8],                      // 7. Panthera tigris amoyensis
        &wwf_shortlist[2],                      // 8. Phocoena sinus
        &wwf_shortlist[10],                     // 9. Pithecophaga jefferyi
        &wwf_shortlist[0],                      // 10. Pongo abelii
        &wwf_shortlist[6],                      // 11. Pseudoryx nghetinhensis
        &wwf_shortlist[3],                      // 12. Rhinoceros sondaicus
    };
    Species *scientific_des[NUM_SPECIES] = {    // Ordinamento per nome scientifico in ordine decrescente
        &wwf_shortlist[3],                      // 1. Rhinoceros sondaicus
        &wwf_shortlist[6],                      // 2. Pseudoryx nghetinhensis
        &wwf_shortlist[0],                      // 3. Pongo abelii
        &wwf_shortlist[10],                     // 4. Pithecophaga jefferyi
        &wwf_shortlist[2],                      // 5. Phocoena sinus
        &wwf_shortlist[8],                      // 6. Panthera tigris amoyensis   
        &wwf_shortlist[1],                      // 7. Panthera pardus orientalis
        &wwf_shortlist[11],                     // 8. Gorilla gorilla gorilla
        &wwf_shortlist[5],                      // 9. Gorilla gorilla diehli
        &wwf_shortlist[9],                      // 10. Gorilla beringei beringei
        &wwf_shortlist[7],                      // 11. Eretmochelys imbricata
        &wwf_shortlist[4],                      // 12. Ceratotherium simum cottoni
    };
    Species *remaining_asc[NUM_SPECIES] = {     // Ordinamento per numero di esemplari rimasti in ordine crescente
        &wwf_shortlist[4],                      // 1. 2
        &wwf_shortlist[2],                      // 2. 10
        &wwf_shortlist[8],                      // 3. 30
        &wwf_shortlist[7],                      // 4. 40
        &wwf_shortlist[3],                      // 5. 70
        &wwf_shortlist[6],                      // 6. 100
        &wwf_shortlist[1],                      // 7. 120
        &wwf_shortlist[5],                      // 8. 300
        &wwf_shortlist[10],                     // 9. 400
        &wwf_shortlist[11],                     // 10. 600
        &wwf_shortlist[9],                      // 11. 1000
        &wwf_shortlist[0],                      // 12. 7500
    };
    Species *remaining_des[NUM_SPECIES] = {     // Ordinamento per numero di esemplari rimasti in ordine decrescente
        &wwf_shortlist[0],                      // 1. 7500
        &wwf_shortlist[9],                      // 2. 1000
        &wwf_shortlist[11],                     // 3. 600
        &wwf_shortlist[10],                     // 4. 400
        &wwf_shortlist[5],                      // 5. 300
        &wwf_shortlist[1],                      // 6. 120
        &wwf_shortlist[6],                      // 7. 100
        &wwf_shortlist[3],                      // 8. 70
        &wwf_shortlist[7],                      // 9. 40
        &wwf_shortlist[8],                      // 10. 30
        &wwf_shortlist[2],                      // 11. 10
        &wwf_shortlist[4],                      // 12. 2
    };
    Species *endangered_asc[NUM_SPECIES] = {    // Ordinamento per numero di esemplari rimasti in ordine crescente
        &wwf_shortlist[0],                      // 1. 1
        &wwf_shortlist[1],                      // 2. 2
        &wwf_shortlist[2],                      // 3. 3                                                                                                                                                                                                                                                                                                                             
        &wwf_shortlist[3],                      // 4. 4
        &wwf_shortlist[4],                      // 5. 5
        &wwf_shortlist[5],                      // 6. 6
        &wwf_shortlist[6],                      // 7. 7
        &wwf_shortlist[7],                      // 8. 8
        &wwf_shortlist[8],                      // 9. 9
        &wwf_shortlist[9],                      // 10. 10
        &wwf_shortlist[10],                     // 11. 11
        &wwf_shortlist[11],                     // 12. 12
    };
    Species *endangered_des[NUM_SPECIES] = {    // Ordinamento per numero di esemplari rimasti in ordine decrescente
        &wwf_shortlist[11],                     // 1. 12
        &wwf_shortlist[10],                     // 2. 11
        &wwf_shortlist[9],                      // 3. 10
        &wwf_shortlist[8],                      // 4. 9
        &wwf_shortlist[7],                      // 5. 8
        &wwf_shortlist[6],                      // 6. 7
        &wwf_shortlist[5],                      // 7. 6
        &wwf_shortlist[4],                      // 8. 5
        &wwf_shortlist[3],                      // 9. 4
        &wwf_shortlist[2],                      // 10. 3
        &wwf_shortlist[1],                      // 11. 2
        &wwf_shortlist[0],                      // 12. 1
    };

    /*************************************/
    /*   FINE  PARTE DA INIZIALIZZARE    */
    /*************************************/
    char sort_type;
    printf("Sort type: ");
    scanf("%c", &sort_type);
    printf("\n");

    Species **sorted = NULL;
    switch (sort_type)
    {
    case COMMON_ASC:
        sorted = common_asc;
        break;
    case COMMON_DES:
        sorted = common_des;
        break;
    case SCIENTIFIC_ASC:
        sorted = scientific_asc;
        break;
    case SCIENTIFIC_DES:
        sorted = scientific_des;
        break;
    case REMAINING_ASC:
        sorted = remaining_asc;
        break;
    case REMAINING_DES:
        sorted = remaining_des;
        break;
    case ENDANGERED_ASC:
        sorted = endangered_asc;
        break;
    case ENDANGERED_DES:
        sorted = endangered_des;
        break;
    }

    for (int i = 0; i < NUM_SPECIES; i++){
        if((sorted != NULL) && (sorted[i] != NULL))
            printf("%s, %s, %d, %d\n", sorted[i]->common, sorted[i]->scientific, sorted[i]->remaining, sorted[i]->endangered);
        else
            printf("Data not available\n");
    }
    
}