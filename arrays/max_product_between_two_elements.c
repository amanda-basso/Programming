/* Implements a code that returns the maximum product between two elements in a list*/
#include<stdio.h>
#include<stdlib.h>
#include"../utils/utils.h"

int optimized_algorithm(int *array, const int size_array){
    int i, greatest = 0, second_greatest = 0;

    for (i = 0; i < size_array; i++){
        if (*(array + i) > greatest){
            if (greatest > second_greatest)
                second_greatest = greatest;
            greatest = *(array + i);
        }
        else if (*(array + i) > second_greatest)
            second_greatest = *(array + i);
    }
    return greatest * second_greatest;
}

int brute_force_solution(int *array, const int size_array){
    int i, j, product, max_product = 0;

    for (i = 0; i < size_array - 1; i++){
        for (j = i + 1; j < size_array; j++){
            product = *(array + i) * *(array + j);
            if (product > max_product)
                max_product = product;
        }
    }

    return max_product;
}

int main(int argc, char *argv[])
{
    int i;
    int *array = malloc((argc - 1) * sizeof(int));

    //Alocate array
    for (i = 0; i < argc - 1; i++)
        *(array + i) = atoi(argv[i + 1]);

    print_array(array,argc - 1, "Alocated array:");
    
    printf("Brute force solution: %d\n", brute_force_solution(array, argc - 1));
    printf("Optimized solution: %d\n", optimized_algorithm(array, argc - 1));

    return 0;
}
