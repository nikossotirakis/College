#include <stdio.h>

int main() {
    int N;
    double lambda;

    // Ask for N
    printf("Enter N (1-9): ");
    scanf("%d", &N);

    // Validity check
    if (N <= 0 || N >= 10) {
        printf("Error: N must be between 1 and 9.\n");
        return 1;
    }

    // Create x array
    double x[N+1];
    printf("Enter %d elements of x:\n", N+1);
    for (int i = 0; i <= N; i++) {
        scanf("%lf", &x[i]);
    }

    // Ask for lambda
    printf("Enter lambda: ");
    scanf("%lf", &lambda);

    // Compute f(x)
    double sum = 0;
    for (int i = 0; i <= N; i++) {
        sum += x[i] + (i / (float)N); // i/N as float
    }

    double f = lambda * sum;
    printf("f(x) = %lf\n", f);

    return 0;
}
