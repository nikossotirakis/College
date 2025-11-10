#include <stdio.h>

float min(float arr[], int N);
float man(float arr[], int N);
void minmax(float arr[], int N);

int main(int argc, char *argv[]) {
    int arraySize = 0;

    // Getting the size of the array from the user
    printf("Enter the array size: ");
    scanf("%d", &arraySize);

    // Creating and initialise the array
    float arr[arraySize];

    for (int i = 0; i < arraySize; i++) {
        printf("Enter the %d element of the array: ", i);
        scanf("%d", &arr[i]);
    }

    minmax(arr, arraySize);

    return 0;
}

float min(float arr[], int N) {
    int min = 999;

    for (int i = 0; i < N; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    return min;
}

float man(float arr[], int N) {
    int max = -999;

    for (int i = 0; i < N; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}

void minmax(float arr[], int N) {
    int min = 999;
    int max = -999;

    // Calculate min
    for (int i = 0; i < N; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    // Calculate max
    for (int i = 0; i < N; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Convert array elements
    for (int i = 0; i < N; i++) {
        arr[i] = (arr[i] - min) / (max - min);
    }
}