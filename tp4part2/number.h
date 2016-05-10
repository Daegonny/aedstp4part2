#ifndef _NUMBER_H
#define _NUMBER_H

typedef struct NUMBER //número de linha
{
    int value;
    struct NUMBER *next; //próximo
}NUMBER;
//cria fila nova vazia
struct NUMBER* createNumber(int value);

//imprime os números
void printNumber(struct NUMBER* number);

void addNumber(struct NUMBER* number, struct NUMBER* next);

#endif
