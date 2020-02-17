/* This code implements two different ways of inverting
 * a linked list. Both are O(n) in time but 'invert_ll'
 * is more efficient as it only takes O(1) space.
 * Basic operations such as append are already implemented
 * in the basic_operations files.*/
#include<stdio.h>
#include<stdlib.h>
#include"basic_operations.h"

/*node* invert_linked_list(node *head, node *ptr, node **invert)
{
    node *aux = malloc(sizeof(node));
    
    if (ptr == NULL)
        return NULL;
    else if (ptr->next == NULL){
        aux->data = ptr->data;
        aux->next = NULL;
        *invert = aux;
        return invert;
    }
    else {
        ptr = ptr->next;
        node *aux1 = invert_linked_list(ptr, invert);
        aux1->next = ptr;
        ptr->next = NULL;
        //return ;
    }
}*/

// Inverts using the same linked list. Takes O(1) extra space.
void invert_ll(node *head)
{
    int i = 0;
    node *prev, *cur, *nxt;
    cur = head;
    prev = NULL;
    nxt = head->next;

    while(nxt != NULL){
        printf("\nIteration: %d\n", i);
        i++;
        //printf("Prev->data = %d\n", prev->data);
        printf("Cur->data = %d\n", cur->data);
        printf("Nxt->data = %d\n", nxt->data);
        cur->next = prev;
        prev = cur;
        cur = nxt;
        nxt = nxt->next;
    }

}

int main(int argc, char *argv[])
{
    node *llPointer, *head, *invert;
    int i;

    llPointer = head = invert = NULL;

    for (i = 0; i < argc - 1; i++)
        append(&head, &llPointer, atoi(argv[i + 1]));

    print_linked_list(head);
    invert_ll(head);
    print_linked_list(head);

    return 0;
}
