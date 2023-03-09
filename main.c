#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "TreeBin.h"

int main()
{
    srand(time(NULL));
    int num;

    Node *ab = TreeInitit();
    ab = InsertNode(ab, 12);
    ab = InsertNode(ab, 4);
    ab = InsertNode(ab, 2);
    //ab = InsertNode(ab, 8);
    //ab = InsertNode(ab, 6);
    //ab = InsertNode(ab, 16);
    //ab = InsertNode(ab, 19);
    //MaxDir(ab);
    PreOrder(ab);
    //printf("\n\n");
    //PosOrder(ab);
    //Path(ab, 12, 6);
    //int a = Height(ab);
    //printf("\nAltura: %d", a);
    //printf("\nBanana");
}
