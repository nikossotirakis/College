#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int* rand_int(int N, int low, int high) {
    int *array = malloc(N * sizeof(int));

    for (int i = 0; i < N; i++) {
        *(array + i) = rand() % (high - low + 1) + low;
    }

    return array;
}

int product(int u[], int v[], int N) {
    int product = 0;

    for (int i = 0; i < N; i++) {
        product += u[i] * v[i];
    }

    return product;
}

int main(void) {
    int size = 0;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    srand(time(NULL));

    int *arr1 = rand_int(size, 1, 10);
    int *arr2 = rand_int(size, 1, 10); 

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < size; j++) {
            if (i == 0) {
                printf("%d ", arr1[j]);
            } 
            else {
                printf("%d ", arr2[j]);
            }
        }
        printf("\n");
    }

    printf("\nThe product of these 2 variables are: %d", product(arr1, arr2, size));

    free(arr1);
    free(arr2);

    return 0;
}