/* Implements solution to remove duplicate numbers on linked list
 * The values used to fill linked list are passed as parameters
 * during execution */
#include<stdio.h>
#include<stdlib.h>
#include"basic_operations.h"

// Node Hash Table
typedef struct nodeHT {
    int key;
    int value;
    struct nodeHT **next;
}nodeHT;

int main(int argc, char *argv[])
{
    int i;
    node *llHead;
    node *llPointer;

    llHead = llPointer = NULL;

    for(i = 0; i < argc - 1; i++)
        append(&llHead, &llPointer, atoi(argv[i + 1]));

    print_linked_list(llHead);

    return 0;
}
