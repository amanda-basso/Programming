/*This code calculates the product of all other elements of an array that are
 * not in the position i of the array*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i, size_array, product_of_all = 1;

    printf("Type the size of the array: ");
    scanf("%d", &size_array);

    int *array = malloc(size_array * sizeof(int));
    int *product_array = malloc(size_array * sizeof(int));
    
    for (i = 0; i < size_array; i++){
        printf("Type the element: ");
        scanf("%d", array + i);
        product_of_all *= *(array + i);
    }

    for (i = 0; i < size_array; i++){
        *(product_array + i) = product_of_all / *(array + i);
        printf("%d ", *(product_array + i));
    }
    
    printf("\n");
    free(array);
    free(product_array);

    return 0;
}
