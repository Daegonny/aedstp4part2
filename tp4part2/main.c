#include <stdio.h>
#include <stdlib.h>
#include "number.h"
#include "word.h"
#include "list.h"

int main(int argc, char const *argv[]) {

    struct LIST* blackList = createList();

    FILE *fp;
    char path[] = "blackList.txt";
    fp = fopen(path, "r+"); //abre o arquivo de texto

    buildBlackList(fp, blackList);
    //printList(blackList);

    //printWord(isInList(createWord("pipoca", NULL), blackList));

    fclose(fp); //fecha arquivo
    return 0;
}
