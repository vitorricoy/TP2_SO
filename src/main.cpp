#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tabela_paginas.h"
#include "algoritmo_substituicao.h"
#include "fifo.h"
#include "lru.h"
#include "novo.h"
#include "segunda_chance.h"


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

    unsigned endereco;
    char rw;

    AlgoritmoSubstituicao* algoritmoSub;

    if(strcmp(algoritmoSubstituicao, "lru")) {
        algoritmoSub = new LRU();
    }
    
    if(strcmp(algoritmoSubstituicao, "2a")) {
        algoritmoSub = new SegundaChance();
    }
    
    if(strcmp(algoritmoSubstituicao, "fifo")) {
        algoritmoSub = new FIFO();
    }
    
    if(strcmp(algoritmoSubstituicao, "novo")) {
        algoritmoSub = new Novo();
    }

    TabelaPaginas tabela(tamanhoPagina, tamanhoMemoria, algoritmoSub, debug);

    while(fscanf(arquivo, "%x %c", &endereco, &rw) != EOF) {
        unsigned s = 0, temp = tamanhoPagina;
        while (temp > 1) {
            temp = temp >> 1;
            s++;
        }
        //Tratar ação
        if(rw == 'R') { 
            tabela.lerEndereco(endereco >> s);
        } else {
            tabela.escreverEndereco(endereco >> s);
        }
    }

    return 0;
}