/* This code includes an implementation of the bubble sort algorithm */
#include<stdlib.h>
#include"../utils/utils.h"

void bubble_sort(int *array, const int size_array){
    int i, j;

    for (i = 0; i < size_array - 1; i++)
        for (j = 0; j < size_array - 1; j++)
            if (*(array + j) > *(array + j + 1))
                swap((array + j), (array + j + 1));
}

int main(int argc, char* argv[])
{
    int *array = malloc(atoi(argv[1]) * sizeof(int));

    create_random_array(array, atoi(argv[1]));

    print_array(array, atoi(argv[1]), "Original array");
    bubble_sort(array, atoi(argv[1]));
    print_array(array, atoi(argv[1]), "Sorted array");

    free(array);

    return 0;
}
