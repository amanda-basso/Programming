/* This code implements string compression
 * Given a string in the following format:
 * aaabcccccddeeee
 * it returns
 * a3b1c5d2e4*/
#include<stdio.h>
#include<stdlib.h>
#include"../utils/utils.h"

int string_compression(char *string, char *compressed, int size_string)
{
    int i, j = 0, counter = 1;
    char aux = *(string);

    for (i = 1; i <= size_string; i++){
        if (*(string + i) == aux)
            counter++;
        else {
            *(compressed + j) = aux;
            // Add char equivalent to number of repetitions
            *(compressed + j + 1) = counter + 48;
            j += 2;
            aux = *(string + i);
            counter = 1;
        }
    }
    *(compressed + j) = '\0';
    if (j > size_string)
        return 0;
    else return 1;
}

int main(int argc, char *argv[])
{
    int size_string = gets_size_string(argv[1]);
    char *compressed = malloc(size_string * sizeof(char));
    int i, compression;
    
    compression = string_compression(argv[1], compressed, size_string);

    if (compression){
        for (i = 0; i < size_string; i++)
            printf("%c ", *(compressed + i));

        printf("\n");
    }
    else printf("It was not possible to compress\n");
    
    int size_compressed = gets_size_string(compressed);

    printf("Size of original string = %d\n", size_string);
    printf("Size of compressed string = %d\n", size_compressed);

    return 0;
}
