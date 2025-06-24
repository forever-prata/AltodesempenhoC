#include <windows.h>
#include <assert.h>
#include <stdio.h>
#include <omp.h>

int main() {
    const int N = 1000;
    int vetor[N];
    int soma = 0;
    for (int i = 0; i < N; i++) {
        vetor[i] = i + 1;
    }
    #pragma omp parallel for reduction(+:soma)
    for (int i = 0; i < N; i++) {
        soma += vetor[i];
    }
    printf("Soma total = %d\n", soma);
    return 0;
}
