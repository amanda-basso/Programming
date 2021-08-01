/* This code includes an implementation of the merge sort algorithm*/
#include <stdlib.h>

#include "../utils/utils.h"

void merge(int *array, int left, int middle, int right) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++) {
        L[i] = *(array + left + i);
    }
    for (j = 0; j < n2; j++) {
        R[j] = *(array + middle + 1 + j);
    }

    i = j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            *(array + k) = L[i];
            i++;
        }
        else {
            *(array + k) = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        *(array + k) = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        *(array + k) = R[j];
        j++;
        k++;
    }
}

void merge_sort(int *array, int left, int right) {
    if (left < right) {
        int middle = left + (right - left)/2;
        merge_sort(array, left, middle);
        merge_sort(array, middle + 1, right);
        merge(array, left, middle, right);
    }
}

int main(int argc, char *argv[])
{
    int *array = malloc(atoi(argv[1]) * sizeof(int));

    create_random_array(array, atoi(argv[1]));

    print_array(array, atoi(argv[1]), "Original array");

    merge_sort(array, 0, atoi(argv[1]) - 1);

    print_array(array, atoi(argv[1]), "Sorted array");

    free(array);

    return 0;
}
