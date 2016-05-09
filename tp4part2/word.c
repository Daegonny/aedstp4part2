#include <stdio.h>
#include "word.h"
#include "queue.h"
#define SPACE 30 //espaço para imprimir na tela
#define TAMSTRING 50 //tamanho máximo da string

struct WORD createWord(char string[50], int length, int line){
    struct WORD word;
    copyString(string, word.string);
    word.length = length;
    word.line = line;
    return word;
}

void readWordFromFile(FILE *fp, struct QUEUE *queue){
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

void printWord(struct WORD word){
    int i = 0;
    //printf("%s",word.string );
    //for(i = (SPACE - word.length); i > 0; i--){
    //    printf(" ");
    //}
    //printf("%d\n", word.line);
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
