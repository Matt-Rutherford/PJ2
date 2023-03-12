#include <stdio.h>
#include <string.h>
#include <iostream>
#include "util.h"
#include "heap.h"
#include "data_structures.h"

HEAP* init(HEAP *heap, int capacity){//init not correct
    heap = new HEAP;
    ELEMENT *h [capacity];
    for (int i = 0; i < capacity;i++){
        ELEMENT *e = new ELEMENT;
        h[i] = e;
        h[i]->key = 0;
    }
    for (int i = 0; i < capacity;i++){
        printf("%lf", heap->H[i]->key);
    }
    heap->H = h;
    heap->capacity = capacity;
    heap->size = 0;
    return heap;

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
void   heapInsert(HEAP *heap, double key){
    if (heap->size == heap->capacity) {
        fprintf(stderr, "Error: heap is full\n");
        return;
    }
    
    //element->key = key;
    heap->H[heap->size]->key = key;
    int i = heap->size;
    while (i > 0 && heap->H[(i-1)/2]->key > heap->H[i]->key) {
        swap(&heap->H[i], &heap->H[(i-1)/2]);
        i = (i-1)/2;
    }
    heap->size++;
}
double   extractMin(HEAP *heap){
    if (heap->size == 0) {
        fprintf(stderr, "Error: heap is empty\n");
        return -1;
    }
    double min_key = heap->H[0]->key;
    heap->H[0] = heap->H[heap->size-1];
    heap->size--;
    heapify(heap, 0);
    return min_key;
}

void printHeap(HEAP *heap){
    fprintf(stdout,"%d", heap->size );
    for (int i=0; i<heap->size;i++){
        fprintf(stdout, "%lf\n", heap->H[i]->key);
        
    }
}
void decreaseKey(HEAP *heap, int position, double newKey){
    if (newKey > heap->H[position]->key) {
        fprintf(stderr, "Error: new key is larger than current key\n");
        return;
    }
    heap->H[position]->key = newKey;
    while (position > 0 && heap->H[(position-1)/2]->key > heap->H[position]->key) {
        swap(&heap->H[position], &heap->H[(position-1)/2]);
        position = (position-1)/2;
    }

    
}

void swap(ELEMENT **a, ELEMENT **b){
    ELEMENT *temp = *a;
    *a = *b;
    *b = temp;
}