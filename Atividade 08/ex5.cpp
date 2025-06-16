#include <windows.h>
#include <assert.h>
#include <stdio.h>
#include <omp.h>

int main() {
    int n = 1000;
    int num_threads;
    // Só executa paralelo se n for maior que 500
    #pragma omp parallel if(n > 500) private(num_threads)
    {
        num_threads = omp_get_num_threads();
        printf("Executando em paralelo com %d threads\n", num_threads);
    }
    n = 100;  // Altera valor de n
    // Agora executa sequencial (condição falsa)
    #pragma omp parallel if(n > 500) private(num_threads)
    {
        num_threads = omp_get_num_threads();
        printf("Executando sequencial (1 thread)\n");
    }
    
    return 0;
}
