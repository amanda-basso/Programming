#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int info;
    struct node *right;
    struct node *left;
}node;

int tree_height(node *T){
    if (T == NULL)
        return 0;
    else {
        int Hl = tree_height(T->left);
        int Hr = tree_height(T->right);
        if (Hl > Hr)
            return 1 + Hl;
        else return 1 + Hr;
    }
}

int is_balanced(node *T){
    if (T == NULL)
        return 1;
    else {
        int Hl = tree_height(T->left);
        int Hr = tree_height(T->right);
        if ((Hl - Hr) > 1 || (Hr - Hl) > 1)
            return 0;
        else{
            if (is_balanced(T->left) && is_balanced(T->right))
                return 1;
            else return 0;
        }
    }
}

int main()
{
    node A, B, C, D, E, F, G;
    A.info = 0;
    A.left = A.right = NULL;
    B.info = 2;
    B.left = B.right = NULL;
    /*C.info = 4;
    C.left = C.right = NULL;
    D.info = 6;
    D.left = D.right = NULL;*/
    E.info = 1;
    E.left = &A;
    E.right = &B;
    /*F.info = 5;
    F.left = NULL;
    F.right = NULL;*/
    G.info = 3;
    G.left = &E;
    G.right = NULL;

    if (is_balanced(&G))
        printf("The tree is balanced");
    else printf("The tree is not balanced");

    return 0;
}

