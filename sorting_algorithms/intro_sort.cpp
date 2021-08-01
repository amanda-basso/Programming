/* Implements Introsort algorithm, a hybrid sorting algorithm.
 * It is a hybrid between quicksort, heapsort, and insertionsort. */
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>

template <typename T>
void swap(T *a, T *b) {
    T aux = *a;
    *a = *b;
    *b = aux;
}

template <typename T>
void insertionsort(T *array, int low, int high) {
    for (int i = low + 1; i <= high; i++) {
        T key = *(array + i);
        int j = i - 1;

        while (j >= 0 && *(array + j) > key) {
            *(array + j + 1) = *(array + j);
            j--;
        }
        *(array + j + 1) = key;
    }
}

template <typename T>
void heapify(T *array, int low, int high, int root) {
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;
    int size = high - low + 1;

    if (left < size && *(array + left) > *(array + largest)) {
        largest = left;
    }
    
    if (right < size && *(array + right) > *(array + largest)) {
        largest = right;
    }

    if (largest != root) {
        swap((array + largest), (array + root));
        heapify(array, low, high, largest);
    }
}

template <typename T>
void heapsort(T *array, int low, int high) {
    for (int i = ((high - low) / 2) + low; i >= low; i--) {
        heapify(array, low, high, i);
    }

    for (int i = high; i >= low; i--) {
        swap((array + low), (array + i));
        heapify(array, low, i - 1, low);
    }
}

template <typename T>
int partition(T *array, int low, int high) {
    T pivot = *(array + high);
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (*(array + j) < pivot) {
            i++;
            swap((array + j), (array + i));
        }
    }
    swap((array + i + 1), (array + high));

    return (i + 1);
}

template <typename T>
void quicksort(T *array, int low, int high, int depth_limit) {
    if ((high - low + 1) <= 16) {
        insertionsort(array, low, high);
    }

    if (depth_limit == 0) {
        heapsort(array, low, high);
    }

    else {
        int partition_index = partition(array, low, high);
        quicksort(array, low, partition_index - 1, depth_limit - 1);
        quicksort(array, partition_index + 1, high, depth_limit - 1);
    }
}

template <typename T>
void introsort(T *array, int low, int high) {
    int depth_limit = 2 * log(high - low + 1);
    quicksort(array, low, high, depth_limit);
}

int main(int argc, char **argv)
{
    srand(time(NULL));
    size_t size = atoi(*(argv + 1));
    int *array = (int*) malloc(size * sizeof(int));

    for (size_t i = 0; i < size; i++) {
        *(array + i) = rand() % 100;
        std::cout << *(array + i) << " ";
    }
    std::cout << std::endl;

    introsort(array, 0, size - 1);

    for (size_t i = 0; i < size; i++) {
        std::cout << *(array + i) << " ";
    }
    std::cout << std::endl;

}
