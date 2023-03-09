#include <stdio.h>
#include <stdlib.h>
#include "TreeBinAvl.h"

Node* TreeInitit(){
    return NULL;
}

void FreeTree(Node *root){
    if(root != NULL){
        FreeTree(root->left);
        FreeTree(root->right);
        free(root);
    }
}

Node* NewNode(int value){
    Node *node = malloc(sizeof(Node));
    node->info = value;
    node->left = NULL;
    node->right = NULL;
    node->height = 0;
    return node;
}

Node* InsertNode(Node *root, int value){
    if(root == NULL){
        return NewNode(value);
    }else{
        if(value > root->info)
            root->right = InsertNode(root->right, value);
        else if(value < root->info)
            root->left = InsertNode(root->left, value);
    }
    root->height = GreaterHeight(GetHeight(root->left), GetHeight(root->right)) + 1;
    root = Balance(root);
    return root;
}

Node* RemoveNode(Node *root, int value){
    if(root == NULL){
        return;
    }else{
        if(value > root->info)
            root->right = RemoveNode(root->right, value);
        else if(value < root->info)
            root->left = RemoveNode(root->left, value);
        else{
            if(root->left == NULL && root->right == NULL){
                printf("Esse valor: %d, estamos atras de: %d\n", root->info, value);
                free(root);
                return NULL;
            }
            else if(root->left != NULL && root->right == NULL){
                Node *node = malloc(sizeof(Node));
                node = root->left;
                free(root);
                return node;
            }
            else if(root->left == NULL && root->right != NULL){
                Node *node = malloc(sizeof(Node));
                node = root->right;
                free(root);
                return node;
            }
            else if(root->left != NULL && root->right != NULL){
                Node *maxDir = malloc(sizeof(Node));
                maxDir = root->left;
                while(maxDir->right != NULL)
                    maxDir = maxDir->right;

                int aux = maxDir->info;
                root = RemoveNode(root, aux);
                root->info = aux;
                return root;
            }
        }
        root->height = GreaterHeight(GetHeight(root->left), GetHeight(root->right)) + 1;
        root = Balance(root);
        return root;
    }
}

void Path(Node* root, int start, int finish){
    if(root != NULL){
        if(finish == root->info)
            printf("%d", root->info);
        else{
            if(start > root->info)
                Path(root->right, start, finish);
            else if(start < root->info)
                Path(root->left, start, finish);
            else{
                printf("%d ", root->info);
                if(finish > root->info)
                    Path(root->right, root->right->info, finish);
                else
                    Path(root->left, root->left->info, finish);
            }
        }
    }
}

int GetHeight(Node *node){
    if(node == NULL)
        return -1;
    return node->height;
}

int MaxHeight(Node *root){
    if(root == NULL)
        return 0;
    int hleft = 0, hright = 0;
    if(root->left != NULL)
        hleft = MaxHeight(root->left);
    if(root->right != NULL)
        hright = MaxHeight(root->right);
    if(hleft > hright)
        return hleft + 1;
    return hright + 1;
}

int GreaterHeight(int a, int b){
    return (a > b)? a: b;
}

int BalancingFactor(Node *node){
    if(node != NULL)
        return (GetHeight(node->left) - GetHeight(node->right));
    return 0;
}

Node* TurnLeft(Node *node){
    Node *nodeAux1, *nodeAux2;

    nodeAux1 = node->right;
    nodeAux2 = node->left;
    nodeAux1->left = node;
    node->right = nodeAux2;

    node->height = GreaterHeight(GetHeight(node->left), GetHeight(node->left)) + 1;
    nodeAux1->height = GreaterHeight(GetHeight(nodeAux1->left), GetHeight(nodeAux1->right)) + 1;
    return nodeAux1;
}

Node* TurnRight(Node *node){
    Node *nodeAux1, *nodeAux2;

    nodeAux1 = node->left;
    nodeAux2 = node->right;
    nodeAux1->right = node;
    node->left = nodeAux2;

    node->height = GreaterHeight(GetHeight(node->left), GetHeight(node->left)) + 1;
    nodeAux1->height = GreaterHeight(GetHeight(nodeAux1->left), GetHeight(nodeAux1->right)) + 1;
    return nodeAux1;
}

Node* TurnLeftRight(Node *node){
    node->left = TurnLeft(node->left);
    return TurnRight(node);
}

Node* TurnRightLeft(Node *node){
    node->right = TurnRight(node->right);
    return TurnLeft(node);
}

Node* Balance(Node *root){
    int fb = BalancingFactor(root);

    if(fb < -1 && BalancingFactor(root->right) <= 0)
        root = TurnLeft(root);
    else if(fb > 1 && BalancingFactor(root->left) >= 0)
        root = TurnRight(root);
    else if(fb > 1 && BalancingFactor(root->left) < 0)
        root = TurnLeftRight(root);
    else if(fb < -1 && BalancingFactor(root->right) > 0)
        root = TurnRightLeft(root);

    return root;
}

void PreOrder(Node *root){
    if(root != NULL){
        printf("%d\n", root->info);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void PosOrder(Node *root){
    if(root != NULL){
        PosOrder(root->left);
        PosOrder(root->right);
        printf("%d\n", root->info);
    }
}
