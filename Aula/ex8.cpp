#include <windows.h>
#include <assert.h>
#include <stdio.h>
#include <omp.h>

int main(int argc, char *argv[]){
    printf("Ola 1 - Fora da Região Paralela ... \n");
    int t = omp_get_max_threads();
    printf("T = %d \n",t);
    #pragma omp parallel if (t>=4)
    {
        int id = omp_get_thread_num();
        int nt = omp_get_num_threads();
        printf("Sou a thread %d de um total de %d \n",id,nt);
    }
    printf("Ola 2 - Fora da Região Paralela ... \n");
    return 0;
}