#include <stdlib.h>
#include <stdio.h>
#include "number.h"

struct NUMBER* createNumber(int value){
    struct NUMBER *number = (struct NUMBER*) malloc(sizeof(struct NUMBER));
    (*number).value = value;
    (*number).next = NULL;
    return number;
}

void printNumber(struct NUMBER* number){
    while (number != NULL) {
        printf("%d ", (*number).value);
    }
}
