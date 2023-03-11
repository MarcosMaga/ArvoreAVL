#include <stdio.h>
#include <stdlib.h>
#include "TreeBinAvl.h"

NodeAvl* TreeInititAvl(){
    return NULL;
}

void FreeTreeAvl(NodeAvl *root){
    if(root != NULL){
        FreeTreeAvl(root->left);
        FreeTreeAvl(root->right);
        free(root);
    }
}

NodeAvl* NewNode(int value){
    NodeAvl *node = malloc(sizeof(NodeAvl));
    node->info = value;
    node->left = NULL;
    node->right = NULL;
    node->height = 0;
    return node;
}

NodeAvl* InsertNodeAvl(NodeAvl *root, int value){
    if(root == NULL){
        return NewNode(value);
    }else{
        if(value > root->info)
            root->right = InsertNodeAvl(root->right, value);
        else if(value < root->info)
            root->left = InsertNodeAvl(root->left, value);
    }
    root->height = GreaterHeight(GetHeight(root->left), GetHeight(root->right)) + 1;
    root = Balance(root);
    return root;
}

NodeAvl* RemoveNodeAvl(NodeAvl *root, int value){
    if(root == NULL){
        return;
    }else{
        if(value > root->info)
            root->right = RemoveNodeAvl(root->right, value);
        else if(value < root->info)
            root->left = RemoveNodeAvl(root->left, value);
        else{
            if(root->left == NULL && root->right == NULL){
                printf("Esse valor: %d, estamos atras de: %d\n", root->info, value);
                free(root);
                return NULL;
            }
            else if(root->left != NULL && root->right == NULL){
                NodeAvl *node = malloc(sizeof(NodeAvl));
                node = root->left;
                free(root);
                return node;
            }
            else if(root->left == NULL && root->right != NULL){
                NodeAvl *node = malloc(sizeof(NodeAvl));
                node = root->right;
                free(root);
                return node;
            }
            else if(root->left != NULL && root->right != NULL){
                NodeAvl *maxDir = malloc(sizeof(NodeAvl));
                maxDir = root->left;
                while(maxDir->right != NULL)
                    maxDir = maxDir->right;

                int aux = maxDir->info;
                root = RemoveNodeAvl(root, aux);
                root->info = aux;
                return root;
            }
        }
        root->height = GreaterHeight(GetHeight(root->left), GetHeight(root->right)) + 1;
        root = Balance(root);
        return root;
    }
}

void PathAvl(NodeAvl* root, int start, int finish){
    if(root != NULL){
        if(finish == root->info)
            printf("%d", root->info);
        else{
            if(start > root->info)
                PathAvl(root->right, start, finish);
            else if(start < root->info)
                PathAvl(root->left, start, finish);
            else{
                printf("%d ", root->info);
                if(finish > root->info)
                    PathAvl(root->right, root->right->info, finish);
                else
                    PathAvl(root->left, root->left->info, finish);
            }
        }
    }
}

int GetHeight(NodeAvl *node){
    if(node == NULL)
        return -1;
    return node->height;
}

int MaxHeightAvl(NodeAvl *root){
    if(root == NULL)
        return 0;
    int hleft = 0, hright = 0;
    if(root->left != NULL)
        hleft = MaxHeightAvl(root->left);
    if(root->right != NULL)
        hright = MaxHeightAvl(root->right);
    if(hleft > hright)
        return hleft + 1;
    return hright + 1;
}

int GreaterHeight(int a, int b){
    return (a > b)? a: b;
}

int BalancingFactor(NodeAvl *node){
    if(node != NULL)
        return (GetHeight(node->left) - GetHeight(node->right));
    return 0;
}

NodeAvl* TurnLeft(NodeAvl *node){
    NodeAvl *nodeAux1, *nodeAux2;

    nodeAux1 = node->right;
    nodeAux2 = node->left;
    nodeAux1->left = node;
    node->right = nodeAux2;

    node->height = GreaterHeight(GetHeight(node->left), GetHeight(node->left)) + 1;
    nodeAux1->height = GreaterHeight(GetHeight(nodeAux1->left), GetHeight(nodeAux1->right)) + 1;
    return nodeAux1;
}

NodeAvl* TurnRight(NodeAvl *node){
    NodeAvl *nodeAux1, *nodeAux2;

    nodeAux1 = node->left;
    nodeAux2 = node->right;
    nodeAux1->right = node;
    node->left = nodeAux2;

    node->height = GreaterHeight(GetHeight(node->left), GetHeight(node->left)) + 1;
    nodeAux1->height = GreaterHeight(GetHeight(nodeAux1->left), GetHeight(nodeAux1->right)) + 1;
    return nodeAux1;
}

NodeAvl* TurnLeftRight(NodeAvl *node){
    node->left = TurnLeft(node->left);
    return TurnRight(node);
}

NodeAvl* TurnRightLeft(NodeAvl *node){
    node->right = TurnRight(node->right);
    return TurnLeft(node);
}

NodeAvl* Balance(NodeAvl *root){
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

void PreOrderAvl(NodeAvl *root){
    if(root != NULL){
        printf("%d\n", root->info);
        PreOrderAvl(root->left);
        PreOrderAvl(root->right);
    }
}

void PreOrderFbAvl(NodeAvl *root){
    if(root != NULL){
        printf("%d - FB:%d\n", root->info, BalancingFactor(root));
        PreOrderFbAvl(root->left);
        PreOrderFbAvl(root->right);
    }
}

void PosOrderAvl(NodeAvl *root){
    if(root != NULL){
        PosOrderAvl(root->left);
        PosOrderAvl(root->right);
        printf("%d\n", root->info);
    }
}
