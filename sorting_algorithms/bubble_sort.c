/* This code implements the bubble sort algorithm */
#include <stdlib.h>

#include "../utils/utils.h"

void bubble_sort(int *array, size_t size){
    size_t i, j;

    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - 1; j++) {
            if (*(array + j) > *(array + j + 1)) {
                swap((array + j), (array + j + 1));
            }
        }
    }
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
