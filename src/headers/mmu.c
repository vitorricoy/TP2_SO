#include <stdlib.h>
#include "mmu.h"
#include "entrada_tabela.h"
#include "tabela_paginas.h"
#include "algoritmo_substituicao.h"

unsigned numeroPaginasSujas;

short MMU_lerEndereco(unsigned endereco) {
    if(TabelaPaginas_enderecoEstaValido(endereco)) {
        TabelaPaginas_atualizarUltimoAcesso(endereco);
        return 0;
    } else {
        MMU_buscaPaginaParaMemoria(endereco);
        return 1;
    }
}

short MMU_escreverEndereco(unsigned endereco) {
    if(TabelaPaginas_enderecoEstaValido(endereco)) {
        TabelaPaginas_atualizarUltimoAcesso(endereco);
        TabelaPaginas_setEnderecoSujo(endereco, 1);
        return 0;
    } else {
        MMU_buscaPaginaParaMemoria(endereco);
        return 1;
    }
}

void MMU_buscaPaginaParaMemoria(unsigned endereco) {
    short sucesso = TabelaPaginas_colocaPaginaMemoria(endereco);
    if(!sucesso) {
        unsigned enderecoRemovido = AlgoritmoSubstituicao_determinaPagina();
        if(TabelaPaginas_enderecoEstaSujo(enderecoRemovido)) {
            numeroPaginasSujas++;
        }
        TabelaPaginas_substituiPaginasMemoria(endereco, enderecoRemovido);
    }
}