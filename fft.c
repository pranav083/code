#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "hpm.h"
#include "datasetFFT.h"

#define PI 3.14159265358979323846

// Structure to hold complex numbers
typedef struct {
    double real;
    double imag;
} Complex;

// Function to perform 1D FFT
void fft(Complex *x, int n) {
    if (n <= 1) return;

    // Divide: separate even and odd indices
    Complex *even = (Complex *)malloc(n / 2 * sizeof(Complex));
    Complex *odd = (Complex *)malloc(n / 2 * sizeof(Complex));
    for (int i = 0; i < n / 2; i++) {
        even[i] = x[i * 2];
        odd[i] = x[i * 2 + 1];
    }

    // Conquer: recursively call fft on both halves
    fft(even, n / 2);
    fft(odd, n / 2);

    // Combine
    for (int k = 0; k < n / 2; k++) {
        double t = -2 * PI * k / n;
        Complex exp = {cos(t), sin(t)};
        Complex temp = {exp.real * odd[k].real - exp.imag * odd[k].imag,
                        exp.real * odd[k].imag + exp.imag * odd[k].real};

        x[k].real = even[k].real + temp.real;
        x[k].imag = even[k].imag + temp.imag;
        x[k + n / 2].real = even[k].real - temp.real;
        x[k + n / 2].imag = even[k].imag - temp.imag;
    }

    free(even);
    free(odd);
}

// Function to perform 2D FFT
void fft2D(Complex **matrix, int rows, int cols) {
    // Perform FFT on each row
    for (int i = 0; i < rows; i++) {
        fft(matrix[i], cols);
    }

    // Perform FFT on each column
    Complex *column = (Complex *)malloc(rows * sizeof(Complex));
    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++) {
            column[i] = matrix[i][j];
        }
        fft(column, rows);
        for (int i = 0; i < rows; i++) {
            matrix[i][j] = column[i];
        }
    }
    free(column);
}

// Function to print 2D complex matrix
void printComplexMatrix(Complex **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%f + %fi\t", matrix[i][j].real, matrix[i][j].imag);
        }
        printf("\n");
    }
}

int main() {
    // Size of the dataset (must be a power of 2)
    int rows = 32;
    int cols = 32;

    // Generate a sample dataset using dataset.h
    unsigned char dataset[DATA_SIZE];
    generate_dataset(dataset, DATA_SIZE);
    hpm_init(); // Start performance monitoring
    // Populate the complex matrix with the generated dataset
    Complex **matrix = (Complex **)malloc(rows * sizeof(Complex *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (Complex *)malloc(cols * sizeof(Complex));
        for (int j = 0; j < cols; j++) {
            int index = (i * cols + j) % DATA_SIZE;
            matrix[i][j].real = dataset[index] / 255.0;  // Normalize the dataset values
            matrix[i][j].imag = 0;
        }
    }

    // Print input data
    // printf("Input Data:\n");
    // printComplexMatrix(matrix, rows, cols);

    // Perform 2D FFT
    fft2D(matrix, rows, cols);

    // Print output data
    // printf("\n2D FFT Output:\n");
    // printComplexMatrix(matrix, rows, cols);

    // Free allocated memory
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
    hpm_print(); // Print performance results
    return 0;
}
