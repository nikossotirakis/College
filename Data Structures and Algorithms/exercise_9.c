#include <stdio.h>

int sum(int arr[], int N) {
    int sum = 0;

    for (int i = 0; i < N; i++) {
        sum += arr[i];
    }

    return sum;
}

int sumRecurse(int arr[], int N) {
    if (N == 0)
        return 0;
    else
        return arr[N - 1] + sumRecurse(arr, N - 1);
}

int main(void) {
    int arr[10] = {1, 5, 2, 7, 8, 3, 6, 9, 10, 2};

    printf("The sum of the array with for-loop: %d\n", sum(arr, 10));
    printf("The sum of the array with Recursion: %d\n", sumRecurse(arr, 10));

    return 0;
}