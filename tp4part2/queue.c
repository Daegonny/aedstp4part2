#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "word.h"

struct QUEUE* createQueue(){
    struct QUEUE *queue = (struct QUEUE*) malloc(sizeof(struct QUEUE));
    (*queue).last = NULL;
    (*queue).first = NULL;
    (*queue).words = NULL;
    return queue;
}

void printQueue(struct QUEUE *queue){
    if(!isEmptyQueue(queue)){
        while(!isEmptyQueue(queue)){
            //printWord((*queue).words[(*queue).first]);
            //popQueue(queue);
        }
    }
}

int isEmptyQueue(struct QUEUE *queue){
    return (*queue).first == (*queue).last;
}

void pushQueue(struct WORD *word, struct QUEUE *queue){
    //(*queue).words[(*queue).last] = word;
    //(*queue).last = (*queue).last + 1;
}

void popQueue(struct QUEUE *queue){
    if(!isEmptyQueue(queue)){
        int i;

        //for(i = 0; i < ((*queue).last -1); i++){
        //    (*queue).words[i] = (*queue).words[i+1];
        //}
        //(*queue).last = (*queue).last - 1;
    }
}
