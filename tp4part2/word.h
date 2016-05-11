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

//constroi lista negra
void buildBlackList(FILE *fp, struct LIST *blackList);

//constori índice
void buildIndex(FILE *fp, struct LIST *index, struct LIST *blackList);

//imprime uma palavra e sua posição na tela
void printWord(struct WORD *word);

void printWordInFile(struct WORD *word, FILE* fp);

//checa se um caractere é valido
int isValidChar(char c);

//checa se uma string está vazia
int isStringEmpty(char *string, int length);

//copia uma string
void copyString(char *from, char *to);

#endif
