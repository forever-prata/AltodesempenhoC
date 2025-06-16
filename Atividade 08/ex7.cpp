#include <assert.h>
#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <time.h>
#include <random>

int main() {
    int num_threads, inicio, fim;
    // Pede os valores ao usuário
    printf("Digite o número de threads desejado: ");
    scanf("%d", &num_threads);
    printf("Digite o valor inicial do intervalo: ");
    scanf("%d", &inicio);
    printf("Digite o valor final do intervalo: ");
    scanf("%d", &fim);
    // Verifica se o intervalo é válido
    if(fim <= inicio) {
        printf("Erro: O valor final deve ser maior que o inicial!\n");
        return 1;
    }
    // Configura o número de threads e inicializa o gerador de números aleatórios
    omp_set_num_threads(num_threads);
    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        static thread_local std::mt19937 generator(std::random_device{}());
        std::uniform_int_distribution<int> distribution(inicio, fim);

        for (int i = 0; i < 10; i++) {
            int num = distribution(generator);
            printf("Thread %d gerou: %d\n", thread_id, num);
        }
    }
    return 0;
}
