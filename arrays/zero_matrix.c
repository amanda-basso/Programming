/* Implements a code that sets the entire row and the entire
 * column as zeros if there are elements zero found
 *
 * In this approach, the rows and the columns to be set as zero
 * are stored in their respective arrays without duplicates.
 * This requires to pass twice through the matrix in search of
 * rows and columns to be set as zeros.
 *
 * If we wanted to pass only once through the matrix looking
 * for zero elements, it would be necessary to store the rows
 * and columns in linked lists, to sort both of them and then
 * to eliminate the duplicates.*/
#include<stdio.h>
#include<stdlib.h>
#include"../utils/utils.h"

int find_zero_elements(int **matrix, const int size_rows, const int size_columns, int *rows, int *columns){
    int i, j;
    int flag, count_row, count_column;
    flag = count_row = count_column = 0;

    // Passes through matrix looking up for rows to be set as zeros
    // Doesn't insert duplicates
    for (i = 0; i < size_rows; i ++)
        for (j = 0; j < size_columns; j++)
            if (*(*(matrix + i) + j) == 0){
                if (!flag)
                    flag = 1;
                *(rows + count_row) = i;
                count_row++;
                break;
            }

    if (!flag)
        return flag;

    // Passes through matrix looking up for columns to be set as zeros
    // Doesn't insert duplicates
    for (j = 0; j < size_columns; j++)
        for (i = 0; i < size_rows; i++)
            if (*(*(matrix + i) + j) == 0){
                *(columns + count_column) = j;
                count_column++;
                break;
            }

    return flag;
}

void set_elements_to_zero(int **matrix, const int size_rows, const int size_columns, int *rows, int *columns){
    int i, row, column, counter = 0;

    while ((*(rows + counter) != -1) && (counter < size_rows)){
        row = *(rows + counter);
        // Given an array, this function will initialize it with the given value
        initialize_array(*(matrix + row), size_columns, 0);
        counter++;
    }

    counter = 0;
    while ((*(columns + counter) != -1) && (counter < size_columns)) {
        column = *(columns + counter);
        for (i = 0; i < size_rows; i++){
            *(*(matrix + i) + column) = 0;
        }
        counter++;
    }
}

int main(int argc, char *argv[])
{
    int i, j;
    int **matrix = malloc(atoi(argv[1]) * sizeof(int*));
    for (i = 0; i < atoi(argv[1]); i++)
        *(matrix + i) = malloc(atoi(argv[2]) * sizeof(int));
    
    int *rows = malloc(atoi(argv[1]) * sizeof(int));
    int *columns = malloc(atoi(argv[2]) * sizeof(int));
    
    initialize_array(rows, atoi(argv[1]), -1);
    initialize_array(columns, atoi(argv[2]), -1);
    
    create_random_matrix(matrix, atoi(argv[1]), atoi(argv[2]));
    print_matrix(matrix, atoi(argv[1]), atoi(argv[2]), "Original matrix");

    if (find_zero_elements(matrix, atoi(argv[1]), atoi(argv[2]), rows, columns)){
        set_elements_to_zero(matrix, atoi(argv[1]), atoi(argv[2]), rows, columns);
        print_matrix(matrix, atoi(argv[1]), atoi(argv[2]), "Modified matrix");
    }

    return 0;
}
