#ifndef TREEBINAVL_H_INCLUDED
#define TREEBINAVL_H_INCLUDED

struct nodeavl{
    int info;
    int height;
    struct nodeavl *left;
    struct nodeavl *right;
};

typedef struct nodeavl NodeAvl;

NodeAvl* TreeInititAvl();
NodeAvl* NewNode(int);
NodeAvl* InsertNodeAvl(NodeAvl*, int);
NodeAvl* RemoveNodeAvl(NodeAvl*, int);
NodeAvl* FindNodeAvl(NodeAvl*, int);
NodeAvl* TurnLeft(NodeAvl*);
NodeAvl* TurnRight(NodeAvl*);
NodeAvl* TurnLeftRight(NodeAvl*);
NodeAvl* TurnRightLeft(NodeAvl*);
NodeAvl* Balance(NodeAvl*);
void FreeTreeAvl(NodeAvl*);
void PathAvl(NodeAvl*, int, int);
void PreOrderAvl(NodeAvl*);
void PreOrderFbAvl(NodeAvl*);
void PosOrderAvl(NodeAvl*);
int FindValueAvl(NodeAvl*, int);
int MaxHeightAvl(NodeAvl*);
int GetHeight(NodeAvl*);
int GreaterHeight(int, int);
int BalancingFactor(NodeAvl*);

#endif // TREEBINAVL_H_INCLUDED
