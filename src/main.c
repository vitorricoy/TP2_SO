#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "headers/mmu.h"
#include "headers/algoritmo_substituicao.h"
#include "headers/tabela_paginas.h"

// Variável global que representa o modo do programa
// 0 para modo sem debug e 1 para modo de debug
short debug;

// Variáveis globais declaradas em outros arquivos
extern unsigned contadorOperacoes;
extern unsigned numeroPaginasSujas;

int main(int argc, char** argv) {

    // Verifica se o programa foi iniciado com os argumentos corretos
    if(argc != 5 && argc != 6) {
        printf("Argumentos incorretos. Utilizar programa no formato ./tp2virtual <algoritmo> <arquivo_entrada> <tamanho_pagina> <tamanho_memoria> <debug (0 ou 1)>\n");
        return 0;
    }

    // Inicializa as variáveis de acordo com os argumentos recebidos
    char* algoritmoSubstituicao = argv[1];
    char* arquivoEntrada = argv[2];
    unsigned tamanhoPagina = strtoul(argv[3], NULL, 10)*1000; // Obtém o tamanho aproximado da página em bits
    unsigned tamanhoMemoria = strtoul(argv[4], NULL, 10)*1000; // Obtém o tamanho aproximado da memória em bits
    debug = 0;
    if(argc == 6) {
        debug = strtoul(argv[5], NULL, 10);
    }

    // Calcula o expoente da potência de dois correspondente ao tamanho da página fornecido
    unsigned bitsPagina = 0, temp = tamanhoPagina;
    while (temp >= 1) {
        temp = temp >> 1;
        bitsPagina++;
    }

    // Define a seed para o rand
    srand(time(NULL));

    // Calcula o número máximo de páginas do tamanho fornecido representáveis com 32 bits
    unsigned long long numeroPaginasCalculo = (1LL << (32LL - bitsPagina));
    unsigned numeroPaginas = numeroPaginasCalculo;

    // Inicializa as variáveis correspondentes à tabela de páginas
    TabelaPaginas_inicializar(tamanhoMemoria, tamanhoPagina, numeroPaginas);

    // Inicializa a variável do algoritmo de substituição que será utilizado
    algoritmoSubstituicao_inicializar(algoritmoSubstituicao);

    // Inicializa a estrutura que guarda a impressão inicial e final da tabela de páginas
    char** printsTabelas;

    printsTabelas = (char**) malloc(2*sizeof(char*));

    if(printsTabelas == NULL) {
        printf("Erro na alocacao de printsTabelas\n");
        return -1;
    }
    
    for(unsigned I=0; I<2; I++) {

        printsTabelas[I] = (char*) malloc(91*(numeroPaginas+1)*sizeof(char) + sizeof(char));

        if(printsTabelas[I] == NULL) {
            printf("Erro na alocacao da posicao %u de printsTabelas\n", I);
            return -1;
        }
    }
    
    // Preenche a string que representa a tabela de páginas inicial (vazia)
    TabelaPaginas_preencherStringTabelaPaginas(printsTabelas[0]);
    
    // Abre o arquivo que contém as operações de memória a serem realizadas
    FILE* arquivo = fopen(arquivoEntrada, "r");

    printf("Executando o simulador...\n");

    // Inicializa variáveis utilizadas no loop de processamento da entrada 
    unsigned endereco;
    char rw;
    unsigned contadorPageFaults = 0;

    // Registra o tempo no início da execução do programa
    clock_t inicio = clock();

    // Trata uma ação na memória lida da entrada
    int valScan = fscanf(arquivo, "%x %c\n", &endereco, &rw);

    while(valScan && valScan != EOF) {

        // Determina se houve um Page Fault
        short pageFault = 0;

        // Contador para controlar o número de operações executadas
        // Utilizado como um registro do tempo em que uma entrada foi inserida na memoria ou acessada
        contadorOperacoes++;
        
        // Determina o tipo de operação lida
        if(rw == 'R') { 
            // Operação de leitura
            pageFault = MMU_lerEndereco((endereco >> bitsPagina));
        } else {
            // Operação de escrita
            pageFault = MMU_escreverEndereco((endereco >> bitsPagina));
        }

        if(pageFault) { // Se ocorreu um Page Fault na operação
            contadorPageFaults++;
        }

        valScan = fscanf(arquivo, "%x %c\n", &endereco, &rw);
    }

    // Registra o tempo no fim da execução do programa
    clock_t fim = clock();

    // Fecha o arquivo de entrada
    fclose(arquivo);

    // Preenche a tabela no fim da execução do programa
    TabelaPaginas_preencherStringTabelaPaginas(printsTabelas[1]);

    // Calcula o tempo gasto para a execução do programa
    double tempoGasto = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

    // Imprime o relatório da execução
    printf("Arquivo de Entrada: %s\n", arquivoEntrada);
    printf("Tamanho da Memoria: %u KB\n", tamanhoMemoria/1000);
    printf("Tamanho das paginas: %u KB\n", tamanhoPagina/1000);
    printf("Tecnica de reposicao: %s\n", algoritmoSubstituicao);
    printf("Paginas lidas do disco: %u\n", contadorPageFaults);
    printf("Paginas escritas no disco: %u\n", numeroPaginasSujas);
    printf("Tempo de Execucao: %lf\n", tempoGasto);
    printf("Tabelas:\n\n");
    printf("Tabela Inicio:\n");
    //printf("%s\n", printsTabelas[0]);
    printf("Tabela Fim:\n");
    //printf("%s", printsTabelas[1]);

    // Libera as memórias alocadas dinamicamente
    for(unsigned I=0; I<2; I++) {
        free(printsTabelas[I]);
    }
    free(printsTabelas);
    TabelaPaginas_destruir();
    return 0;
}