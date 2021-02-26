#include <stdlib.h>
#include <stdio.h>
#include "tabela_paginas.h"
#include "entrada_tabela.h"

unsigned tamanhoMemoria;
unsigned paginasOcupadas;
unsigned numeroPaginas;
EntradaTabela* tabelaPaginas;
unsigned* paginasNaMemoria;
unsigned contador;

void TabelaPaginas_inicializar(unsigned tamMem, unsigned tamPag, unsigned numPag){
    tamanhoMemoria = tamMem;
    tabelaPaginas = (EntradaTabela*) calloc(numPag, sizeof(EntradaTabela));
    paginasNaMemoria = (unsigned*) calloc((tamMem/tamPag), sizeof(unsigned));
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
    if(paginasOcupadas < numeroPaginas) {
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
    printf(string , "Pagina     Valido   Sujo   Tempo Entrada  Segunda Chance  Tempo do Ultimo Acesso\n");
    string  += sprintf(string , "Pagina     Valido   Sujo   Tempo Entrada  Segunda Chance  Tempo do Ultimo Acesso\n");
    for(unsigned I=0; I<numeroPaginas; I++) {
        string += sprintf(string, "0x%08x %hd        %hd      %-14u  %hd               %u\n", I, tabelaPaginas[I].valido, tabelaPaginas[I].sujo, tabelaPaginas[I].tempoEntrada, tabelaPaginas[I].segundaChance, tabelaPaginas[I].ultimoAcesso);
        printf(string, "0x%08x %hd        %hd      %-14u  %hd               %u\n", I, tabelaPaginas[I].valido, tabelaPaginas[I].sujo, tabelaPaginas[I].tempoEntrada, tabelaPaginas[I].segundaChance, tabelaPaginas[I].ultimoAcesso);
    }
}