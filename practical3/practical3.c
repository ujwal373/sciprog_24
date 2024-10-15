#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846

double trapezoidal_rule(double (*f)(double), double a, double b, int N) {
    double h = (b - a) / N;
    double sum = 0.5 * (f(a) + f(b)); // Initial sum (first and last terms)

    for (int i = 1; i < N; i++) {
        double x = a + i * h;
        sum += f(x); // Add 2*f(x_i) in the formula
    }

    return sum * h;
}

double func(double x) {
    return tan(x); // Define the function tan(x)
}

int main() {
    double a = 0;
    double b = M_PI / 3;
    int N = 12; // 12 intervals

    double result = trapezoidal_rule(func, a, b, N);
    printf("Approximation of integral: %lf\n", result);
    printf("Expected value: %lf\n", log(2)); // Compare with log(2)
    
    return 0;
}