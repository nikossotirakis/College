#include <stdio.h>
#include <string.h>

// Creating the Employee struct
typedef struct {
    char name[50];
    float salery;    
} Employee;

int main(void) {
    // Creating the Employee type array & getting the size of it from the user
    int arraySize = 0;

    printf("Enter the size of the array: ");
    scanf("%d", &arraySize);

    Employee employees[arraySize];

    // Getting input from the user for each element of the array
    for (int i = 0; i < arraySize; i++) {
        printf("Enter the name and salery of the %d employee: ", i + 1);
        scanf("%s %f", &employees[i].name, &employees[i].salery);
    }

    // Print the all the array elements
    for (int i = 0; i < arraySize; i++) {
        printf("Employee number %d: %s %.2f\n", i + 1, employees[i].name, employees[i].salery);
    }

    // Calculate the expanses of the company
    float totalExpanses = 0;

    for (int i = 0; i < arraySize; i++) {
        totalExpanses += employees[i].salery;
    }

    printf("The companies total expanses are: %.2f", totalExpanses);

    return 0;
}