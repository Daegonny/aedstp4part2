#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "word.h"
#include "number.h"
#define SPACE 30 //espaço para imprimir na tela
#define TAMSTRING 50 //tamanho máximo da string

struct WORD* createWord(char string[50], struct NUMBER* line){
    struct WORD *word = (struct WORD*) malloc(sizeof(struct WORD));
    copyString(string, (*word).string);
    (*word).line = line;
    return word;
}

int compareWord(struct WORD *wordOne, struct WORD *wordTwo){
    return strcmp((*wordOne).string, (*wordTwo).string); //0 = igual.
}

void readWordFromFile(FILE *fp, struct LIST *list){
    if(fp == NULL){
        printf("%s\n", "Fail to open file!");
    }
    else{
        char chars[TAMSTRING];
        char c;
        int line = 1;
        int i = 0;
        while ((c = fgetc(fp)) != EOF) {
            if(isValidChar(c)){
                chars[i] = c;
            }
            else{
                chars[i] = '\0';
                if(!isStringEmpty(chars, i)){
                    addToList(createWord(chars, createNumber(line)), list);
                    //pushQueue(createWord(chars, i, line), queue);
                }
                if(c == '\n')
                line++;
                i = -1;
            }
            i++;
        }
    }
}

void printWord(struct WORD *word){
    printf("%s",(*word).string );
    //escrever as linhas também
}
// códigos ascii para números e letras maiúsculas/minúsculas
int isValidChar(char c){
    return
        (c >= 48 && c <= 57) ||
        (c >= 65 && c <= 90) ||
        (c >= 97 && c <= 122);
}

int isStringEmpty(char *string, int length){
    int flag = 1;
    if(length > 0){
        int i;
        for(i = 0; i < length; i++){
            if(string[i] != ' ')
                flag = 0;
        }
    }
    return flag;
}

void copyString(char from[], char to[]){
    int i = 0;
    while ((to[i] = from[i]) != '\0') {
        i++;
    }
}
