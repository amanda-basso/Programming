/* This is the dynamic programming version of the code that
 * outputs the number of ways to line up pennies and nickels
 * until they sum up a given value. The approach used is top-down.*/
#include<stdio.h>
#include<stdlib.h>

long long coin_ways(int number, long long *cache){
    if (*(cache + number) != -1)
        return *(cache + number);
    
    *(cache + number) = coin_ways(number - 1, cache) + coin_ways(number - 5, cache);
    return *(cache + number);
}

int main(int argc, char *argv[])
{
    int i;
    long long *cache = malloc((atoi(argv[1]) + 1) * sizeof(long long));
    long long number_ways;

    // Creates cache with basic values already
    for (i = 0; i <= atoi(argv[1]); i++){
        if (i >= 0 && i < 5)
            *(cache + i) = 1;
        else if (i == 5)
            *(cache + i) = 2;
        else 
            *(cache + i) = -1;
    }

    number_ways = coin_ways(atoi(argv[1]), cache);
    
    printf("Number of ways: %lld\n", number_ways);

    return 0;
}
