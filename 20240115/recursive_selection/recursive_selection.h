#ifndef __RECURSIVE_SELECTION_H__
#define __RECURSIVE_SELECTION_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Trova ricorsivamente il minimo all'interno di un array da ordinare
int *recursive_min_index(int *start, int* end);

// Ordina ricorsivamente un array usando l'algoritmo selection sort
void recursive_selection_sort(int* start, int* end);

#endif // __RECURSIVE_SELECTION_H__