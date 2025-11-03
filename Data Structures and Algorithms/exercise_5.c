#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* createIntArray(int size);
int* calculateProduct(int *arr1, int *arr2, int size);

int main(void) {
    // Getting the array size
    int arraySize = 0;

    printf("Enter the array size: ");
    scanf("%d", &arraySize);

    // Random seed
    srand(time(NULL));

    // Creating the array
    int *arr1 = createIntArray(arraySize);
    int *arr2 = createIntArray(arraySize);
    int *product = calculateProduct(arr1, arr2, arraySize);

    // Printing the arrays 
    for (int i = 0; i < 3; i++) {
        printf("Array %d values: ", i + 1);

        for (int j = 0; j < arraySize; j++) {
            if (i == 0) {
                printf("%d ", *(arr1 + j));
            } else if (i == 1) {
                printf("%d ", *(arr2 + j));
            } else {
                printf("%d ", *(product + j));
            }
        }

        printf("\n");
    }

    // Freeing up the memory
    free(arr1);
    free(arr2);
    free(product);

    return 0;
}

int* createIntArray(int size) {
    // Creating the array 
    int *arr = malloc(size * sizeof(int));

    // Checking for malloc failure
    if (arr == NULL) {
        printf("Error: Memory allocation failed!");
        free(arr);
        exit(1);
    }

    // Assign random values from 1-10 to the array
    for (int i = 0; i < size; i++) {
        *(arr + i) = rand() % 10 + 1;
    }

    return arr;
}

int* calculateProduct(int *arr1, int *arr2, int size) {
    // Creating the array
    int *product = malloc(size * sizeof(int));

    // Checking for malloc failure
    if (product == NULL) {
        printf("Error: Memory allocation failed!");
        free(product);
        exit(1);
    }

    // Calculating the product of the 2 arrays
    for (int i = 0; i < size; i++) {
        *(product + i) = *(arr1 + i) * *(arr2 + i);
    }

    return product;
}