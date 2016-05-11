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
    (*word).next = NULL;
    return word;
}

int compareWord(struct WORD *wordOne, struct WORD *wordTwo){
    return strcasecmp((*wordOne).string, (*wordTwo).string); //0 = igual.
}

void buildBlackList(FILE *fp, struct LIST *blackList){
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
                    struct WORD *currentWord = createWord(chars, createNumber(line));
                    addToList(currentWord, blackList);
                }
                if(c == '\n')
                line++;
                i = -1;
            }
            i++;
        }
    }
}

void buildIndex(FILE *fp, struct LIST *index, struct LIST *blackList){
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
                    struct WORD *currentWord = createWord(chars, createNumber(line));
                    if(isInList(currentWord, blackList) == NULL){//se não está presente na lista negra
                        struct WORD *wordInIndex = isInList(currentWord, index);
                        if(wordInIndex != NULL){//se já está na lista, adicione linha
                            addNumber((*wordInIndex).line, (*currentWord).line);
                        }
                        else{
                            //addToList(currentWord, index);
                            addInOrderToList(currentWord, index);
                        }
                    }
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
    if(word != NULL){
        printf("%s: ",(*word).string);
    }
    printNumber((*word).line);
    printf("\n");
}

void printWordInFile(struct WORD *word, FILE* fp){
    if (fp != NULL) {
        if(word != NULL){
            fprintf(fp, "%s: ",(*word).string);
        }
        printNumberInFile((*word).line, fp);
        fprintf(fp, "\n");
    }
    else{
        printf("Falha ao escrever em arquivo!\n");
    }
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
