#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"utils.h"

void swap(int *a, int *b){
    int aux;

    aux = *a;
    *a = *b;
    *b = aux;
}

void print_array(int *array, const int size_array, const char sentence[]){
    int i;

    printf("%s\n", sentence);
    for (i = 0; i < size_array; i++)
        printf("%d ", *(array + i));
    printf("\n");
}

void print_matrix(int **matrix, const int rows, const int columns, const char sentence[]){
    int i, j;

    printf("%s\n", sentence);
    for (i = 0; i < rows; i++){
        for (j = 0; j < columns; j++)
            printf("%d  ", *(*(matrix + i) + j));
        printf("\n");
    }
    printf("\n");
}

void create_random_array(int *array, const int size_array){
    srand(time(NULL));
    int i;

    for (i = 0; i < size_array; i++)
        *(array + i) = rand() % 100;
}

void create_random_matrix(int **matrix, const int rows, const int columns){
    srand(time(NULL));
    int i, j;

    for (i = 0; i < rows; i++)
        for (j = 0; j < columns; j++)
            *(*(matrix + i) + j) = rand() % 10;
}

void initialize_array(int *array, const int size_array, const int value){
    int i;

    for (i = 0; i < size_array; i++)
        *(array + i) = value;
}

int gets_size_string(char *string){
    int size = 0;

    while (*(string + size) != '\0')
        size++;

    return size;
}

int qpartition(int *array, int low, int high){
    int j;
    int pivot = *(array + high);
    int i = low - 1;

    for (j = low; j < high; j++){
        if (*(array + j) < pivot){
            i++;
            swap((array + j), (array + i));
        }
    }
    swap((array + i + 1), (array + high));
    return (i + 1);
}

void quicksort(int *array, int low, int high){
    if (low < high){
        int partition_index = qpartition(array, low, high);
        quicksort(array, low, partition_index - 1);
        quicksort(array, partition_index + 1, high);
    }
}
