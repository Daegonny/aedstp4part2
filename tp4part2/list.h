#ifndef _LIST_H
#define _LIST_H

typedef struct LIST //estrutura lista
{
    struct WORD* words;
}LIST;

//cria lista nova vazia
struct LIST* createList();

//imprime as palavras da lista à medida que a esvazia
void printList(struct LIST *list);

//checa se a lista está vazia
int isEmptyList(struct LIST *list);

//checa se palavra se encontra na lista e a retorna em caso positivo
struct WORD* isInList(struct WORD *word, struct LIST *list);

//insere palavra na lista
void addToList(struct WORD *word, struct LIST *list);

//insere palavra em ordem alfabética na lista
void addInOrderToList(struct WORD *word, struct LIST *list);

//remove palavra na lista
void removeFromList(struct LIST *list, struct WORD *word);

#endif
