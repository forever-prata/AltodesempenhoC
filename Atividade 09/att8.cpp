#include <windows.h>
#include <assert.h>
#include <stdio.h>
#include <omp.h>
#include <time.h>

int main() {
    const int N = 4;
    int A[N][N] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    int B[N][N] = {
        {1, 2, 3, 4},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };
    int C[N][N] = {0};
    #pragma omp parallel
    {
        #pragma omp sections
        {
            #pragma omp section
            {
                for (int i = 0; i < 2; i++) { // linhas 0 e 1
                    for (int j = 0; j < N; j++) {
                        for (int k = 0; k < N; k++) {
                            C[i][j] += A[i][k] * B[k][j];
                        }
                    }
                }
            }
            #pragma omp section
            {
                for (int i = 2; i < 4; i++) { // linhas 2 e 3
                    for (int j = 0; j < N; j++) {
                        for (int k = 0; k < N; k++) {
                            C[i][j] += A[i][k] * B[k][j];
                        }
                    }
                }
            }
        }
    }
    printf("Matriz Resultado C:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%4d ", C[i][j]);
        }
        printf("\n");
    }
    return 0;
}
