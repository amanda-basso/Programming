/* This file contains util functions common to the implementation of diverse sorting algorithms */
#ifndef UTILS_H
#define UTILS_H

void swap(int *a, int *b);
void print_array(int *array, const int size_array, const char sentence[]);
void create_random_array(int *array, const int size_array);
int gets_size_string(char *string);
int partition(int *array, int low, int high);
void quick_sort(int *array, int low, int high);
void print_matrix(int **matrix, const int rows, const int columns, const char sentence[]);
void create_random_matrix(int **matrix, const int rows, const int columns);
void initialize_array(int *array, const int size_array, const int value);

#endif //UTILS_H
