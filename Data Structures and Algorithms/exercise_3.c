#include <stdio.h>
#include <stdlib.h>

int main() {
    float a, b, result;
    char operation;
    int sum = 0;

    // Check if the program have to terminate
    printf("Enter a, b and operation (+ or - or * or /): ");
    scanf("%f %f %c", &a, &b, &operation);

    while (operation != '$') {
        // Check whether operation is invalid (e.g. devision by 0.0).
        if (operation == '/' && b == 0.0) {
            printf("Error: Cannot divide by 0.0. Operation has failed.");
            return -1;
        }

        if (operation == '+') {
            result = a + b;
        }
        else if (operation == '-') {
            result = a - b;
        }
        else if (operation == '*') {
            result = a * b;
        }
        else {
            // Operation should be /, otherwise it's an undefined operation.
            if (operation != '/') {
                printf("Error: undefined operation: %c", operation);
                return -1;
            }

            result = a / b;
        }

        printf("Success! Result of %.2f %c %.2f = %.2f\n\n", a, operation, b, result);

        system("pause");
        system("cls");
        
        // Increment the sum of calculations
        sum++;

        printf("Enter a, b and operation (+ or - or * or /): ");
        scanf("%f %f %c", &a, &b, &operation);
    }
    
        system("cls");
        printf("Calculated %d operations!", sum);

        return 0;
}