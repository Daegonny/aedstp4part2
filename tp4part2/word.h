#ifndef _WORD_H
#define _WORD_H
#include "list.h"
#include "number.h"
#define TAMSTRING 50 //tamanho máximo da string

typedef struct WORD //estrutura palavra
{
    char string[TAMSTRING]; //cadeia de caracteres da palavra
    struct NUMBER* line; //linhas em que a palavra ocorre
    struct WORD* next; //proxima palavra
}WORD;

//cria nova palavra
struct WORD* createWord(char string[TAMSTRING], struct NUMBER* line);

//compara duas palavras
int compareWord(struct WORD *wordOne, struct WORD *wordTwo);

//lê palavras num arquivo e adiciona em uma lista
void readWordFromFile(FILE *fp, struct LIST *list);

//imprime uma palavra e sua posição na tela
void printWord(struct WORD *word);

//checa se um caractere é valido
int isValidChar(char c);

//checa se uma string está vazia
int isStringEmpty(char *string, int length);

//copia uma string
void copyString(char *from, char *to);

#endif
