#include <stdlib.h>
#include <stdio.h>
#include "tabela_paginas.h"
#include "entrada_tabela.h"

unsigned numeroPaginasMemoria; // Número de páginas que podem ser salvas na memória
unsigned paginasOcupadas = 0; // Número de páginas ocupadas na memória
unsigned numeroPaginas; // Número total de páginas do programa
EntradaTabela* tabelaPaginas; // Tabela de páginas com as informações lógicas de cada página
unsigned* paginasNaMemoria; // Tabela de páginas reversa com o identificador de cada página salva na memória
unsigned contadorOperacoes  = 0; // Contador das operações do programa utilizado como contador do tempo do programa

// Inicializa as variáveis relacionadas à tabela de páginas
void TabelaPaginas_inicializar(unsigned tamMem, unsigned tamPag, unsigned numPag) {

    // Número de páginas na memória de tamanho 'tamMem'
    numeroPaginasMemoria = (tamMem/tamPag);

    // Aloca a tabela de páginas
    tabelaPaginas = (EntradaTabela*) malloc(numPag*sizeof(EntradaTabela));

    if(tabelaPaginas == NULL) {
        printf("Erro na alocacao da tabela de paginas\n");
        exit(-1);
    }

    // Inicializa a tabela de páginas alocada
    for(unsigned I=0; I<numPag; I++) {
        tabelaPaginas[I].posicaoMemoria = 0;
        tabelaPaginas[I].segundaChance = 0;
        tabelaPaginas[I].sujo = 0;
        tabelaPaginas[I].tempoEntrada = 0;
        tabelaPaginas[I].ultimoAcesso = 0;
        tabelaPaginas[I].valido = 0;
    }

    // Aloca a tabela de páginas reversa que contém o identificador das páginas salvas em cada posição da memória
    paginasNaMemoria = (unsigned*) malloc(numeroPaginasMemoria*sizeof(unsigned));

    if(paginasNaMemoria == NULL) {
        printf("Erro na alocacao da tabela de paginas reversa\n");
        exit(-1);
    }

    // Inicializa a tabela de páginas reversa
    for(unsigned I=0; I<numeroPaginasMemoria; I++) {
        paginasNaMemoria[I] = 0;
    }

    // Salva o número de páginas
    numeroPaginas = numPag;
    
    // Inicializa as variáveis 'paginasOcupadas' e 'contadorOperacoes'
    paginasOcupadas = 0;
    contadorOperacoes = 0;
}

// Desaloca a memória alocada dinamicamente pela função de inicialização
void TabelaPaginas_destruir() {

    // Libera a memória alocada para os dois arrays
    free(tabelaPaginas);
    free(paginasNaMemoria);
}

// Determina se a página fornecida está na memória
short TabelaPaginas_paginaEstaValida(unsigned pagina) {
    return tabelaPaginas[pagina].valido;
}

// Determina se a página fornecida está suja
short TabelaPaginas_paginaEstaSuja(unsigned pagina) {
    return tabelaPaginas[pagina].sujo;
}

// Atribui o valor dado à flag de válido da página fornecida
void TabelaPaginas_setPaginaValido(unsigned pagina, short valido) {
    tabelaPaginas[pagina].valido = valido;
}

// Atribui o valor dado à flag de sujo do endereço fornecido
void TabelaPaginas_setPaginaSuja(unsigned pagina, short sujo) {
    tabelaPaginas[pagina].sujo = sujo;
}

// Coloca a página dada na memória, retornando 1 caso tenha sucesso e 0 caso contrário
short TabelaPaginas_colocaPaginaMemoria(unsigned pagina) {

    // Determina se a memória possui espaço para adicionar uma página
    if(paginasOcupadas < numeroPaginasMemoria) {

        // Adiciona a página dada por 'pagina' na memória
        paginasNaMemoria[paginasOcupadas] = pagina;
        tabelaPaginas[pagina].posicaoMemoria = paginasOcupadas;
        paginasOcupadas++;
        tabelaPaginas[pagina].valido = 1;
        tabelaPaginas[pagina].sujo = 0;
        tabelaPaginas[pagina].tempoEntrada = contadorOperacoes;
        tabelaPaginas[pagina].ultimoAcesso = contadorOperacoes;
        tabelaPaginas[pagina].segundaChance = 1;
        return 1;
    }
    return 0;
}

// Substitui a página dada por 'paginaRemovida' pela página dada por 'pagina' na memória
void TabelaPaginas_substituiPaginasMemoria(unsigned pagina, unsigned paginaRemovida) {

    // Remove a página dada por 'paginaRemovida' da memória
    tabelaPaginas[paginaRemovida].valido = 0;
    paginasNaMemoria[tabelaPaginas[paginaRemovida].posicaoMemoria] = pagina;

    // Adiciona a página dada por 'pagina' na memória
    tabelaPaginas[pagina].posicaoMemoria = tabelaPaginas[paginaRemovida].posicaoMemoria;
    tabelaPaginas[pagina].valido = 1;
    tabelaPaginas[pagina].sujo = 0;
    tabelaPaginas[pagina].tempoEntrada = contadorOperacoes;
    tabelaPaginas[pagina].ultimoAcesso = contadorOperacoes;
    tabelaPaginas[pagina].segundaChance = 1;
}

// Atualiza o momento do último acesso à página recebida
// e reinicia a flag de segunda chance
void TabelaPaginas_atualizarValoresPaginaAcessada(unsigned pagina) {
    tabelaPaginas[pagina].ultimoAcesso = contadorOperacoes;
    tabelaPaginas[pagina].segundaChance = 1;
}

// Preenche a string dada com a representação em string da tabela de páginas
void TabelaPaginas_preencherStringTabelaPaginas(char* string) {
    
    // Guarda a tabela de páginas formatada em 'string'
    char* temp = string;
    int v = 0;
    v = sprintf(temp , "Frame      Pagina     Valido   Sujo   Tempo Entrada  Segunda Chance  Tempo do Ultimo Acesso\n");
    temp+=v;
    for(unsigned I=0; I<paginasOcupadas; I++) {
        int idPagina = paginasNaMemoria[I];
        v = snprintf(temp, 101*sizeof(char), "0x%08x 0x%08x %hd        %hd      %-13u  %hd               %-10u\n", I, idPagina, tabelaPaginas[idPagina].valido, tabelaPaginas[idPagina].sujo, tabelaPaginas[idPagina].tempoEntrada, tabelaPaginas[idPagina].segundaChance, tabelaPaginas[idPagina].ultimoAcesso);
        temp+=v;
    }
}