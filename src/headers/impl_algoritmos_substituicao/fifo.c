#include <stdlib.h>
#include "fifo.h"
#include "../tabela_paginas.h"

// Variáveis da tabela de páginas utilizadas
extern unsigned paginasOcupadas;
extern EntradaTabela* tabelaPaginas;
extern unsigned* paginasNaMemoria;

// Remove a página inserida primeiro
unsigned FIFO() {

    // Inicialmente a primeira página da memória é a inserida primeiro
    unsigned primeiro = paginasNaMemoria[0];
    unsigned tempoPrimeiro = tabelaPaginas[paginasNaMemoria[0]].tempoEntrada;

    // Percorre a memória procurando a página com o momento de inserção menor
    for(unsigned I=1; I<paginasOcupadas; I++) {
        if(tabelaPaginas[paginasNaMemoria[I]].tempoEntrada < tempoPrimeiro){
            primeiro = paginasNaMemoria[I];
            tempoPrimeiro = tabelaPaginas[paginasNaMemoria[I]].tempoEntrada;
        }
    }

    // Retorna a página com o menor tempo de entrada na memória
    return primeiro;
}