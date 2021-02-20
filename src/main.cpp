#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    MMU gerenciadorMemoria(&memoria, algoritmoSub, debug);

    unsigned endereco;
    char rw;

    while(fscanf(arquivo, "%x %c", &endereco, &rw) != EOF) {
        
        //Tratar ação
        if(rw == 'R') { 
            gerenciadorMemoria.lerEndereco((endereco >> bitsPagina));
        } else {
            gerenciadorMemoria.escreverEndereco((endereco >> bitsPagina));
        }
    }

    return 0;
}