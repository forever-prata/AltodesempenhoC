#include <windows.h>
#include <assert.h>
#include <stdio.h>
#include <omp.h>

int main() {
    int x = 100, y = 200;
    
    #pragma omp parallel default(none) shared(x) private(y) // Exige declaração explícita
    {
        y = omp_get_thread_num() * 10; // y é privado
        x += y; // x é compartilhado
        
        printf("Thread %d: x=%d, y=%d\n", omp_get_thread_num(), x, y);
    }
    
    printf("Valor final de x: %d\n", x); // y não é acessível aqui
    return 0;
}
