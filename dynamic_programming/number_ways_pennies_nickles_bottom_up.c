/* This code implements the bottom up aproach for outputting
 * the number of ways to lay nickels and pennies into a line
 * until they sum up to some value.*/
#include<stdio.h>
#include<stdlib.h>

long long coin_ways(int number, long long *cache){
    int i;

    for (i = 6; i <= number; i++)
        *(cache + i) = *(cache + i - 1) + *(cache + i - 5);

    return *(cache + number);
}

int main(int argc, char *argv[])
{
    int i;
    long long *cache = malloc((atoi(argv[1]) + 1) * sizeof(long long));
    long long number_ways;

    for (i = 0; i <= atoi(argv[1]); i++){
        if (i >= 0 && i < 5)
            *(cache + i) = 1;
        else if (i == 5)
            *(cache + i) = 2;
        else
            *(cache + i) = -1;
    }

    number_ways = coin_ways(atoi(argv[1]), cache);
    printf("Number ways = %lld\n", number_ways);
    
    return 0;
}
