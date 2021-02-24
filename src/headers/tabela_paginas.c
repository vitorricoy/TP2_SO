#include <stdlib.h>
#include <stdio.h>
#include "tabela_paginas.h"
#include "entrada_tabela.h"

unsigned tamanhoMemoria;
unsigned paginasOcupadas;
unsigned numeroPaginas;
EntradaTabela* tabelaPaginas;
unsigned* paginasNaMemoria;

void TabelaPaginas_inicializar(unsigned tamMem, unsigned tamPag, unsigned numPag, short dbg){
    tamanhoMemoria = tamMem;
    tabelaPaginas = (EntradaTabela*) malloc(numPag * sizeof(EntradaTabela));
    paginasNaMemoria = (unsigned*) malloc((tamMem/tamPag) * sizeof(unsigned));
    numeroPaginas = numPag;
    paginasOcupadas = 0;
    debug = dbg;
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
    if(paginasOcupadas < numeroPaginas) {
        paginasNaMemoria[paginasOcupadas] = endereco;
        tabelaPaginas[endereco].posicaoMemoria = paginasOcupadas;
        paginasOcupadas++;
        tabelaPaginas[endereco].valido = 1;
        tabelaPaginas[endereco].sujo = 0;
        tabelaPaginas[endereco].tempoEntrada = contador;
        tabelaPaginas[endereco].ultimoAcesso = contador;
    }
    return 0;
}

void TabelaPaginas_colocaPaginaMemoriaCheia(unsigned endereco, unsigned posicaoMemoria) {
    paginasNaMemoria[posicaoMemoria] = endereco;
    tabelaPaginas[endereco].valido = 1;
    tabelaPaginas[endereco].sujo = 0;
    tabelaPaginas[endereco].tempoEntrada = contador;
    tabelaPaginas[endereco].ultimoAcesso = contador;
}

void TabelaPaginas_setEnderecoSujo(unsigned endereco, short sujo) {
    tabelaPaginas[endereco].sujo = sujo;
}

void TabelaPaginas_atualizarUltimoAcesso(unsigned endereco) {
    tabelaPaginas[endereco].ultimoAcesso = contador;
}

void TabelaPaginas_preencherStringTabelaPaginas(char* string) {
    sprintf(string, "Pagina     Valido   Sujo   Tempo Entrada  Referencia  Tempo do Ultimo Acesso\n");
    for(unsigned I=0; I<numeroPaginas; I++) {
        sprintf(string+77*(I+1), "%#010x %d        %d      %-14d  %d           %d\n", I, tabelaPaginas[I].valido, tabelaPaginas[I].sujo, tabelaPaginas[I].tempoEntrada, tabelaPaginas[I].segundaChance, tabelaPaginas[I].ultimoAcesso);
    }
}