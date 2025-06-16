#include <windows.h>
#include <assert.h>
#include <stdio.h>
#include <omp.h>

int main() {
    int x = 10; // Variável compartilhada inicial    
    #pragma omp parallel private(x) // x torna-se privada para cada thread
    {
        // x não está inicializada aqui (valor indefinido)
        int thread_id = omp_get_thread_num();
        x = thread_id * 2; // Cada thread atribui seu próprio valor        
        printf("Thread %d: x = %d\n", thread_id, x);
    }    
    // Fora da região paralela, x retorna ao seu valor original
    printf("Fora da região paralela: x = %d\n", x);    
    return 0;
}
