#include <windows.h>
#include <assert.h>
#include <omp.h>
#include <stdio.h>
#include <vector>

int main() {
    std::vector<int> data1(5), data2(5);

    #pragma omp parallel
    {
        #pragma omp for nowait // Sem barreira aqui
        for (int i = 0; i < data1.size(); ++i) {
            data1[i] = i * 2; // Processamento da primeira parte dos dados
        }

        // As threads podem começar a trabalhar em data2 imediatamente
        #pragma omp for
        for (int i = 0; i < data2.size(); ++i) {
            data2[i] = i * 3; // Processamento da segunda parte dos dados
        }
    }

    return 0;
}
