#include <windows.h>
#include <assert.h>
#include <stdio.h>
#include <omp.h>
#include <time.h>


int main() {
    const int LINHAS = 5;
    const int COLUNAS = 5;
    int matriz[LINHAS][COLUNAS];
    #pragma omp parallel
    {
        #pragma omp single
        {
            srand(time(NULL));
            printf("Gerador de números aleatórios inicializado pela thread %d\n", omp_get_thread_num());
        }
        #pragma omp for
        for (int i = 0; i < LINHAS; i++) {
            for (int j = 0; j < COLUNAS; j++) {
                matriz[i][j] = rand() % 100;
            }
        }
    }
    printf("Matriz gerada:\n");
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            printf("%3d ", matriz[i][j]);
        }
        printf("\n");
    }
    return 0;
}

