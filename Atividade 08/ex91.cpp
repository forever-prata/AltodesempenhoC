#include <windows.h>
#include <assert.h>
#include <stdio.h>
#include <omp.h>

int main() {
    int a = 5, b = 10; // Compartilhadas por padrão
    
    #pragma omp parallel default(shared) // Todas as variáveis são shared
    {
        a += omp_get_thread_num();
        b -= omp_get_thread_num();
        printf("Thread %d: a=%d, b=%d\n", omp_get_thread_num(), a, b);
    }
    
    printf("Valores finais: a=%d, b=%d\n", a, b);
    return 0;
}
