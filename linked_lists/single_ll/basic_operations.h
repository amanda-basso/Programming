/* This file contains headers to single linked lists basic functions */
#ifndef BASIC_OPERATIONS_H
#define BASIC_OPERATIONS_H

typedef struct node{
    int data;
    struct node *next;
}node;

void append(node **head, node **L, const int data);
void print_linked_list(node *head);
int search(node *head, const int data);
int remove_node(node *head, const int data);

#endif //BASIC_OPERATIONS_H
