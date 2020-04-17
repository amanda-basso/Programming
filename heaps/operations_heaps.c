/* This code implements heapify, insert and remove min in C */
#include<stdio.h>
#include<stdlib.h>
#include"../utils/utils.h"

void insert_heapify(int *array, int size_array, int index){
    int parent = (index - 1)/2;

    if (parent > 0)
        if (*(array + parent) < *(array + index)){
            swap((array + parent), (array + index));
            insert_heapify(array, size_array, parent);
        }
}

void insert_heap(int *array, int size_array, int value){
    size_array++;
    *(array + size_array - 1) = value;
    insert_heapify(array, size_array, size_array - 1);
}

void build_heapify(int *array, const int size_array, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (right < size_array && *(array + right) > *(array + largest))
        largest = right;

    if (left < size_array && *(array + left) > *(array + largest))
        largest = left;

    if (largest != i){
        swap((array + largest), (array + i));
        build_heapify(array, size_array, largest);
    }
}

void build_heap(int *array, const int size_array){
    int i;
    int start_index = (size_array / 2) - 1;

    for (i = start_index; i >= 0; i--)
        build_heapify(array, size_array, i);
}

int main(int argc, char *argv[])
{
    int i, element;
    int *array = malloc(atoi(argv[1]) * sizeof(int));

    if (atoi(argv[2]) == 0){
        create_random_array(array, atoi(argv[1]));

        print_array(array, atoi(argv[1]), "Array generated");
        build_heap(array, atoi(argv[1]));
        print_array(array, atoi(argv[1]), "Heap in the form of array");
    }
    else if (atoi(argv[2]) == 1){
        printf("Insert elements into heap:\n");
        for (i = 0; i < atoi(argv[1]); i++){
            scanf("%d", &element);
            insert_heap(array, i, element);
        }

        print_array(array, atoi(argv[1]), "Array generated");
    }
    else if (atoi(argv[2]) == 2){
        //Implement remove min
    }

    free(array);

    return 0;
}
