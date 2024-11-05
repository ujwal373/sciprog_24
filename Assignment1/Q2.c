#include <stdio.h>

#define SIZE 4

// Function to calculate determinant of a 3x3 matrix
double getDet3x3(double minor[3][3]) {
    return minor[0][0] * (minor[1][1] * minor[2][2] - minor[1][2] * minor[2][1])
         - minor[0][1] * (minor[1][0] * minor[2][2] - minor[1][2] * minor[2][0])
         + minor[0][2] * (minor[1][0] * minor[2][1] - minor[1][1] * minor[2][0]);
}

// Function to create a 3x3 minor by removing row 0 and column k
void createMinor(double src[4][4], double dest[3][3], int colToSkip) {
    int row = 0, col = 0;
    for (int i = 1; i < SIZE; i++) { // Start from row 1
        col = 0;
        for (int j = 0; j < SIZE; j++) {
            if (j == colToSkip) continue; // Skip the specified column
            dest[row][col] = src[i][j];
            col++;
        }
        row++;
    }
}

int main() {
    double hmat[SIZE][SIZE];
    double minor[3][3];
    double determinant = 0.0;

    // Initialize Hilbert matrix
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            hmat[i][j] = 1.0 / (i + j + 1);
        }
    }

    // Print Hilbert Matrix
    printf("4x4 Hilbert Matrix:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%.10f\t", hmat[i][j]);
        }
        printf("\n");
    }

    // Calculate determinant using Cramer's rule, expanding along the first row
    for (int k = 0; k < SIZE; k++) {
        createMinor(hmat, minor, k);
        double cofactor = ((k % 2 == 0) ? 1 : -1) * hmat[0][k] * getDet3x3(minor);
        determinant += cofactor;
    }

    // Print the determinant
    printf("\nDeterminant of the 4x4 Hilbert Matrix: %.16f\n", determinant);

    return 0;
}
