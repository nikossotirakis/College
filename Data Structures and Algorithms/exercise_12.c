// interpolation_search.c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10000000

int interpolation_search(int arr[], int n, int x) {
    int low = 0;
    int high = n - 1;

    while (low <= high && x >= arr[low] && x <= arr[high]) {

        if (arr[low] == arr[high]) {
            if (arr[low] == x)
                return low;
            return -1;
        }

        long long pos = low + (long long)(x - arr[low]) * (high - low) /
                        (arr[high] - arr[low]);

        if (arr[pos] == x)
            return pos;
        else if (arr[pos] < x)
            low = pos + 1;
        else
            high = pos - 1;
    }

    return -1;
}

// compare_searches.c

// Binary search
int binary_search(int arr[], int n, int x) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x)
            return mid;
        else if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

// Από εδώ κάνεις include το άλλο αρχείο
int interpolation_search(int arr[], int n, int x);

int cmp(const void *a, const void *b) {
    int x = *(int*)a;
    int y = *(int*)b;
    return x - y;
}

int main() {
    int *arr = malloc(sizeof(int) * N);
    if (!arr) {
        printf("Memory error\n");
        return 1;
    }

    srand(time(NULL));

    // γέμισμα πίνακα
    for (int i = 0; i < N; i++)
        arr[i] = rand();

    // ταξινόμηση
    qsort(arr, N, sizeof(int), cmp);

    int target = arr[rand() % N];

    // Interpolation search timing
    clock_t start = clock();
    int pos1 = interpolation_search(arr, N, target);
    clock_t end = clock();
    double interp_time = (double)(end - start) / CLOCKS_PER_SEC;

    // Binary search timing
    start = clock();
    int pos2 = binary_search(arr, N, target);
    end = clock();
    double binary_time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Interpolation: %.6f sec, index=%d\n", interp_time, pos1);
    printf("Binary:        %.6f sec, index=%d\n", binary_time, pos2);

    free(arr);
    return 0;
}

// Βγαινει 0 τα Seconds γιατι η clock() δεν μετραει τα πολυ μικρα m/s