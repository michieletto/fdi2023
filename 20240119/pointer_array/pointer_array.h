#ifndef __POINTER_ARRAY_H__
#define __POINTER_ARRAY_H__

// Include le librerie necessarie
#include <stdio.h>          // Input/output
#include <stdlib.h>         // Standard library
#include <stdbool.h>        // Booleani

// Stampa un array di interi da start a end
void print_array(int *start, int *end);

// Raddoppia il valore degli elementi di un array da start a end
void twice_array(int *start, int *end);

// Restituisce la somma degli elementi di un array da start a end
int sum_array(int *start, int *end);

// Inverte l'ordine degli elementi di un array da start a end
void reverse_array(int *start, int *end);

// Trova un elemento in un array da start a end
int *find_array(int *start, int *end, int value);

#endif // __POINTER_ARRAY_H__