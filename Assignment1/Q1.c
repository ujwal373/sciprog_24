// Complete the inclusion of necessary libraries
#include <stdio.h>
#include <math.h>

int main() {

    // Complete variable declarations
    int n, i;
    float sum_x = 0, sum_y = 0, sum_xy = 0, sum_x2 = 0, alpha, beta, denominator;

    // Enter the number of data points
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    float x[n], y[n];

    // Enter (xi, yi) values i=1, 2, ..., n
    // Note that C array indices start from 0
    printf("Enter the x and y values:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d]: ", i);
        scanf("%f", &x[i]);
        printf("y[%d]: ", i);
        scanf("%f", &y[i]);

        sum_x += x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        sum_x2 += pow(x[i], 2);
    }
    
    denominator = (n * sum_x2 - pow(sum_x, 2));
    if (denominator == 0) {
        printf("Error: Denominator is zero, cannot calculate alpha.\n");
        return 1;
    }

    alpha = (n * sum_xy - sum_x * sum_y) / denominator;
    beta = (sum_y - alpha * sum_x) / n;

    // Print the equation of the line
    printf("The equation of the line is: y = %.2fx + %.2f\n", alpha, beta);

    return 0;
}
