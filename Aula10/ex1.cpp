#include <windows.h>
#include <assert.h>
#include <stdio.h>
#include <time.h>
#include <omp.h>

int main (int argc , char *argv[]){
    const int N = 5; const int T = 20;
    int a[N]; int b[N];
    int aux_dot = 0; int dot = 0;
    srand (time(NULL));
    for (int x = 0; x < N; x++){
        a[x] = rand() % (T * 2);
        b[x] = rand() % (T * 2);
    }
    #pragma omp parallel private (aux_dot)
    {
    #pragma omp for
    for (int i = 0; i < N; i++){
        aux_dot += a[i]*b[i];
    }
    #pragma omp critical
    dot += aux_dot;    
    }
}