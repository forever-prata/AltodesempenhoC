#include <windows.h>
#include <assert.h>
#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_threads;
    // Pede o número de threads ao usuário
    printf("Digite o número de threads desejado: ");
    scanf("%d", &num_threads);
    // Configura o número de threads e inicializa o gerador de números aleatórios
    omp_set_num_threads(num_threads);
    srand(time(NULL));
    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        // Cada thread gera 10 números aleatórios
        for(int i = 0; i < 10; i++) {
            int num = rand() % 1001; // Gera número entre 0 e 1000
            printf("Thread %d gerou: %d\n", thread_id, num);
        }
    }
    return 0;
}


