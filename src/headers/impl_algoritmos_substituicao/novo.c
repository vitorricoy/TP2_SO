#include <stdlib.h>
#include "novo.h"
#include "../tabela_paginas.h"

extern unsigned paginasOcupadas;
extern unsigned* paginasNaMemoria;

unsigned novo() {
    unsigned indice = rand() % paginasOcupadas;
    unsigned endereco = paginasNaMemoria[indice];
    return endereco;
}