#include <windows.h>
#include <assert.h>
#include <stdio.h>
#include <omp.h>
#include <time.h>

int main() {
    const int TAMANHO = 5;
    int vetorSoma[TAMANHO] = {1, 2, 3, 4, 5};
    int vetorProduto[TAMANHO] = {1, 2, 3, 4, 5};
    int soma = 0;
    int produto = 1;

    #pragma omp parallel sections
    {
        #pragma omp section
        {
            for (int i = 0; i < TAMANHO; i++) {
                soma += vetorSoma[i];
            }
            printf("Soma dos elementos: %d (calculada pela thread %d)\n", soma, omp_get_thread_num());
        }
        #pragma omp section
        {
            for (int i = 0; i < TAMANHO; i++) {
                produto *= vetorProduto[i];
            }
            printf("Produto dos elementos: %d (calculado pela thread %d)\n", produto, omp_get_thread_num());
        }
    }
    return 0;
}