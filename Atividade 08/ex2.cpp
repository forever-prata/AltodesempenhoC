#include <windows.h>
#include <assert.h>
#include <stdio.h>
#include <omp.h>

int main() {
    int sum = 0; // Variável compartilhada
    #pragma omp parallel shared(sum) // sum é compartilhada entre threads
    {
        int thread_id = omp_get_thread_num();
        int local_contribution = (thread_id + 1) * 10;
        
        // Região crítica para evitar condições de corrida
        #pragma omp critical
        {
            sum += local_contribution; // Todas as threads atualizam a mesma variável
        } 
        printf("Thread %d contribuiu com %d\n", thread_id, local_contribution);
    }
    printf("Soma total: %d\n", sum); 
    return 0;
}
