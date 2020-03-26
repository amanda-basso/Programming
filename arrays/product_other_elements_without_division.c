/* The following code calculates the array formed by the product of all 
 * elements in the given array except for the one at the ith position.
 * It implements the logic without using division.*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i, size_array;

    printf("Type size of array: ");
    scanf("%d", &size_array);

    int *array = malloc(size_array * sizeof(int));
    int *product_array = malloc(size_array * sizeof(int));
    int *prefix_array = malloc(size_array * sizeof(int));
    int *suffix_array = malloc(size_array * sizeof(int));

    for (i = 0; i < size_array; i++){
        printf("Type element: ");
        scanf("%d", array + i);
        *(prefix_array + i) = -1;
        *(suffix_array + i) = -1;
        *(product_array + i) = -1;
    }
    // Creates prefix array
    for (i = 0; i < size_array; i++){
        if (*prefix_array == -1)
            *prefix_array = *(array + i);
        else
            *(prefix_array + i) = *(prefix_array + i - 1) * *(array + i);
    }
    // Creates suffix array
    for (i = size_array - 1; i >= 0; i--){
        if (*(suffix_array + size_array - 1) == -1)
            *(suffix_array + i) = *(array + size_array - 1);
        else
            *(suffix_array + i) = *(suffix_array + i + 1) * *(array + i);
    }
    // Multiplies prefix array with suffix according to index
    *product_array = *(suffix_array + 1);
    *(product_array + size_array - 1) = *(prefix_array + size_array - 2);
    for (i = 1; i < size_array - 1; i++)
        *(product_array + i) = *(prefix_array + i - 1) * *(suffix_array + i + 1);

    printf("\nProduct array:\n");
    for (i = 0; i < size_array; i++){
        printf("%d ", *(product_array + i));
    }
    printf("\n");
    
    free(array);
    free(prefix_array);
    free(suffix_array);
    free(product_array);

    return 0;
}
