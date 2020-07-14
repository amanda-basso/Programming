/* This code checks if a string has all unique characters*/
#include<stdio.h>
#include<stdlib.h>
#include"../utils/utils.h"

int verifies_unique_chars(char *string, int *array, int size_string){
    int i, index;

    for (i = 0; i < 26; i++)
        *(array + i) = 0;

    for (i = 0; i < size_string; i++){
        index = *(string + i) - 97;
        //printf("INDEX = %d\n", index);
        *(array + index) = *(array + index) + 1;
    }

    for (i = 0; i < 26; i++){
        if (*(array + i) > 1)
            return 0;
        else
            return 1;
    }
}

int main(int argc, char *argv[])
{
    int *array = malloc(26 * sizeof(int));
    int size_string;

    size_string = gets_size_string(argv[1]);
    
    if (verifies_unique_chars(argv[1], array, size_string) == 1)
        printf("String has all unique characters!\n");

    else if (size_string > 26)
        printf("String has not all unique characters since is has %d letters!\n", size_string);
     
    else
        printf("String has not all unique characters!\n");

    return 0;
}
