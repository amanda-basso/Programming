/* This code implements insertion into heaps in C */
#include<stdio.h>
#include<stdlib.h>
#include"../utils/utils.h"

void heapify(int *array, int size_array, int index){
    int parent = (index - 1)/2;

    if (parent > 0)
        if (*(array + parent) < *(array + index)){
            swap((array + parent), (array + index));
            heapify(array, size_array, parent);
        }
}

void insert_heap(int *array, int size_array, int value){
    size_array++;
    *(array + size_array - 1) = value;
    heapify(array, size_array, size_array - 1);
}

int main(int argc, char *argv[1])
{
    int i, element;
    int *array = malloc(atoi(argv[1]) * sizeof(int));

    printf("Insert elements into heap:\n");
    for (i = 0; i < atoi(argv[1]); i++){
        scanf("%d", &element);
        insert_heap(array, i, element);
    }

    print_array(array, atoi(argv[1]), "Array generated");

    free(array);
    
    return 0;
}
