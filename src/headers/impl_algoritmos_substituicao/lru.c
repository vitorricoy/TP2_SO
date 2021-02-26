#include <stdlib.h>
#include "lru.h"
#include "../tabela_paginas.h"

extern unsigned paginasOcupadas;
extern EntradaTabela* tabelaPaginas;
extern unsigned* paginasNaMemoria;

unsigned LRU() {
    unsigned ultimo, tempoUltimo;
    ultimo = paginasNaMemoria[0];
    tempoUltimo = tabelaPaginas[paginasNaMemoria[0]].ultimoAcesso;
    for(unsigned I=1; I<paginasOcupadas; I++) {
        if(tabelaPaginas[paginasNaMemoria[I]].ultimoAcesso < tempoUltimo){
            ultimo = paginasNaMemoria[I];
            tempoUltimo = tabelaPaginas[paginasNaMemoria[I]].ultimoAcesso;
        }
    }
    return ultimo;
}