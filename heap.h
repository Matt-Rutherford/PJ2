//Matthew Rutherford 1227041896
#ifndef _heap_h
#define _heap_h 1
#include "data_structures.h"


HEAP* init(HEAP *heap, int capacity);
void buildMinHeap(HEAP *heap);
void heapify(HEAP *heap, int index);
void decreaseKey(HEAP* heap, int position, double newKey);
void   heapInsert(HEAP *heap, double key);
double   extractMin(HEAP *heap);
void printHeap(HEAP *heap);
void swap(ELEMENT **a, ELEMENT **b);


#endif