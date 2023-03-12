#ifndef _heap_h
#define _heap_h 1
#include "data_structures.h"

HEAP *    init(HEAP *, int);
void    heapify(HEAP *, int);
void   heapInsert(HEAP *, double);
double   extractMin(HEAP *, double);
void printHeap(HEAP*);
void swap(ELEMENT **a, ELEMENT **b);


#endif