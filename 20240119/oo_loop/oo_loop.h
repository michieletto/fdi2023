#ifndef __OO_LOOP_H__
#define __OO_LOOP_H__

// Include le librerie necessarie
#include <stdio.h>          // Input/output
#include <stdlib.h>         // Standard library
#include <stdbool.h>        // Booleani

// Duplica la capacità dell'array di interi
int *resize_array(int *array, int *capacity);

// Legge un array di interi da tastiera fino a quando 
// non viene inserito un valore negativo
int *read_array(int *size, int *capacity);

#endif // __OO_LOOP_H__