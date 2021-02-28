#include <stdlib.h>
#include "novo.h"
#include "../tabela_paginas.h"

// Variáveis da tabela de páginas utilizadas
extern unsigned paginasOcupadas;
extern unsigned* paginasNaMemoria;

// Algoritmo novo
// Remove as páginas aleatoriamente
unsigned novo() {
    
    // Sorteia um índice ocupado da memória e remove a página presente nesse índice
    unsigned indice = rand() % paginasOcupadas;
    unsigned endereco = paginasNaMemoria[indice];
    return endereco;
}