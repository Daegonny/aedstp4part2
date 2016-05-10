#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "word.h"

//cria lista nova vazia
struct LIST* createList(){
    struct LIST *list = (struct LIST*) malloc(sizeof(struct LIST));
    (*list).words = NULL;
}

//imprime as palavras da lista à medida que a esvazia
void printList(struct LIST *list){
    struct WORD *aux = (*list).words;
    while(aux != NULL){
        printWord(aux);
        aux = (*aux).next;
    }
}

//checa se a lista está vazia
int isEmptyList(struct LIST *list){
    return (*list).words == NULL;
}

//checa se palavra se encontra na lista
struct WORD* isInList(struct WORD *word, struct LIST *list){
    struct WORD *result = NULL;
    if(!isEmptyList(list)){
        struct WORD *aux = (*list).words;
        while(aux != NULL && result == NULL){
            if(compareWord(word, aux) == 0)
                result = aux;
            aux = (*aux).next;
        }
    }
    return result;
}

//insere palavra na lista
void addToList(struct WORD *word, struct LIST *list){
    struct WORD *aux = (*list).words;
    if(isEmptyList(list)){
        (*list).words = word;
    }
    else{
        while((*aux).next != NULL){
            aux = (*aux).next;
        }
        (*aux).next = word;
    }
}

void addInOrderToList(struct WORD *word, struct LIST *list){
    struct WORD *aux = (*list).words;
    if(isEmptyList(list)){
        (*word).next = NULL;
        (*list).words = word;
    }
    else if(compareWord(word, aux) < 0){
        struct WORD *it = aux;
        (*list).words = word;
        (*word).next = it;

    }
    else{
        // struct WORD *it = aux;
        //     printf("%s < %s = %d\n", (*word).string, (*it).string, compareWord(word, it));
        //
        // while((*aux).next != NULL && compareWord(word, (*aux).next) > 0){
        //     printf("entrou aqui \n");
        //     aux = (*aux).next;
        // }

        //(*aux).next = word;
        //printList(list);
    }
}

//remove palavra na lista
void removeFromList(struct LIST *list, struct WORD *word){
    struct WORD *aux = (*list).words;
    struct WORD *it = NULL;
    while((*aux).next != NULL && it == NULL){
        if(compareWord(word, (*aux).next) == 0){
            it = (*aux).next;
        }
        else{
            aux = (*aux).next;
        }
    }
    if(it != NULL){
        (*aux).next = (*it).next;
        free(it);
    }
}
