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

void create_random_array(int *array, const int size_array){
    srand(time(NULL));
    int i;

    for (i = 0; i < size_array; i++)
        *(array + i) = rand()%100;
}

int gets_size_string(char *string){
    int size = 0;

    while (*(string + size) != '\0')
        size++;

    return size;
}
