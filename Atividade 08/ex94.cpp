#include <windows.h>
#include <assert.h>
#include <omp.h>
#include <stdio.h>
#include <vector>

int main() {
    #pragma omp parallel
    {
        #pragma omp for nowait // Sem barreira no loop externo
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) { // Loop interno
                // ... algum trabalho ...
            }
        }

        // As threads continuam aqui sem esperar pelo loop externo
        #pragma omp single
        {
            printf("Loops concluídos!\n");
        }
    }
    return 0;
}

