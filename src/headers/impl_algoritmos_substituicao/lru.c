#include <stdlib.h>
#include "lru.h"
#include "../tabela_paginas.h"

// Variáveis da tabela de páginas utilizadas
extern unsigned paginasOcupadas;
extern EntradaTabela* tabelaPaginas;
extern unsigned* paginasNaMemoria;

// Remove a página usada menos recentemente
unsigned LRU() {

    // Inicialmente a primeira página da memória foi usada menos recentemente
    unsigned ultimo = paginasNaMemoria[0];
    unsigned tempoUltimo = tabelaPaginas[paginasNaMemoria[0]].ultimoAcesso;

    // Percorre a memória procurando a página com o momento de ultimo acesso menor
    for(unsigned I=1; I<paginasOcupadas; I++) {
        if(tabelaPaginas[paginasNaMemoria[I]].ultimoAcesso < tempoUltimo){
            ultimo = paginasNaMemoria[I];
            tempoUltimo = tabelaPaginas[paginasNaMemoria[I]].ultimoAcesso;
        }
    }

    // Retorna a página usada menos recentemente
    return ultimo;
}