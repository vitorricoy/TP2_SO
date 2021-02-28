#ifndef TP2_SO_SRC_HEADERS_ALGORITMO_SUBSTITUICAO_H
#define TP2_SO_SRC_HEADERS_ALGORITMO_SUBSTITUICAO_H

#include "entrada_tabela.h"
#include "tabela_paginas.h"

// Inicializa a variável que guarda qual o algoritmo de substituição escolhido
void algoritmoSubstituicao_inicializar(char* algoritmoSubstituicao);

// Determina a página que deve ser removida de acordo com o algoritmo escolhido
unsigned AlgoritmoSubstituicao_determinaPagina();

#endif //TP2_SO_SRC_HEADERS_ALGORITMO_SUBSTITUICAO_H