#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void reverse_string(char *string){
    
}

int main(int argc, char *argv[])
{
    int i;
    srand(time(NULL));
    char *string = malloc(atoi(argv[1]) * sizeof(char));

    printf("Original string:\n");
    for (i = 0; i < atoi(argv[1]); i++){
        *(string + i) = rand()%25 + 97;
        printf("%c ", *(string + i));
    }
    printf("Last character: %c ", *(string + 10));
    printf("\n");

    return 0;
}
