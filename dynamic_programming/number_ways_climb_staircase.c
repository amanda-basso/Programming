/* This code implements ways of climbing a stairway given an array of
 * possible steps. */
#include<stdio.h>
#include<stdlib.h>

long long stair_ways(int number, long long *cache, int *steps, int number_steps){
    int i, j;

    for (i = 1; i <= number; i++)
        for (j = 0; j < number_steps; j++)
            if (i - *(steps + j) >= 0)
                *(cache + i) += *(cache + i - *(steps + j));

    return *(cache + number);
}

int main(int argc, char *argv[])
{
    int i, j, number_steps = argc - 2;
    int *steps = malloc((argc - 2) * sizeof(int));
    long long number_ways;
    long long *cache = malloc((atoi(argv[1]) + 1) * sizeof(long long));

    // Fills array with number of steps
    for (i = 2; i < argc; i++)
        *(steps + i - 2) = atoi(argv[i]);

    // Fills cache
    for (i = 1; i <= atoi(argv[1]); i++)
        *(cache + i) = 0;
    *cache = 1;

    number_ways = stair_ways(atoi(argv[1]), cache, steps, number_steps);

    for (i = 0; i <= atoi(argv[1]); i++)
        printf("f(%d) = %lld\n", i, *(cache + i));
    printf("Number of ways = %lld\n", number_ways);

    return 0;
}
