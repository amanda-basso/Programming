/* This code implements the recursive way of outputtig the number of
 * ways it is possible to decode a given integer array into a string.
 * a = 1, b = 2, c = 3, ..., z = 26.*/
#include<stdio.h>
#include<stdlib.h>

int decode(int *array){
    //int number_ways;

    if (*array <= 0){
        printf("\nEmpty string\n");
        return 0;
    }
    else if (*array <= 2 && *(array + 1) <= 6){
        printf("\n%c\n", *array + 96);
        printf("\n%c\n", *array * 10 + *(array + 1) + 96);
        return 2 + decode(array + 1);
    }
    else{
        printf("\n%c\n", *array + 96);
        return 1 + decode(array + 1);
    }
}

int main(int argc, char *argv[])
{
    int i;
    int *array = malloc(atoi(argv[1]) * sizeof(int));

    for (i = 0; i < atoi(argv[1]); i++)
        *(array + i) = atoi(argv[i + 2]);

    printf("Given array:\n");
    for (i = 0; i < atoi(argv[1]); i++)
        printf("%d ", *(array + 1));

    printf("\nNumber of ways to decode string: %d\n", decode(array));
    
    return 0;
}
