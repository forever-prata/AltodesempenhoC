#include <assert.h>
#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <time.h>
#include <random>
#include <iostream>

int main() {
    int num_threads, inicio, fim;
    // Pede os valores ao usuário
    std::cout << "Digite o número de threads desejado: ";
    std::cin >> num_threads;
    std::cout << "Digite o valor inicial do intervalo: ";
    std::cin >> inicio;
    std::cout << "Digite o valor final do intervalo: ";
    std::cin >> fim;
    // Verifica se o intervalo é válido
    if(fim <= inicio) {
        std::cerr << "Erro: O valor final deve ser maior que o inicial!\n";
        return 1;
    }
    // Configura o número de threads e inicializa o gerador de números aleatórios
    omp_set_num_threads(num_threads);

    long long total_sum = 0; // Use long long to avoid potential overflow

    #pragma omp parallel reduction(+:total_sum)
    {
        int thread_id = omp_get_thread_num();
        static thread_local std::mt19937 generator(std::random_device{}());
        std::uniform_int_distribution<int> distribution(inicio, fim);

        int local_sum = 0; // Sum for this thread

        for (int i = 0; i < 10; i++) {
            int num = distribution(generator);
            printf("Thread %d gerou: %d\n", thread_id, num);
            local_sum += num;
        }
        total_sum += local_sum; // Add the local sum to the global sum
    }
    printf("Soma total de todos os números gerados: %lld\n", total_sum);
    return 0;
}