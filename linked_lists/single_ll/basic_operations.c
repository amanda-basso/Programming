/* This code implements append, search and remove operations for linked lists
 * The pointer to 'head' always stays in the head of the linked list
 * The pointer L is the one used to pass through the linked list.*/
#include<stdio.h>
#include<stdlib.h>
#include"basic_operations.h"

void append(node **head, node **L, const int data){
    node *aux = malloc(sizeof(node));
    aux->data = data;
    aux->next = NULL;

    if (*L == NULL) {
        *head = aux;
        *L = aux;
    }
    else if ((*L)->next == NULL)
        (*L)->next = aux;
    else {
        *L = (*L)->next;
        append(head, L, data);
    }
}

void print_linked_list(node *head){
    node *aux;
    aux = head;

    while (aux != NULL){
        printf("%d ", aux->data);
        aux = aux->next;
    }
    printf("\n");
}

int search(node *head, const int data){
    node *aux;
    aux = head;

    if (aux == NULL)
        return 0;
    else {
        if (aux->data == data)
            return 1;
        else {
            aux = aux->next;
            search(aux, data);
        }
    }
}

int remove_node(node *head, const int data){
    node *aux1, *aux2;
    aux1 = head;
    aux2 = head->next;

    if (aux1 == NULL)
        return 0;
    else {
        if (aux2->data == data){
            aux1->next = aux2->next;
            aux2 = NULL;
            free(aux2);
            return 1;
        } else {
            aux1 = aux1->next;
            remove_node(aux1, data);
        }
    }   
}
