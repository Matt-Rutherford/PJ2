//Matthew Rutherford 1227041896
#ifndef _heap_h
#define _heap_h 1
#include "data_structures.h"

HEAP *    init(HEAP *, int);
void buildMinHeap(HEAP*);
void    heapify(HEAP *, int);
void   heapInsert(HEAP *, double);
double   extractMin(HEAP *);
void printHeap(HEAP*);
void decreasekey(HEAP*, int, double);
void swap(ELEMENT **a, ELEMENT **b);



#endif