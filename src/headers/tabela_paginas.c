#include <stdlib.h>
#include <stdio.h>
#include "tabela_paginas.h"
#include "entrada_tabela.h"

unsigned numeroPaginasMemoria;
unsigned paginasOcupadas;
unsigned numeroPaginas;
EntradaTabela* tabelaPaginas;
unsigned* paginasNaMemoria;
unsigned contador;
unsigned numeroPaginasMemoria;

void TabelaPaginas_inicializar(unsigned tamMem, unsigned tamPag, unsigned numPag){
    numeroPaginasMemoria = (tamMem/tamPag);
    tabelaPaginas = (EntradaTabela*) malloc(numPag*sizeof(EntradaTabela));
    paginasNaMemoria = (unsigned*) malloc(numeroPaginasMemoria*sizeof(unsigned));
    numeroPaginas = numPag;
    paginasOcupadas = 0;
}

void TabelaPaginas_destruir() {
    free(tabelaPaginas);
    free(paginasNaMemoria);
}

short TabelaPaginas_enderecoEstaValido(unsigned endereco) {
    return tabelaPaginas[endereco].valido;
}

short TabelaPaginas_enderecoEstaSujo(unsigned endereco) {
    return tabelaPaginas[endereco].sujo;
}

void TabelaPaginas_setEnderecoValido(unsigned endereco, short valido) {
    tabelaPaginas[endereco].valido = valido;
}

short TabelaPaginas_colocaPaginaMemoria(unsigned endereco) {
    if(paginasOcupadas < numeroPaginasMemoria) {
        paginasNaMemoria[paginasOcupadas] = endereco;
        tabelaPaginas[endereco].posicaoMemoria = paginasOcupadas;
        paginasOcupadas++;
        tabelaPaginas[endereco].valido = 1;
        tabelaPaginas[endereco].sujo = 0;
        tabelaPaginas[endereco].tempoEntrada = contador;
        tabelaPaginas[endereco].ultimoAcesso = contador;
        tabelaPaginas[endereco].segundaChance = 1;
        return 1;
    }
    return 0;
}

void TabelaPaginas_substituiPaginasMemoria(unsigned endereco, unsigned enderecoRemovido) {
    tabelaPaginas[enderecoRemovido].valido = 0;
    paginasNaMemoria[tabelaPaginas[enderecoRemovido].posicaoMemoria] = endereco;
    tabelaPaginas[endereco].posicaoMemoria = tabelaPaginas[enderecoRemovido].posicaoMemoria;
    tabelaPaginas[endereco].valido = 1;
    tabelaPaginas[endereco].sujo = 0;
    tabelaPaginas[endereco].tempoEntrada = contador;
    tabelaPaginas[endereco].ultimoAcesso = contador;
    tabelaPaginas[endereco].segundaChance = 1;
}

void TabelaPaginas_setEnderecoSujo(unsigned endereco, short sujo) {
    tabelaPaginas[endereco].sujo = sujo;
}

void TabelaPaginas_atualizarUltimoAcesso(unsigned endereco) {
    tabelaPaginas[endereco].ultimoAcesso = contador;
}

void TabelaPaginas_preencherStringTabelaPaginas(char* string) {
    char* temp = string;
    int v = 0;
    v = sprintf(temp , "Pagina     Valido   Sujo   Tempo Entrada  Segunda Chance  Tempo do Ultimo Acesso\n");
    temp+=v;
    for(unsigned I=0; I<numeroPaginas; I++) {
        v = snprintf(temp, 91*sizeof(char), "0x%08x %hd        %hd      %-13u  %hd               %-10u\n", I, tabelaPaginas[I].valido, tabelaPaginas[I].sujo, tabelaPaginas[I].tempoEntrada, tabelaPaginas[I].segundaChance, tabelaPaginas[I].ultimoAcesso);
        temp+=v;
    }
}