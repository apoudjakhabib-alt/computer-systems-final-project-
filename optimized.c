#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5000

int main() {

    int **matrix;

    matrix = malloc(SIZE * sizeof(int *));

    for (int i = 0; i < SIZE; i++) {
        matrix[i] = malloc(SIZE * sizeof(int));
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matrix[i][j] = (i + j) % 100;
        }
    }

    long long sum = 0;

    clock_t start = clock();

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            sum += matrix[i][j];
        }
    }

    clock_t end = clock();

    double time_spent =
        (double)(end - start) / CLOCKS_PER_SEC;

    printf("Optimized (Row-Major)\n");
    printf("Sum = %lld\n", sum);
    printf("Time = %f seconds\n", time_spent);

    for (int i = 0; i < SIZE; i++) {
        free(matrix[i]);
    }

    free(matrix);

    return 0;
}