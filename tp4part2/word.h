#ifndef _WORD_H
#define _WORD_H
#include "queue.h"
#define TAMSTRING 50 //tamanho máximo da string

typedef struct WORD //estrutura palavra
{
    char string[TAMSTRING]; //cadeia de caracteres da palavra
    int length; //comprimento
    int line; //linha do texto que a palavra se encontra
}WORD;

//cria nova palavra
struct WORD createWord(char string[TAMSTRING], int length, int line);

//lê palavras num arquivo e as enfileira numa fila
void readWordFromFile(FILE *fp, struct QUEUE *queue);

//imprime uma palavra e sua posição na tela
void printWord(struct WORD *word);

//checa se um caractere é valido
int isValidChar(char c);

//checa se uma string está vazia
int isStringEmpty(char *string, int length);

//copia uma string
void copyString(char *from, char *to);

#endif
