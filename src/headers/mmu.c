#include <stdlib.h>
#include <stdio.h>
#include "mmu.h"
#include "entrada_tabela.h"
#include "tabela_paginas.h"
#include "algoritmo_substituicao.h"

// Total de páginas sujas escritas no disco
unsigned numeroPaginasSujas = 0;

// Lê a página recebida por argumento
// Retorna 1 caso tenha ocorrido um Page Fault e 0 caso contrário
short MMU_lerPagina(unsigned pagina) {

    // Verifica se a página já está na memória
    if(TabelaPaginas_paginaEstaValida(pagina)) {

        // Caso página esteja na memória, atualiza as flags devido ao acesso
        TabelaPaginas_atualizarValoresPaginaAcessada(pagina);

        if(debug) { // Imprime a mensagem do modo debug
            printf("Pagina 0x%08x acessada\n", pagina);
        }
        return 0;
    } else {

        // Caso a página não esteja na memória ela é lida do disco e inserida na memória
        MMU_buscaPaginaParaMemoria(pagina);

        if(debug) { // Imprime a mensagem do modo debug
            printf("Pagina 0x%08x nao encontrada na memoria\n", pagina);
        }
        return 1;
    }
}

// Escreve na página recebida por argumento
// Retorna 1 caso tenha ocorrido um Page Fault e 0 caso contrário
short MMU_escreverPagina(unsigned pagina) {

    // Verifica se a página já está na memória
    if(TabelaPaginas_paginaEstaValida(pagina)) {

        // Caso a página esteja na memória, atualiza as flags devido ao acesso 
        // e marca que a página está suja
        TabelaPaginas_atualizarValoresPaginaAcessada(pagina);
        TabelaPaginas_setPaginaSuja(pagina, 1);

        if(debug) { // Imprime a mensagem do modo debug
            printf("Pagina 0x%08x acessada e escrita\n", pagina);
        }
        return 0;
    } else {

        // Caso a página não esteja na memória ela é lida do disco e inserida na memória
        MMU_buscaPaginaParaMemoria(pagina);

        if(debug) { // Imprime a mensagem do modo debug
            printf("Pagina 0x%08x nao encontrada na memoria\n", pagina);
        }
        return 1;
    }
}

// Coloca a página recebida na memória
void MMU_buscaPaginaParaMemoria(unsigned pagina) {

    // Tenta inserir a página na memória
    // Operação é bem sucedida se a memória possui algum espaço vazio
    short sucesso = TabelaPaginas_colocaPaginaMemoria(pagina);
    
    if(!sucesso) { // Memória cheia

        // Usa o algoritmo de substituição fornecido para determinar 
        // a página a ser removida da memória
        unsigned paginaRemovida = AlgoritmoSubstituicao_determinaPagina();
        
        // Se a página estava suja, marca que ela foi escrita no disco
        if(TabelaPaginas_paginaEstaSuja(paginaRemovida)) {
            numeroPaginasSujas++;
        }

        // Substitui a página a ser removida pela página sendo inserida
        TabelaPaginas_substituiPaginasMemoria(pagina, paginaRemovida);

        if(debug) { // Imprime a mensagem do modo debug
            printf("Pagina 0x%08x substituida pela pagina 0x%08x na memoria\n", paginaRemovida, pagina);
        }
    } else { // Memória com espaço

        if(debug) { // Imprime a mensagem do modo debug
            printf("Pagina 0x%08x adicionada a memoria\n", pagina);
        }
    }
}