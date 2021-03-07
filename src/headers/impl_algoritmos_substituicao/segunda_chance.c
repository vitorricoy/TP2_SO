#include <stdlib.h>
#include <stdio.h>
#include "segunda_chance.h"
#include "../tabela_paginas.h"

// Variáveis da tabela de páginas utilizadas
extern unsigned paginasOcupadas;
extern EntradaTabela* tabelaPaginas;
extern unsigned* paginasNaMemoria;
extern unsigned contadorOperacoes;

// Tipo de dados auxiliar criado para ajudar na ordenação
typedef struct AuxPagina {
    unsigned tempo;
    short referencia;
    unsigned identificador;
} AuxPagina;

// Comparador utilizado para a ordenação
// Ordena os elementos de acordo com o momento de entrada na memória
int comp (const void* p1, const void* p2) {
    return ((AuxPagina*)p1)->tempo - ((AuxPagina*)p2)->tempo;
}

// Remove as páginas na ordem FIFO porém dá uma segunda chance às páginas que seriam removidas
unsigned segundaChance() {

    // Aloca o vetor das páginas na memória com as informações necessárias
    AuxPagina* vetorPaginas = (AuxPagina*) malloc(paginasOcupadas * sizeof(AuxPagina));

    if(vetorPaginas == NULL) {
        printf("Erro ao alocar o vetor de páginas para o algoritmo de segunda chance\n");
        exit(-1);
    }

    // Preenche o vetor alocado
    for(unsigned I=0; I<paginasOcupadas; I++) {
        vetorPaginas[I].tempo = tabelaPaginas[paginasNaMemoria[I]].tempoEntrada;
        vetorPaginas[I].referencia = tabelaPaginas[paginasNaMemoria[I]].segundaChance;
        vetorPaginas[I].identificador = paginasNaMemoria[I];
    }
    
    // Ordena esse vetor pelo tempo de entrada
    qsort(vetorPaginas, paginasOcupadas, sizeof(AuxPagina), comp);

    // Marca a flag de segunda chance dos elementos até remover algum deles
    unsigned posicao = 0;
    while(vetorPaginas[posicao].referencia) {

        // Marca a flag como usada em ambos arrays
        tabelaPaginas[vetorPaginas[posicao].identificador].segundaChance = 0;
        vetorPaginas[posicao].referencia = 0;

        // Atualiza o tempo de chegada as páginas que receberam a segunda chance
        tabelaPaginas[vetorPaginas[posicao].identificador].tempoEntrada = contadorOperacoes++;

        // Vai para a próxima posição de forma circular
        posicao = (posicao + 1) % paginasOcupadas;
    }

    // Retorna o identificador da primeira página com a flag zero na ordem de menor tempo de entrada
    unsigned retorno = vetorPaginas[posicao].identificador;
    
    // Desaloca a memória alocada
    free(vetorPaginas);

    return retorno;

}