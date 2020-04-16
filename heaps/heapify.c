/* This code implements heapify in C
 * It takes an array and turns it into a heap */
#include<stdlib.h>
#include"../utils/utils.h"

void heapify(int *array, const int size_array, int i){
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (right < size_array && *(array + right) < *(array + smallest))
        smallest = right;

    if (left < size_array && *(array + left) < *(array + smallest))
        smallest = left;

    if (smallest != i){
        swap((array + smallest), (array + i));
        heapify(array, size_array, smallest);
    }
}

void build_heap(int *array, const int size_array){
    int i;
    int start_index = (size_array / 2) - 1; //index of last non-leaf node

    for (i = start_index; i >= 0; i--)
        heapify(array, size_array, i);
}

int main(int argc, char *argv[])
{
    int *array = malloc(atoi(argv[1]) * sizeof(int));

    create_random_array(array, atoi(argv[1]));

    print_array(array, atoi(argv[1]), "Array generated");
    build_heap(array, atoi(argv[1]));
    print_array(array, atoi(argv[1]), "Heap in the form of array");

    free(array);

    return 0;
}
