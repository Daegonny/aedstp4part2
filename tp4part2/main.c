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
    char ixPath[] = "kant.txt";

    fp = fopen(blPath, "r+");
    buildBlackList(fp, blackList);
    //printList(blackList);
    fclose(fp);

    fp = fopen(ixPath, "r+");
    buildIndex(fp, index, blackList);
    printList(index);
    fclose(fp);
    return 0;
}
