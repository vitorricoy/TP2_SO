#include <stdlib.h>
#include "fifo.h"
#include "../tabela_paginas.h"

extern unsigned paginasOcupadas;
extern EntradaTabela* tabelaPaginas;
extern unsigned* paginasNaMemoria;

unsigned FIFO() {
    unsigned primeiro, tempoPrimeiro;
    primeiro = paginasNaMemoria[0];
    tempoPrimeiro = tabelaPaginas[paginasNaMemoria[0]].tempoEntrada;
    for(unsigned I=1; I<paginasOcupadas; I++) {
        if(tabelaPaginas[paginasNaMemoria[I]].tempoEntrada < tempoPrimeiro){
            primeiro = paginasNaMemoria[I];
            tempoPrimeiro = tabelaPaginas[paginasNaMemoria[I]].tempoEntrada;
        }
    }
    return primeiro;
}