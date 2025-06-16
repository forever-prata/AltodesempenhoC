#include <windows.h>
#include <assert.h>
#include <stdio.h>
#include <omp.h>

int main() {
int x = 10; // Valor original
#pragma omp parallel firstprivate(x) // Cada thread recebe cópia de x iniciada com 10
{
    int thread_id = omp_get_thread_num();
    x += thread_id; // Modifica sua cópia privada
    printf("Thread %d: x = %d\n", thread_id, x);
}
// Fora do paralelo, x mantém valor original
printf("Fora da região paralela: x = %d\n", x);
return 0;
}