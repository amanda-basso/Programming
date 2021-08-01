/* This code implements the selection sort algorithm */
#include <stdlib.h>

#include "../utils/utils.h"

void selection_sort(int *array, size_t size) {
    size_t i, j, min_index;

    for (i = 0; i < size - 1; i++) {
        min_index = i;
        for (j = i + 1; j < size; j++) {
            if (*(array + j) < *(array + min_index)) {
                min_index = j;
            }
        }
        if (min_index != i) {
            swap((array + i), (array + min_index));
        }
    }
}

int main(int argc, char *argv[])
{
    int *array = malloc(atoi(argv[1]) * sizeof(int));

    create_random_array(array, atoi(argv[1]));

    print_array(array, atoi(argv[1]), "Original array");

    selection_sort(array, atoi(argv[1]));

    print_array(array, atoi(argv[1]), "Sorted array");

    free(array);

    return 0;
}
