#include <stdio.h>
#include <string.h>
#include "util.h"
//next instruction checks whether command is valid. could maybe have a better name
int nextInstruction(char *Word, double *key)
{
    int  returnV;


    if (strcmp(Word, "Stop")==0) return 1;
    if (strcmp(Word, "Print")==0) return 1;
    if (strcmp(Word, "Write")==0) return 1;
    if (strcmp(Word, "Read")==0) return 1;

    if (strcmp(Word, "Insert")==0){
        returnV = fscanf(stdin, "%lf", key);
        if (returnV == 1){
            return 1;
        }else{
            return 0;
        }
    }

    if (strcmp(Word, "Init")==0){
    returnV = fscanf(stdin, "%lf", key);
    if (returnV == 1){
        return 1;
    }else{
        return 0;
    }

}

    return 0;
}


int nextInstruction(char *Word, int *position, double *key)
{
    int returnV;
    if (strcmp(Word, "DecreaseKey")==0){//TODO
        returnV = fscanf(stdin, "%d %lf", position, key);
        if (returnV == 0){
            return 0;
        }
        returnV = fscanf(stdin, "%lf", key);
        if (returnV == 1){
            return 1;
        }else{
            return 0;
        }
    }
    return 0;
}

