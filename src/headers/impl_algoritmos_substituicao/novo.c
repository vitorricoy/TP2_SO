#include <stdlib.h>
#include "novo.h"
#include "../tabela_paginas.h"

// Variáveis da tabela de páginas utilizadas
extern unsigned paginasOcupadas;
extern unsigned* paginasNaMemoria;

// Tipo de dados auxiliar criado para ajudar na ordenação
typedef struct AuxPagina {
    unsigned tempo;
    unsigned endereco;
} AuxPagina;

// Comparador utilizado para a ordenação
// Ordena os elementos de acordo com o momento de entrada na memória
int comparacao (const void* p1, const void* p2) {
    return ((AuxPagina*)p1)->tempo - ((AuxPagina*)p2)->tempo;
}

// Algoritmo novo
// Dado um k aleatório, remove a k-esima pagina, numa ordenação crescente das páginas por tempo de entrada.
unsigned novo() {

    AuxPagina* aux_pagina = (AuxPagina*) malloc(paginasOcupadas * sizeof(AuxPagina));

    // Preenche o vetor alocado
    for(unsigned I=0; I<paginasOcupadas; I++) {
        aux_pagina[I].tempo = tabelaPaginas[paginasNaMemoria[I]].tempoEntrada;
        aux_pagina[I].endereco = paginasNaMemoria[I];
    }

    // Ordena esse vetor pelo tempo de entrada
    qsort(aux_pagina, paginasOcupadas, sizeof(unsigned), comparacao);

    // Sorteia um número k aleatório 
    unsigned k = rand() % paginasOcupadas;

    // Retorna o k-esimo elemento do vetor ordenado por tempo de entrada
    return aux_pagina[k].endereco;
}