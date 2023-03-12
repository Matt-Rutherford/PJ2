#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"
#include "heap.h"

int main(int argc, char **argv){
    
    HEAP *heap;
    
    FILE *fp;
    int capacity, size, n, position;

    double key;
    int returnV;
    char Word[100];

    if (argc < 4){
        fprintf(stderr, "Usage: %s <ifile> <ofile> Flag\n", argv[0]);
        exit(0);
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
            heap = init(heap, capacity);
            
            if (!heap){
                fprintf(stderr, "Error: calloc failed\n");
                exit(0);
            }
            
        }

        if (strcmp(Word, "Stop")==0){
            return 0;
        }

        if (strcmp(Word, "Print")==0){
            if (heap == NULL){
                fprintf(stderr, "Warning: Heap is NULL\n");
                continue;
            }
            printHeap(heap);
            fprintf(stdout, "\n");
            continue;
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
                fscanf(fp, "%d", &n);
                for (int i = 0; i<n;i++){
                    returnV = fscanf(fp, "%lf", &heap->H[i]->key);
                    heap->size++;
                }
             
                fclose(fp);
            } else {
                fprintf(stderr, "Error: heap is NULL\n");
            }
            continue;
        }



        if (strcmp(Word, "Insert")==0){
            heapInsert(heap, key);
            continue;
        }

    }

    return 1;
}
