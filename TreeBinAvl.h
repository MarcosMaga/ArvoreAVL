#ifndef TREEBINAVL_H_INCLUDED
#define TREEBINAVL_H_INCLUDED

struct node{
    int info;
    int height;
    struct node *left;
    struct node *right;
};

typedef struct node Node;

Node* TreeInitit();
Node* NewNode(int);
Node* InsertNode(Node*, int);
Node* RemoveNode(Node*, int);
Node* MaxDir(Node*);
Node* TurnLeft(Node*);
Node* TurnRight(Node*);
Node* TurnLeftRight(Node*);
Node* TurnRightLeft(Node*);
Node* Balance(Node*);
void FreeTree(Node*);
void Path(Node*, int, int);
void PreOrder(Node*);
void PosOrder(Node*);
int MaxHeight(Node*);
int GetHeight(Node*);
int GreaterHeight(int, int);
int BalancingFactor(Node*);

#endif // TREEBINAVL_H_INCLUDED
