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
    heap->heapifies = 0;
    for (int i =0;i<capacity;i++){
        heap->H[i] = NULL;
    }
    return heap;

}

void buildMinHeap(HEAP *heap) {
    heap->heapifies=0;
    int n = heap->size;
    for (int i = (n / 2) - 1; i >= 0; i--) {
        heapify(heap, i);
    }
}

void heapify(HEAP *heap, int i){
    if (heap->heapify){
        heap->heapifies++;
    }
    int left = 2*i + 1;
    int right = 2*i + 2;
    int smallest;
    if (left < heap->size && heap->H[left]->key < heap->H[i]->key ){
        smallest = left;
    } else {
        smallest = i;
    }
    if (right < heap->size && heap->H[right]->key < heap->H[smallest]->key  ){
        smallest = right;
    }
    if (smallest != i) {
        swap(&heap->H[i], &heap->H[smallest]);
        heapify(heap, smallest);
    }
}
void decreaseKey(HEAP* heap, int position, double newKey) {
    
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
    heap->heapifies=0;
    double min_key = heap->H[0]->key;
    heap->H[0] = heap->H[heap->size-1];
    heap->size--;
    heapify(heap, 0);
    return min_key;
}

void printHeap(HEAP *heap){
    if (heap->heapify && heap->heapifies > 0){
        fprintf(stdout,"Number of Heapify calls: %d\n", heap->heapifies);
        heap->heapifies = 0;
    }
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