/* This code implements heap sort in C. */
#include <stdlib.h>

#include "../utils/utils.h"

void heapify(int *array, int size, int root) {
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < size && *(array + left) > *(array + largest)) {
        largest = left;
    }

    if (right < size && *(array + right) > *(array + largest)) {
        largest = right;
    }

    if (largest != root) {
        swap((array + largest), (array + root));
        heapify(array, size, largest);
    }
}

void heapsort(int *array, int size) {
    int i;

    for (i = size / 2 - 1; i >= 0; i--) {
        heapify(array, size, i);
    }

    for (i = size - 1; i >= 0; i--) {
        swap((array), (array + i));
        heapify(array, i, 0);
    }
}

int main(int argc, char *argv[])
{
    int *array = malloc(atoi(argv[1]) * sizeof(int));

    create_random_array(array, atoi(argv[1]));

    print_array(array, atoi(argv[1]), "Original array");

    heapsort(array, atoi(argv[1]));

    print_array(array, atoi(argv[1]), "Sorted array");

    return 0;
}
