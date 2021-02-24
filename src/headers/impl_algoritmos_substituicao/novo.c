#include <stdlib.h>
#include "novo.h"
#include "../tabela_paginas.h"

unsigned novo() {
    int indice = rand() % paginasOcupadas;
    int endereco = paginasNaMemoria[indice];
    return endereco;
}