/* This code implement regular expressions matching:
 * . which matches any single character
 * * which matches zero or more of the preceding element
 * Implements a function that takes in a string and a valid
 * regex and returns whether the string matches.*/
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
    char *string = malloc((atoi(argv[1]) + 1) * sizeof(char));
    int i;

    for (i = 0; i < atoi(argv[1]); i++){
        *(string + i) = argv[i + 2];
        printf("%c\n", *(string + i));
    }

    return 0;
}
