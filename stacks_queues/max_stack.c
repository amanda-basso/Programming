/* This code implements push, pop, peek, isEmpty and max_value on a stack*/
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int value;
    struct node *next;
}node;

void push(node* stack, node *aux, const int val){
    
    aux->value = val;
    aux->next = NULL;
    stack->next = aux;
    stack = stack->next;
    printf("Stack inside function = %d\n", stack->value);
}

int main(int argc, char *argv[])
{
    int i;
    node *aux = malloc(sizeof(node));
    node *stack = malloc(sizeof(node));

    aux->value = stack->value = -1;
    aux->next = stack->next = NULL;

    for (i = 0; i < argc - 1; i++){
        push(stack, aux, atoi(argv[i + 1]));
        printf("Stack value in main = %d\n", stack->value);
    }

    return 0;
}
