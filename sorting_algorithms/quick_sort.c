/* This code implements the quick sort method in C */
#include <stdlib.h>

#include "../utils/utils.h"

int partition(int *array, int low, int high) {
    int j;
    int pivot = *(array + high);
    int i = low - 1;

    for (j = low; j < high; j++) {
        if (*(array + j) < pivot) {
            i++;
            swap((array + j), (array + i));
        }
    }
    swap((array + i + 1), (array + high));

    return (i + 1);
}

void quick_sort(int *array, int low, int high) {
    if (low < high) {
        int partition_index = partition(array, low, high);
        quick_sort(array, low, partition_index - 1);
        quick_sort(array, partition_index + 1, high);
    }
}

int main(int argc, char *argv[])
{
    int *array = malloc(atoi(argv[1]) * sizeof(int));

    create_random_array(array, atoi(argv[1]));

    print_array(array, atoi(argv[1]), "Original array");

    quick_sort(array, 0, atoi(argv[1]) - 1);

    print_array(array, atoi(argv[1]), "Sorted array");

    free(array);

    return 0;
}
