//Matthew Rutherford 1227041896
#include <stdio.h>
#include <string.h>
#include <iostream>
#include "util.h"
#include "heap.h"
#include "data_structures.h"
#include <limits>

HEAP* init(HEAP *heap, int capacity){
    heap->H = new ELEMENT * [capacity];
    heap->capacity = capacity;
    heap->size = 0;
    return heap;

}

void buildMinHeap(HEAP *heap) {
    int n = heap->size;
    for (int i = (n / 2) - 1; i >= 0; i--) {
        heapify(heap, i);
    }
}
void heapify(HEAP *heap, int index){
    int smallest = index;
    int left_child = 2*index + 1;
    int right_child = 2*index + 2;
    if (left_child < heap->size && heap->H[left_child]->key < heap->H[smallest]->key)
        smallest = left_child;
    if (right_child < heap->size && heap->H[right_child]->key < heap->H[smallest]->key)
        smallest = right_child;
    if (smallest != index) {
        swap(&heap->H[index], &heap->H[smallest]);
        heapify(heap, smallest);
    }
}

void decreaseKey(HEAP* heap, int position, double newKey) {
    //printf("%lf", heap->H[position]->key);
    if (newKey > heap->H[position]->key) {
        fprintf(stderr, "Error: new key is larger than current key\n");
        return;
    }
    else {
        heap->H[position]->key = newKey;
        while (position > 0 && heap->H[(position - 1) / 2]->key > heap->H[position]->key) {
            swap(&heap->H[position], &heap->H[(position - 1) / 2]);
            position = (position - 1) / 2;
        }
    }
   
}
void   heapInsert(HEAP *heap, double key){
    heap->size++;
    ELEMENT* e = new ELEMENT;
    e->key = std::numeric_limits<double>::max();

    int i = heap->size-1;
    heap->H[i] = e;
    decreaseKey(heap, i, key); 

 
}
double   extractMin(HEAP *heap){
    
    double min_key = heap->H[0]->key;
    heap->H[0] = heap->H[heap->size-1];
    heap->size--;
    heapify(heap, 0);
    return min_key;
}

void printHeap(HEAP *heap){
    fprintf(stdout,"%d\n", heap->size );
    for (int i=0; i<heap->size;i++){
        fprintf(stdout, "%lf\n", heap->H[i]->key);
        
    }
}


void swap(ELEMENT **a, ELEMENT **b){
    ELEMENT *temp = *a;
    *a = *b;
    *b = temp;
}