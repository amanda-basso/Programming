/*This code implements the brute force solution for the
 * maximum subarray sum*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void create_integer_array(int *array, const int size){
    srand(time(NULL));
    int i;
    
    for (i = 0; i < size; i++){
        *(array + i) = (rand() % 20) - 10;
        printf("%d ", *(array + i));
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    int i, j, k, curr_max = 0, sum = 0;
    int *array = malloc(atoi(argv[1]) * sizeof(int));
    
    create_integer_array(array, atoi(argv[1]));

    
    for (i = 0; i < atoi(argv[1]) - 1; i++){
        for (j = i; j < atoi(argv[1]); j++){
            for (k = j; k <= i; k++){
                sum += *(array + k);
            }
        }
    }

    return 0;
}
