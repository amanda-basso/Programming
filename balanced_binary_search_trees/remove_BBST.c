#include<stdio.h>

typedef struct node{
    int info;
    int balancing;
    struct node *left;
    struct node *right;
}node;

int tree_height(node *T){
    if (T == NULL)
        return 0;
    else {
        int Hleft = tree_height(T->left);
        int Hright = tree_height(T->right);

        if (Hleft > Hright)
            return 1 + tree_height(T->left);
        else return 1 + tree_height(T->right);
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

void rotation_right_right(node *T, int changed_height){
    node *child;
    
    child = T->right;
    T->right = child->left;
    child->left = T;
    
    if (child->balancing == 0){
        child->balancing = -1;
        T->balancing = 1;
        changed_height = 0;
    } else if (child->balancing == 1){
        child->balancing = 0;
        T->balancing = 0;
        changed_height = 1;
    }
    T = child;
}

void rotation_left_left(node *T, int changed_height){
    node *child;

    child = T->left;
    T->left = child->right;
    child->right = T;

    if (child->balancing == 0){
        T->balancing = -1;
        child->balancing = 1;
        changed_height = 0;
    } else if (child->balancing == -1){
        T->balancing = 0;
        child->balancing = 0;
        changed_height = 1;
    }
    T = child;
}

void rotation_left_right(node *T, int changed_height){
    node *child, *grandchild;

    child = T->left;
    grandchild = child->right;
    T->left = grandchild->right;
    child->right = grandchild->left;
    grandchild->left = child;
    grandchild->right = T;
    
    if (grandchild->balancing == 0){
        T->balancing = child->balancing = grandchild->balancing = 0;
    } else if (grandchild->balancing == 1){
        T->balancing = -1;
        child->balancing = 0;
        grandchild->balancing = 1;
    } else if (grandchild->balancing == -1){
        T->balancing = 0;
        child->balancing = 1;
        grandchild->balancing = -1;
    }
    T = grandchild;
    changed_height = 1;
}

void rotation_right_left(node *T, int changed_height){
    node *child, *grandchild;

    child = T->right;
    grandchild = child->left;
    child->left = grandchild->right;
    T->right = grandchild->left;
    grandchild->left = T;
    grandchild->right = child;

    if (grandchild->balancing == 0){
        T->balancing = child->balancing= grandchild->balancing = 0;
    } else if (grandchild->balancing == 1){
        T->balancing = 0;
        child->balancing = -1;
        grandchild->balancing = 1;
    } else if (grandchild->balancing == -1){
        T->balancing = 1;
        child->balancing = 0;
        grandchild->balancing = -1;
    }
    T = grandchild;
    changed_height = 1;
}

void remove_node(node *T, int value, int ok, int changed_height){
    node *aux, *child;
    if (T == NULL){
        ok = 0; //there's no way or removing from an empty tree
        changed_height = 0;
    } else {
        if (value < T->info){
            remove_node(T->left, value, ok, changed_height);
            if (changed_height){
                if (T->balancing == 0){
                    T->balancing = 1;
                    changed_height = 0;
                } else if (T->balancing == -1){
                    T->balancing = 0;
                    changed_height = 1;
                } else if (T->balancing == 1){
                    child = T->right;
                    if (child->balancing == -1)
                        rotation_left_right(T, changed_height);
                    else rotation_left_left(T, changed_height);
                }
            }
        } else if (value > T->info){
            remove_node(T->right, value, ok, changed_height);
            if (changed_height){
                if (T->balancing == 0){
                    T->balancing = -1;
                    changed_height = 0;
                } else if (T->balancing == 1){
                    T->balancing = 0;
                    changed_height = 1;
                } else if (T->balancing == -1){
                    child = T->left;
                    if (child->balancing == 1)
                        rotation_left_right(T, changed_height);
                    else rotation_left_left(T, changed_height);
                }
            }
        } else if (value == T->info){
            aux = T;
            if (T->left == NULL && T->right == NULL){
                // deletenode(aux);
                T = NULL;
                ok = 1;
                changed_height = 1;
            } else if (T->left != NULL && T->right != NULL){
                aux = T->left;
                while (aux->right != NULL){
                    aux = aux->right;
                }
                T->info = aux->info;
                remove_node(T->left, T->info, ok, changed_height);
                if (changed_height){
                    if (T->balancing == 0){
                        T->balancing = 1;
                        changed_height = 0;
                    } else if (T->balancing == -1){
                        T->balancing = 0;
                        changed_height = 1;
                    } else if (T->balancing == 1){
                        child = T->right;
                        if (child->balancing == -1)
                            rotation_right_left(T, changed_height);
                        else rotation_right_right(T, changed_height);
                    }
                }
            } else {
                if (T->left == NULL)
                    T = T->right;
                else T = T->left;
                //deletenode(aux);
                ok = 1;
                changed_height = 1;
            }
        }
    }
}

int main()
{
    return 0;
}
