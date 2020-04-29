/* This code calculates number of ways of laying pennies and nickles
 * into a line until their sum is equal to a dollar. The approach used
 * here is the recursive one so is very slow and not at all optimized.*/
#include<stdio.h>
#include<stdlib.h>

int coin_ways(int number){
    if (number >= 0 && number < 5)
        return 1;
    else if (number == 5)
        return 2;
    else return coin_ways(number - 5) + coin_ways(number - 1);
}

int main(int argc, char *argv[])
{
    int number_ways = coin_ways(atoi(argv[1]));

    printf("Number of ways = %d\n", number_ways);

    return 0;
}
