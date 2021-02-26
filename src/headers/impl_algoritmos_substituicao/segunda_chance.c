#include <stdlib.h>
#include "segunda_chance.h"
#include "../tabela_paginas.h"

extern unsigned paginasOcupadas;
extern EntradaTabela* tabelaPaginas;
extern unsigned* paginasNaMemoria;

typedef struct AuxPagina {
    unsigned tempo;
    short referencia;
    unsigned endereco;
}AuxPagina;

int comp (const void* p1, const void* p2) {
    return ((AuxPagina*)p1)->tempo - ((AuxPagina*)p2)->tempo;
}

unsigned segundaChance() {
    AuxPagina* pagina;
    pagina = (AuxPagina*) malloc(paginasOcupadas * sizeof(AuxPagina));
    for(unsigned I=0; I<paginasOcupadas; I++) {
        pagina[I].tempo = tabelaPaginas[paginasNaMemoria[I]].tempoEntrada;
        pagina[I].referencia = tabelaPaginas[paginasNaMemoria[I]].segundaChance;
        pagina[I].endereco = paginasNaMemoria[I];
    }

    qsort(pagina, paginasOcupadas, sizeof(AuxPagina), comp);

    unsigned posicao = 0;
    while(pagina[posicao].referencia) {
        tabelaPaginas[pagina[posicao].endereco].segundaChance = 0;
        pagina[posicao].referencia = 0;
        posicao = (posicao + 1) % paginasOcupadas;
    }

    return pagina[posicao].endereco;

}