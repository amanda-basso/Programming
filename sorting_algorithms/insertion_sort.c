/* This code implements insertion sort algorithm in C */
#include <stdlib.h>

#include "../utils/utils.h"

void insertion_sort(int *array, size_t size) {
    size_t i, j;
    int key;

    for (i = 1; i < size; i++) {
        key = *(array + i);
        j = i - 1;

        while (j >= 0 && *(array + j) > key) {
            *(array + j + 1) = *(array + j);
            j--;
        }
        *(array + j + 1) = key;
    }
}

int main(int argc, char *argv[])
{
    int *array = malloc(atoi(argv[1]) * sizeof(int));

    create_random_array(array, atoi(argv[1]));

    print_array(array, atoi(argv[1]), "Original array");

    insertion_sort(array, atoi(argv[1]));

    print_array(array, atoi(argv[1]), "Sorted array");

    free(array);

    return 0;
}
