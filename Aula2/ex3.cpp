#include <windows.h>
#include <assert.h>
#include <stdio.h>
#include <omp.h>
#include <time.h>

int main(int argc, char *argv[]){
    const int TAM = 100000;
    float A[TAM];
    float B[TAM];
    float C[TAM];

    for (int x = 0; x < TAM; x++){
        A[x] = rand() % (TAM * 2);
        B[x] = rand() % (TAM * 2);
    }
    omp_set_num_threads(128);
    #pragma omp parallel for
    for (int x = 0; x < 2048; x++){
        C[x] = A[x] + B[x];
    }
    for (int x = 0; x < 2048; x++){
        printf ("C[%d] = %f\n",x,C[x]);
    }
    return 0;

}