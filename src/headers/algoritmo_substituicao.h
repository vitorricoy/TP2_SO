#ifndef TP2_SO_SRC_HEADERS_ALGORITMO_SUBSTITUICAO_H
#define TP2_SO_SRC_HEADERS_ALGORITMO_SUBSTITUICAO_H

#include "entrada_tabela.h"
#include "tabela_paginas.h"

void algoritmoSubstituicao_inicializar(char* algoritmoSubstituicao);

EntradaTabela AlgoritmoSubstituicao_determinaPagina();

extern short debug;

extern char* algoritmoSubstituicao;

#endif //TP2_SO_SRC_HEADERS_ALGORITMO_SUBSTITUICAO_H