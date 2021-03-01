#include <stdlib.h>
#include "novo.h"
#include "../tabela_paginas.h"

// Variáveis da tabela de páginas utilizadas
extern unsigned paginasOcupadas;
extern unsigned* paginasNaMemoria;

typedef struct AuxPagina {
    unsigned tempo;
    unsigned endereco;
} AuxPagina;

int comp (const void* p1, const void* p2) {
    return ((AuxPagina*)p1)->tempo - ((AuxPagina*)p2)->tempo;
}

// Algoritmo novo
// Remove as páginas aleatoriamente
unsigned novo() {

    AuxPagina* aux_pagina = (AuxPagina*) malloc(paginasOcupadas * sizeof(AuxPagina));

    // Preenche o vetor alocado
    for(unsigned I=0; I<paginasOcupadas; I++) {
        aux_pagina[I].tempo = tabelaPaginas[paginasNaMemoria[I]].tempoEntrada;
        aux_pagina[I].endereco = paginasNaMemoria[I];
    }

    // Sorteia um índice ocupado da memória e remove a página presente nesse índice
    qsort(aux_pagina, paginasOcupadas, sizeof(unsigned), comp);
    unsigned k = rand() % paginasOcupadas;
    return aux_pagina[k].endereco;
}