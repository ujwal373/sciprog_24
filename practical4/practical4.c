#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

double degrees_to_radians(int degrees) {
    return degrees * (PI / 180.0);
}

int main() {
    int N = 13; // From 0 to 60 degrees in steps of 5 -> 13 values
    double tan_values[N];

    // Calculate tan(x) for every 5 degrees from 0 to 60 degrees
    for (int i = 0; i <= 12; i++) {
        int degrees = i * 5; // Degrees
        double radians = degrees_to_radians(degrees); // Convert to radians
        tan_values[i] = tan(radians); // Compute tan(x)
        printf("tan(%d degrees) = %lf\n", degrees, tan_values[i]);
    }

    return 0;
}
