#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "headers/mmu.h"
#include "headers/algoritmo_substituicao.h"
#include "headers/impl_algoritmos_substituicao/fifo.h"
#include "headers/impl_algoritmos_substituicao/lru.h"
#include "headers/impl_algoritmos_substituicao/novo.h"
#include "headers/impl_algoritmos_substituicao/segunda_chance.h"


int main(int argc, char** argv) {
    if(argc != 5 && argc != 6) {
        printf("Argumentos incorretos.");
        return 0;
    }
    char* algoritmoSubstituicao = argv[1];
    char* arquivoEntrada = argv[2];
    unsigned tamanhoPagina = strtoul(argv[3], NULL, 10);
    unsigned tamanhoMemoria = strtoul(argv[4], NULL, 10);
    unsigned debug = 0;
    if(argc == 5) {
        debug = strtoul(argv[5], NULL, 10);
    }

    unsigned bitsPagina = 0, temp = tamanhoPagina;
    while (temp > 1) {
        temp = temp >> 1;
        bitsPagina++;
    }

    FILE* arquivo = fopen(arquivoEntrada, "r");

    unsigned numeroLinhas = 0;

    for(char c = getc(arquivo); c != EOF; c = getc(arquivo)) {
        if(c == '\n') {
            numeroLinhas++;
        }
    }

    fclose(arquivo);

    unsigned numeroPaginas = (1 << (32-bitsPagina));

    if(debug == 2) { // Imprime a tabela por cada iteração
        long long custoIteracoes = numeroPaginas * numeroLinhas;
        if(custoIteracoes > 1e8) {
            printf("Arquivo de entrada ou numero de paginas muito grandes para executarem o debug detalhado em tempo habil\n");
            return 0;
        }
    }

    MemoriaFisica memoria(tamanhoMemoria, tamanhoPagina, numeroPaginas, debug);

    AlgoritmoSubstituicao* algoritmoSub;

    if(strcmp(algoritmoSubstituicao, "lru")) {
        algoritmoSub = new LRU(&memoria);
    }
    
    if(strcmp(algoritmoSubstituicao, "2a")) {
        algoritmoSub = new SegundaChance(&memoria);
    }
    
    if(strcmp(algoritmoSubstituicao, "fifo")) {
        algoritmoSub = new FIFO(&memoria);
    }
    
    if(strcmp(algoritmoSubstituicao, "novo")) {
        algoritmoSub = new Novo(&memoria);
    }

    unsigned contadorPaginasSujas = 0;

    MMU gerenciadorMemoria(&memoria, &contadorPaginasSujas, algoritmoSub, debug);

    unsigned endereco;
    char rw;

    unsigned contadorLeituras = 0;
    unsigned contadorEscritas = 0;
    unsigned contadorPageFaults = 0;

    printf("Executando o simulador...\n");
     
    clock_t inicio = clock();

    char** printsTabelas;
    unsigned numeroPrintsTabelas = 2;
    if(debug == 2) {
        numeroPrintsTabelas = numeroLinhas+1;
    }
    printsTabelas = (char**) malloc(numeroPrintsTabelas*sizeof(char*));
    for(unsigned I=0; I<numeroPrintsTabelas; I++) {
        // Cada linha da tabela tem 50 caracteres e tem o \0 no fim
        printsTabelas[I] = (char*) malloc(50*(numeroLinhas+1)*sizeof(char) + sizeof(char));
    }
    
    arquivo = fopen(arquivoEntrada, "r");

    memoria.preencherStringTabelaPaginas(printsTabelas[0]);

    unsigned cont = 1;

    while(fscanf(arquivo, "%x %c", &endereco, &rw) != EOF) {
        //Tratar ação
        bool pageFault = false;
        if(rw == 'R') { 
            contadorLeituras++;
            pageFault = gerenciadorMemoria.lerEndereco((endereco >> bitsPagina));
        } else {
            contadorEscritas++;
            pageFault = gerenciadorMemoria.escreverEndereco((endereco >> bitsPagina));
        }
        if(pageFault) {
            contadorPageFaults++;
        }
        if(debug == 2) {
            memoria.preencherStringTabelaPaginas(printsTabelas[cont++]);
        }
    }

    memoria.preencherStringTabelaPaginas(printsTabelas[cont]);

    clock_t fim = clock();
    double tempoGasto = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

    printf("Arquivo de Entrada: %s\n", arquivoEntrada);
    printf("Tamanho da Memoria: %u KB\n", tamanhoMemoria);
    printf("Tamanho das paginas: %u KB\n", tamanhoPagina);
    printf("Tecnica de reposicao: %s\n", algoritmoSubstituicao);
    printf("Paginas lidas: %u\n", contadorLeituras);
    printf("Paginas escritas: %u\n", contadorEscritas);
    printf("Paginas sujas: %u\n", contadorPaginasSujas);
    printf("Tempo de Execucao: %lf\n", tempoGasto);
    printf("Tabelas:\n\n");
    printf("Tabela Inicio:\n");
    printf("%s\n", printsTabelas[0]);
    if(debug == 2) {
        for(unsigned I=1; I<numeroLinhas; I++) {
            printf("Tabela após passo %d:\n", I);
            printf("%s\n", printsTabelas[I]);
        }
    }
    printf("Tabela Fim:\n");
    printf("%s", printsTabelas[cont]);

    for(unsigned I=0; I<numeroPrintsTabelas; I++) {
        free(printsTabelas[I]);
    }
    free(printsTabelas);
    return 0;
}