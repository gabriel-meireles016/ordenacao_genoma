// gcc -Iincludes src/sequencial.c src/funcoes.c -o codigo_sequencial
// ./codigo_sequencial testes/entradas/ex_minusculo.txt testes/saidas/sequencial/sequencial_minusculo.txt

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/funcoes.h"

#define MAX_SEQ_LENGTH 100
#define DNA_CHARS "ACGT"

int main(int argc, char *argv[]) {
    
    if (argc != 3) {
        printf("Erro de comando.");
        return 1;
    }
    
    char* arq_entrada = argv[1];
    char* arq_saida = argv[2];

    // Leitura de Arquivo
    int total_seqs;
    char** dna_sequencias = ler_arquivo(arq_entrada, &total_seqs);
    
    clock_t ini = clock();

    sequential_sort(dna_sequencias, total_seqs);

    clock_t fim = clock();

    double tempo_execucao = ((double)(fim - ini)) / CLOCKS_PER_SEC;
    printf("Tempo de execução do qsort(): %.4f segundos.\n", tempo_execucao);

    // Arquivo de saída

    escrever_arquivo(arq_saida, dna_sequencias, total_seqs);

    free(dna_sequencias);
    return 0;
}
