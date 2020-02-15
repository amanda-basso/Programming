#include<stdio.h>

typedef struct node{
    int info;
    int balancing;
    struct node *right;
    struct node *left;
}node;

int tree_height(node *T){
    if (T == NULL)
        return 0;
    else {
        int Hleft = tree_height(T->left);
        int Hright = tree_height(T->right);

        if (Hleft > Hright)
            return 1 + Hleft;
        else return 1 + Hright;
    }
}

int is_balanced(node *T){
    if (T == NULL)
        return 1;
    else {
        int Hleft = tree_height(T->left);
        int Hright = tree_height(T->right);

        if ((Hleft - Hright) > 1 || (Hright - Hleft) > 1)
            return 0;
        else {
            if (is_balanced(T->left) && is_balanced(T->right))
                return 1;
            else return 0;
        }
    }
}

int rotation_left_left(node *T, int changed_height){
    node *child;

    child = T->left;
    T->left = child->right;
    child->right = T;
    T->balancing = child->balancing = 0;
    changed_height = 0;
    T = child;
}

int rotation_right_right(node *T, int changed_height){
    node *child;

    child = T->right;
    T->right = child->left;
    child->left = T;
    T->balancing = child->balancing = 0;
    changed_height = 0;
    T = child;
}

int rotation_left_right(node *T, int changed_height){
    node *child, *grandchild;

    child = T->left;
    grandchild = child->right;
    T->left = grandchild->right;
    child->right = grandchild->left;
    grandchild->right = T;
    grandchild->left = child;
    if (grandchild->balancing == 1){
        T->balancing = -1;
        grandchild->balancing = child->balancing = 0;
    } else if (grandchild->balancing == -1){
        child->balancing = 1;
        grandchild->balancing = T->balancing = 0;
    } else if (grandchild->balancing == 0){
        grandchild->balancing = child->balancing = T->balancing = 0;
    }
    T = grandchild;
    changed_height = 0;
}

int rotation_right_left(node *T, int changed_height){
    node *child, *grandchild;

    child = T->right;
    grandchild = child->left;
    T->right = grandchild->left;
    child->left = grandchild->right;
    grandchild->left = T;
    grandchild->right = child;
    if (grandchild->balancing == 1){
        child->balancing = -1;
        grandchild->balancing = T->balancing = 0;
    } else if (grandchild->balancing == -1){
        T->balancing = 1;
        grandchild->balancing = child->balancing = 0;
    } else if (grandchild->balancing == 0){
        grandchild->balancing = child->balancing = T->balancing = 0;
    }
    T = grandchild;
    changed_height = 0;
}

void insert(node *T, int value, int ok, int changed_height){
    node *R, *child, *grandchild;

    if (T == NULL){
        R->info = value;
        ok = changed_height = 1;
        R->balancing = 0;
        R->right = R->left = NULL;
        T = R;
        R = NULL;
    }
    else {
        if (value == T->info)
            ok = changed_height = 0;
        else if (T->info > value){
            insert(T->left, value, ok, changed_height);
            if (changed_height){
                if (T->balancing== -1){
                    child = T->left;
                    if (child->balancing == -1)
                        rotation_left_left(T, changed_height);
                    else rotation_left_right(T, changed_height);
                } else if (T->balancing == 0){
                    T->balancing = -1;
                    changed_height = 1;
                } else if (T->balancing == 1){
                    T->balancing = 0;
                    changed_height = 0;
                }
            }
        } else if (T->info < value){
            insert(T->right, value, ok, changed_height);
            if (changed_height){
                if (T->balancing == -1){
                    T->balancing = 0;
                    changed_height = 0;
                } else if (T->balancing == 0){
                    T->balancing = 1;
                    changed_height = 1;
                } else if (T->balancing == 1){
                    child = T->right;
                    if (child->balancing == 1)
                        rotation_right_right(T, changed_height);
                    else rotation_right_left(T, changed_height);
                }
            }
        }
    }
}

int main()
{
    /*node A, B, C, D, E, F, G;
    A.info = 0;
    A.left = A.right = NULL;
    B.info = 2;
    B.left = B.right = NULL;
    C.info = 4;
    C.left = C.right = NULL;
    D.info = 6;
    D.left = D.right = NULL;
    E.info = 1;
    E.left = &A;
    E.right = &B;
    F.info = 5;
    F.left = &C;
    F.right = &D;
    G.info = 3;
    G.left = &E;
    G.right = &F;

    if (is_balanced(&G))
        printf("Num primeiro momento, esta balanceada\n");
    else printf("Nao esta balanceada\n");

    node H, I;
    H.info = 7;
    H.left = H.right = NULL;
    D.right = &H;

    if (is_balanced(&G))
        printf("Mesmo após a inserção de %d esta balanceada\n", H.info);
    else printf("Nao esta mais balanceada\n");

    I.info = 8;
    H.right = &I;
    I.left = I.right = NULL;

    if (is_balanced(&G))
        printf("Mesmo apos a insercao de %d esta balanceada\n", I.info);
    else printf("Apos a insercao de %d, nao esta mais balanceada\n", I.info);*/

    node A, B, C, D, E, F, G, H, I;
    insert(&A, 0, 1, 1);

    if (is_balanced(&A))
        printf("The tree whose root value is %d is balanced\n", A.info);
    else printf("The tree whose root value is %d is not balanced\n", A.info);


    return 0;
}
