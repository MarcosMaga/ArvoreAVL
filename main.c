#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "TreeBinAvl.h"

int main()
{
    srand(time(NULL));
    int num;

    NodeAvl *ab = TreeInititAvl();
    ab = InsertNodeAvl(ab, 12);
    ab = InsertNodeAvl(ab, 4);
    ab = InsertNodeAvl(ab, 2);
    //ab = InsertNode(ab, 8);
    //ab = InsertNode(ab, 6);
    //ab = InsertNode(ab, 16);
    //ab = InsertNode(ab, 19);
    //MaxDir(ab);
    PreOrderAvl(ab);
    //printf("\n\n");
    //PosOrder(ab);
    //Path(ab, 12, 6);
    //int a = Height(ab);
    //printf("\nAltura: %d", a);
    //printf("\nBanana");
}
