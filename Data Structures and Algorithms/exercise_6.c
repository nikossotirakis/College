#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    int years = 0;

    printf("Enter the amount of years: ");
    scanf("%d", &years);

    int sales[years][12][5];

    // Setting up the seed for pseudo-random numbers
    srand(time(NULL));

    // Initialise array
    for (int i = 0; i < years; i++) {
        for (int j = 0; j < 12; j++) {
            for (int k = 0; k < 5; k++) {
                sales[i][j][k] = rand() % 990001 + 10000;
            }
        } 
    }

    // Calculate avarage
    int marketAverage[5] = {0}; 

    for (int i = 0; i < years; i++) {       
        for (int j = 0; j < 12; j++) {     
            for (int k = 0; k < 5; k++) {    
                marketAverage[k] += sales[i][j][k]; 
            }
        }
    }

    // Finding the largest element of the array
    int maxSalesMarket = marketAverage[0];

    for (int i = 1; i < 5; i++) {
        if (marketAverage[i] > maxSalesMarket) {
            maxSalesMarket = marketAverage[i];
        }
    }


    // Calculate the most profitable month
    int bestMonth = 0;
    int maxSales = -1;

    for (int j = 0; j < 12; j++) {        
        int monthSum = 0;
        for (int i = 0; i < 2; i++) {     
            for (int k = 0; k < 5; k++) { 
                monthSum += sales[i][j][k];
            }
        }

        if (monthSum > maxSales) {
            maxSales = monthSum;
            bestMonth = j;  
        }
    }


    return 0;
}