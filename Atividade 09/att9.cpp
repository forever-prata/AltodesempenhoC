#include <windows.h>
#include <assert.h>
#include <stdio.h>
#include <omp.h>
#include <time.h>

int main() {
    const int TAMANHO = 10;
    int vetor[TAMANHO] = {5, 3, 7, 1, 9, 3, 6, 3, 8, 2};
    int valorBuscado = 13;
    int posEncontrada = -1;

    #pragma omp parallel shared(posEncontrada)
    {
        #pragma omp for
        for (int i = 0; i < TAMANHO; i++) {
            if (vetor[i] == valorBuscado) {
                #pragma omp critical
                {
                    if (posEncontrada == -1 || i < posEncontrada) {
                        posEncontrada = i;
                    }
                }
            }
        }
        #pragma omp single
        {
            if (posEncontrada != -1) {
                printf("Valor %d encontrado na posição %d\n", valorBuscado, posEncontrada);
            } else {
                printf("Valor %d não encontrado no vetor.\n", valorBuscado);
            }
        }
    }
    return 0;
}
