/* This code finds the smallest window necessary to sort an array*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int max_min_number(int max_min_seen, int number_array, char max_min[]){
    if (max_min == "max"){
        if (max_min_seen > number_array)
            return max_min_seen;
        else return number_array;
    } else {
        if (max_min_seen > number_array)
            return number_array;
        else return max_min_seen;
    }
}

int main(int argc, char *argv[])
{
    int i, current, min_seen = 100, max_seen = -1, highest_bound = -1, lowest_bound = -1;
    srand(time(NULL));
    int *array = malloc(atoi(argv[1]) * sizeof(int));

    for (i = 0; i < atoi(argv[1]); i++){
        *(array + i) = rand()%100;
        printf("%d ", *(array + i));
    }
    printf("\n");
    
    for (i = 0; i < atoi(argv[1]); i++){
        current = *(array + i);
        max_seen = max_min_number(max_seen, current, "max");
        if (*(array + i) < max_seen)
            lowest_bound = i;
    }
    for (i = atoi(argv[1]) - 1; i >= 0; i--){
        current = *(array + i);
        min_seen = max_min_number(min_seen, current, "min");
        if (*(array + i) > min_seen)
            highest_bound = i;
    }

    if (highest_bound == -1)
        printf("Array is already sorted\n");
    else
        printf("\nSmallest window to sort array: (%d, %d)\n", highest_bound, lowest_bound);

    free(array);

    return 0;
}
