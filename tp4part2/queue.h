#ifndef _QUEUE_H
#define _QUEUE_H

typedef struct QUEUE //estrutura fila
{
    struct WORD *first; //primeiro da fila
    struct WORD *last; //último da fila
    struct WORD *words; //ponteiro de palavras
}QUEUE;

//cria fila nova vazia
struct QUEUE* createQueue();

//imprime as palavras da fila à medida que a desenfileira
void printQueue(struct QUEUE *queue);

//checa se a fila está fazia
int isEmptyQueue(struct QUEUE *queue);

//enfileira palavra na fila
void pushQueue(struct WORD *word, struct QUEUE *queue);

//desenfileira palavra na fila
void popQueue(struct QUEUE *queue);

#endif
