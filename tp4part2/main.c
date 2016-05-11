#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "number.h"
#include "word.h"
#include "list.h"

int main(int argc, char const *argv[]) {

    struct LIST* blackList = createList();
    struct LIST* index = createList();

    FILE *fp;
    char blPath[] = "blackList.txt";
    char ixPath[] = "plato.txt";
    char otPath[] = "out.txt";

    fp = fopen(blPath, "r+");
    printf("Carregando dicionario negativo...\n");
    buildBlackList(fp, blackList);
    //printList(blackList);
    fclose(fp);

    fp = fopen(ixPath, "r+");
    printf("Construindo indice remissivo...\n");
    buildIndex(fp, index, blackList);
    //printList(index);
    fclose(fp);

    fp = fopen(otPath, "w+");
    printf("Salvando indice em arquivo...\n");
    printListInFile(index, fp);
    fclose(fp);

    printf("Operacao Concluida!\n");

    return 0;
}
