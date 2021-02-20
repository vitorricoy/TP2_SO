#include <stdlib.h>
#include "tabela_paginas.h"
#include "entrada_tabela.h"
#include "memoria_fisica.h"

TabelaPaginas::TabelaPaginas(unsigned tamanhoPagina, unsigned numeroPaginas, MemoriaFisica* memoriaFisica, AlgoritmoSubstituicao* algoritmo, bool debug) {
    this->tamanhoPagina = tamanhoPagina;
    this->algoritmoSubstituicao = algoritmo;
    this->debug = debug;
    this->numeroPaginas = numeroPaginas;
    this->entradas = (EntradaTabela*) malloc(this->numeroPaginas * sizeof(EntradaTabela));
    this->memoriaFisica = memoriaFisica;
}

TabelaPaginas::~TabelaPaginas() {
    free(this->entradas);
}

bool TabelaPaginas::lerEndereco(unsigned endereco) {
    this->entradas[endereco];
}

bool TabelaPaginas::escreverEndereco(unsigned endereco) {

}