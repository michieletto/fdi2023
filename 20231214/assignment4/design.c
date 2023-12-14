// design.c
#include "design.h"        // Libreria con le funzioni

/**
 * Calcolare il peso totale del pezzo
 * @param [in] item array di componenti
 * @param [in] size numero di componenti
 * @return peso totale del pezzo
 * sommatoria dei pesi dei componenti che formano il pezzo
 * per la quantità di ciascun componente
**/
float get_total_weight(struct Component item[], int size) {
    // Definire la variabile per tenere traccia del peso totale
    float total_weight = 0.0f;
    // Iterare su tutti i componenti
    for (int i = 0; i < size; i++) {
        // Aggiungere il peso del componente al peso totale
        // moltiplicando il peso per la quantità
        total_weight += item[i].weight * item[i].quantity;
    }
    // Ritornare il peso totale
    return total_weight;
}

/**
 * Calcolare la superficie totale del pezzo
 * @param [in] item array di componenti
 * @param [in] size numero di componenti
 * @return superficie totale del pezzo
 * sommatoria del prodotto delle 2 dimensioni
 * maggiori dei componenti che formano il pezzo
 * per la quantità di ciascun componente
**/
float get_total_area(struct Component item[], int size) {
    // Definire la variabile per tenere traccia della superficie totale
    float total_area = 0.0f;
    // Iterare su tutti i componenti
    for (int i = 0; i < size; i++) {
        // Definire le variabili per memorizzare le dimensioni maggiori
        float first = 0.0f;
        float other = 0.0f;
        // Trovare la prima dimensione maggiore
        // confrontando altezza e lunghezza
        if (item[i].height > item[i].length) {
            first = item[i].height;
            other = item[i].length;
        } else {
            first = item[i].length;
            other = item[i].height;
        }
        // Trovare la seconda dimensione maggiore
        // confrontando la dimensione più corta e la profondità
        float second = (item[i].depth > other) ? item[i].depth : other;
        // Aggiungere la superficie del componente alla superficie totale
        // moltiplicando le 2 dimensioni maggiori per la quantità
        total_area += first * second * item[i].quantity;
    }
    // Ritornare la superficie totale
    return total_area;
}

/**
 * Calcolare il peso medio per componente
 * @param [in] item array di componenti
 * @param [in] size numero di componenti
 * @return peso medio per componente
 * peso totale diviso per numero totale di componenti che formano il pezzo
**/
float get_average_weight(struct Component item[], int size) {
    // Calcolare il peso totale
    float total_weight = get_total_weight(item, size);
    // Calcolare la quantità totale di componenti
    int total_quantity = 0;
    // Iterare su tutti i componenti
    for (int i = 0; i < size; i++) {
        // Aggiungere la quantità del componente alla quantità totale
        total_quantity += item[i].quantity;
    }
    // Ritornare il peso medio
    return total_weight / total_quantity;
}

/**
 * Fornire il materiale principale di cui è composto il pezzo
 * @param [in] item array di componenti
 * @param [in] size numero di componenti
 * @return materiale principale di cui è composto il pezzo
 * il materiale principale è quello che compare più volte
 * tra i materiali dei componenti del pezzo
**/
Material get_main_material(struct Component item[], int size) {
    // Definire la variabile per tenere traccia del materiale principale
    Material main_material = METAL;
    // Definire la variabile per tenere traccia del numero di occorrenze
    int max_occurrences = 0;
    // Definire un array per tenere traccia delle occorrenze
    int occurrences[FOAM + 1] = {0};
    // Iterare su tutti i componenti
    for (int i = 0; i < size; i++)
    {
        // Incrementare il numero di occorrenze del materiale del componente
        occurrences[item[i].material]+=item[i].quantity;
        // Se il numero di occorrenze del materiale del componente
        // è maggiore del numero di occorrenze del materiale principale
        if (occurrences[item[i].material] > max_occurrences) {
            // Aggiornare il numero di occorrenze del materiale principale
            max_occurrences = occurrences[item[i].material];
            // Aggiornare il materiale principale
            main_material = item[i].material;
        }
    }
    // Ritornare il materiale principale
    return main_material;
}

/**
 * Calcolare il prezzo minimo di vendita del pezzo
 * @param [in] item array di componenti
 * @param [in] size numero di componenti
 * @return prezzo minimo di vendita del pezzo
 * 120% della somma dei prezzi dei componenti che formano il pezzo
*/
float get_min_price(struct Component item[], int size) {
    // Definire la variabile per tenere traccia del prezzo totale
    float total_price = 0.0f;
    // Iterare su tutti i componenti
    for (int i = 0; i < size; i++) {
        // Aggiungere il prezzo del componente al prezzo totale
        // moltiplicando il prezzo per la quantità
        total_price += item[i].price * item[i].quantity;
    }
    // Ritornare il prezzo minimo
    return total_price * 1.2f;
}