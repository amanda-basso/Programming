/*This code implements Kadane's algorithm to calculate the maximum subarray sum */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>

void createRandomIntegerArray(int *array, int size){
    int i;

    for (i = 0; i < size; i++){
        *(array + i) = (rand() % 20) - 10;
        printf("%d ", *(array + i));
    }
    printf("\n");
}

int kadanesAlgorithm(int *array, int size){
    int max_so_far = INT_MIN, local_max = 0;
    int i;

    for (i = 0; i < size; i++){
        local_max += *(array + i);
        if (max_so_far < local_max)
            max_so_far = local_max;
        if (local_max < 0)
            local_max = 0;
    }
    return max_so_far;
}

int main(int argc, char *argv[])
{
    srand(time(NULL));
    int *array = malloc(atoi(argv[1]) * sizeof(int));
    int i, max_subarray_sum;

    createRandomIntegerArray(array, atoi(argv[1]));
    max_subarray_sum = kadanesAlgorithm(array, atoi(argv[1]));

    printf("Max subarray sum = %d\n", max_subarray_sum);

    return 0;
}
