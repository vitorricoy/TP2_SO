#include <stdlib.h>
#include <stdio.h>
#include "mmu.h"
#include "entrada_tabela.h"
#include "tabela_paginas.h"
#include "algoritmo_substituicao.h"

// Total de páginas sujas escritas no disco
unsigned numeroPaginasSujas = 0;

// Lê a página do endereço recebido por argumento
// Retorna 1 caso tenha ocorrido um Page Fault e 0 caso contrário
short MMU_lerEndereco(unsigned endereco) {

    // Verifica se a página já está na memória
    if(TabelaPaginas_enderecoEstaValido(endereco)) {

        // Caso página esteja na memória, apenas atualiza o momento do último acesso
        TabelaPaginas_atualizarUltimoAcesso(endereco);

        if(debug) { // Imprime a mensagem do modo debug
            printf("Pagina 0x%08x acessada\n", endereco);
        }
        return 0;
    } else {

        // Caso a página não esteja na memória ela é lida do disco e inserida na memória
        MMU_buscaPaginaParaMemoria(endereco);

        if(debug) { // Imprime a mensagem do modo debug
            printf("Pagina 0x%08x nao encontrada na memoria\n", endereco);
        }
        return 1;
    }
}

// Escreve na página do endereço recebido por argumento
// Retorna 1 caso tenha ocorrido um Page Fault e 0 caso contrário
short MMU_escreverEndereco(unsigned endereco) {

    // Verifica se a página já está na memória
    if(TabelaPaginas_enderecoEstaValido(endereco)) {

        // Caso página esteja na memória, atualiza o momento do último 
        // acesso e marca que a página está suja
        TabelaPaginas_atualizarUltimoAcesso(endereco);
        TabelaPaginas_setEnderecoSujo(endereco, 1);

        if(debug) { // Imprime a mensagem do modo debug
            printf("Pagina 0x%08x acessada e escrita\n", endereco);
        }
        return 0;
    } else {

        // Caso a página não esteja na memória ela é lida do disco e inserida na memória
        MMU_buscaPaginaParaMemoria(endereco);

        if(debug) { // Imprime a mensagem do modo debug
            printf("Pagina 0x%08x nao encontrada na memoria\n", endereco);
        }
        return 1;
    }
}

// Coloca a página apontada por endereço na memória
void MMU_buscaPaginaParaMemoria(unsigned endereco) {

    // Tenta inserir a página na memória
    // Operação é bem sucedida se a memória possui algum espaço vazio
    short sucesso = TabelaPaginas_colocaPaginaMemoria(endereco);
    
    if(!sucesso) { // Memória cheia

        // Usa o algoritmo de substituição fornecido para determinar 
        // a página a ser removida da memória
        unsigned enderecoRemovido = AlgoritmoSubstituicao_determinaPagina();
        
        // Se a página estava suja, marca que ela foi escrita no disco
        if(TabelaPaginas_enderecoEstaSujo(enderecoRemovido)) {
            numeroPaginasSujas++;
        }

        // Substitui a página a ser removida pela página sendo inserida
        TabelaPaginas_substituiPaginasMemoria(endereco, enderecoRemovido);

        if(debug) { // Imprime a mensagem do modo debug
            printf("Pagina 0x%08x substituida pela pagina 0x%08x na memoria\n", enderecoRemovido, endereco);
        }
    } else { // Memória com espaço

        if(debug) { // Imprime a mensagem do modo debug
            printf("Pagina 0x%08x adicionada a memoria\n", endereco);
        }
    }
}