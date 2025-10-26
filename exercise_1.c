#include <stdio.h>
#include <stdlib.h>

// This exercise contains all a, b, c and d questions in once.
// We didn't use any constant due to the fact that there wasnt any good case for it (We can use them though with the #define ot const keyword).

int main(void) {
    float income = -1.0, total = 0.0;
    int tax = 0, month = 0;
     
    // Making sure input is valid
    while (income < 0) {
        printf("Enter your income: ");
        scanf("%f", &income);
    }

    // Double check for valid input and finding the tax
    if (income < 0) {
        printf("Program terminating due to invalid input.");
        return 1;
    } 
    else if (income < 10000) {
        tax = 9;
    }
    else if (income < 20000) {
        tax = 22;
    }
    else if (income < 40000) {
        tax = 30;
    }
    else {
        tax = 50;
    }

    // Finding the month of payment
    printf("Enter the month of payment of the tax (4-12): ");
    scanf("%d", &month);

    // Calculating tax based on discount/penalty
    if (month < 5) {
        total = income * (float)tax / 100 - ((income * (float)tax / 100) * 0.1);
    } 
    else if (month > 6) {
        total = income * (float)tax / 100 + ((income * (float)tax / 100) * 0.05);
    }
    else {
        total = income * tax / 100;
    }

    printf("Your tax is: %.2f", total);

    return 0;
}