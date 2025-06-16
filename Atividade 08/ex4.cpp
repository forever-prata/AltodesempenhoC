#include <windows.h>
#include <assert.h>
#include <stdio.h>
#include <omp.h>

int main() {
int sum = 0; // Variável de resultado
#pragma omp parallel for reduction(+:sum) // Cada thread tem sua cópia de sum
for(int i = 1; i <= 100; i++) {
    sum += i; // Operação segura em cada thread
}
// Soma final combina resultados de todas threads
printf("Soma total: %d\n", sum);
return 0;
}