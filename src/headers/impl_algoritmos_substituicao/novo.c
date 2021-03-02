#include <stdlib.h>
#include <stdio.h>
#include "novo.h"
#include "../tabela_paginas.h"

// Variáveis da tabela de páginas utilizadas
extern unsigned paginasOcupadas;
extern EntradaTabela* tabelaPaginas;
extern unsigned* paginasNaMemoria;

// Tipo de dados auxiliar criado para ajudar na ordenação
typedef struct AuxPagina {
    unsigned tempo;
    unsigned identificador;
} AuxPagina;

// Comparador utilizado para a ordenação
// Ordena os elementos de acordo com o momento de entrada na memória
int comparacao (const void* p1, const void* p2) {
    return ((AuxPagina*)p1)->tempo - ((AuxPagina*)p2)->tempo;
}

// Algoritmo novo
// Dado um k aleatório, remove a k-esima pagina, numa ordenação crescente das páginas por tempo de entrada.
unsigned novo() {

    // Aloca o vetor das páginas na memória com as informações necessárias
    AuxPagina* auxPagina = (AuxPagina*) malloc(paginasOcupadas * sizeof(AuxPagina));

    if(auxPagina == NULL) {
        printf("Erro ao alocar o vetor de páginas para o algoritmo de substituicao\n");
        exit(-1);
    }

    // Preenche o vetor alocado
    for(unsigned I=0; I<paginasOcupadas; I++) {
        auxPagina[I].tempo = tabelaPaginas[paginasNaMemoria[I]].tempoEntrada;
        auxPagina[I].identificador = paginasNaMemoria[I];
    }

    // Ordena esse vetor pelo tempo de entrada
    qsort(auxPagina, paginasOcupadas, sizeof(AuxPagina), comparacao);

    // Sorteia um número k aleatório 
    unsigned k = rand() % paginasOcupadas;
    
    // Retorna o k-esimo elemento do vetor ordenado por tempo de entrada
    unsigned retorno = auxPagina[k].identificador;

    // Desaloca a memória alocada
    free(auxPagina);

    return retorno;
}