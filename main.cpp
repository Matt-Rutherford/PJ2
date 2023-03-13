#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"
#include "heap.h"
#include <limits>
//Matthew Rutherford 1227041896
int main(int argc, char **argv){
    
    HEAP* heap = NULL;
    
    FILE *fp;
    int capacity, n, position;

    double key;
    int returnV;
    char Word[100];
    bool flag = 0;
    
    if (argc < 4){
        fprintf(stderr, "Usage: %s <ifile> <ofile> Flag\n", argv[0]);
        exit(0);
    }
    if (strcmp(argv[3], "1")==0) {
        flag = 1;
    }
    
    while (1){
        returnV = fscanf(stdin, "%s", Word);
        
        if (strcmp(Word, "DecreaseKey")==0){
            returnV = nextInstruction(Word, &position, &key);
        } else {           
            returnV = nextInstruction(Word, &key);
        }
        

        if (returnV == 0){
            fprintf(stderr, "Warning: Invalid instruction\n");
            continue;
        }

        if(strcmp(Word, "Init")==0){
            
            capacity = key;
            heap = new HEAP;
            if (!heap) {
                fprintf(stderr, "Error: calloc failed\n");
                exit(0);
            }
            heap = init(heap, capacity);
            
            
            
        }

        if (strcmp(Word, "Stop")==0){
            return 0;
        }

        if (strcmp(Word, "Print")==0){
            if (heap == NULL){
                fprintf(stderr, "Warning: Heap is NULL\n");
                continue;
            }
            else {
                printHeap(heap);
                fprintf(stdout, "\n");
                continue;
            }
           
        }

        if (strcmp(Word, "Write")==0){

            if (heap != NULL){
                fp = fopen(argv[2], "w");
                if (!fp){
                    fprintf(stderr, "Error: cannot open file %s\n", argv[2]);
                    exit(0);
                }
                fprintf(fp, "%d", heap->size);
                for (int i =0;i<heap->size;i++){
                    fprintf(fp, "%lf\n", heap->H[i]->key);
                }
                
                fclose(fp);
            } else {
                fprintf(stderr, "Error: heap is NULL\n");
            }
            continue;
        }


        if (strcmp(Word, "Read")==0){
            
            if (heap != NULL){
                fp = fopen(argv[1], "r");
                if (!fp){
                    fprintf(stderr, "Error: cannot open file %s\n", argv[1]);
                    exit(0);
                }
                returnV = fscanf(fp, "%d", &n);
                
                if (heap->capacity < (heap->size + n)) {
                    fprintf(stderr, "Error: size of input is larger than capacity %s\n", argv[1]);
                    fclose(fp);
                    exit(0);
                }
                
                double newKey = 0;
                for (int i = 0, j = heap->size; i<n;i++,j++){
                    ELEMENT *e = new ELEMENT;
                    returnV = fscanf(fp, "%lf", &e->key);
                    heap->H[i] = e;
                }
                
                heap->size += n;
                buildMinHeap(heap);
                
                fclose(fp);
            } else {
                fprintf(stderr, "Error: heap is NULL\n");
            }
            continue;
        }



        if (strcmp(Word, "Insert")==0){
            if (heap == NULL) {
                fprintf(stderr, "Error: heap is NULL\n");
                continue;
            }
            else if (heap->size == heap->capacity) {
                fprintf(stderr, "Error: heap is full\n");
                continue;
            }
            else {
                heapInsert(heap, key);
            }
            continue;
        }
        if (strcmp(Word, "ExtractMin") == 0) {
            if (heap == NULL) {
                fprintf(stderr, "Error: heap is NULL\n");
                continue;
            }
            else if (heap->size == 0) {
                fprintf(stderr, "Error: heap is empty\n");
                continue;
            }
            else {
                double Key = extractMin(heap);
                fprintf(stdout, "ExtractMin: %lf\n", Key);
            }
        }

    }

    return 1;
}
