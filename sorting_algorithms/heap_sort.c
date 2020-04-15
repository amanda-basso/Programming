/* This code implements heap sort in C */
#include<stdlib.h>
#include"../utils/utils.h"

int main(int argc, char *argv[])
{
    int *array = malloc(atoi(argv[1]) * sizeof(int));

    create_random_array(array, atoi(argv[1]));

    print_array(array, atoi(argv[1]), "Original array");

    return 0;
}
