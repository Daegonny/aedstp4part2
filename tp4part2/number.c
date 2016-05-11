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
    if(number != NULL){
        printf("%d", (*number).value);
        number = (*number).next;
        while (number != NULL) {
            printf(", %d", (*number).value);
            number = (*number).next;
        }
    }
}

void printNumberInFile(struct NUMBER* number, FILE* fp){
    if(fp != NULL){
        if(number != NULL){
            fprintf(fp, "%d", (*number).value);
            number = (*number).next;
            while (number != NULL) {
                fprintf(fp, ", %d", (*number).value);
                number = (*number).next;
            }
        }
    }
    else{
        printf("Falha ao escrever em arquivo!\n");
    }
}

void addNumber(struct NUMBER* number, struct NUMBER* next){
    while ((*number).next != NULL ){
        number = (*number).next;
    }
    (*number).next = next;
}
