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
    if(argc != 4 && argc != 5) {
        printf("Argumentos incorretos.");
        return 0;
    }
    char* algoritmoSubstituicao = argv[1];
    char* arquivoEntrada = argv[2];
    unsigned tamanhoPagina = atoi(argv[3]);
    unsigned tamanhoMemoria = atoi(argv[4]);
    bool debug = argc == 5;
    
    FILE* arquivo = fopen(arquivoEntrada, "r");

    unsigned bitsPagina = 0, temp = tamanhoPagina;
    while (temp > 1) {
        temp = temp >> 1;
        bitsPagina++;
    }
    unsigned numeroPaginas = (1 << (32-bitsPagina));

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
    }

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
    printf("Tabela:\n");
    //Ver como seria a tabela
    return 0;
}