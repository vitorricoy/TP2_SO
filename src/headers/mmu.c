#include <stdlib.h>
#include "mmu.h"
#include "entrada_tabela.h"
#include "memoria_fisica.h"
#include "algoritmo_substituicao.h"

unsigned contadorPaginasSujas = 0;

short MMU_lerEndereco(unsigned endereco) {
    if(MemoriaFisica_enderecoEstaValido(endereco)) {
        return 0;
    } else {
        MMU_buscaPaginaParaMemoria(endereco, 0);
        return 1;
    }
}

short MMU_escreverEndereco(unsigned endereco) {
    if(MemoriaFisica_enderecoEstaValido(endereco)) {
        MemoriaFisica_setEnderecoSujo(endereco, 1);
        return 0;
    } else {
        MMU_buscaPaginaParaMemoria(endereco, 1);
        MemoriaFisica_setEnderecoSujo(endereco, 1);
        return 1;
    }
}

void MMU_buscaPaginaParaMemoria(unsigned endereco, short escrita) {
    // Ver melhor quando juntar as partes
    short sucesso = MemoriaFisica_colocaPaginaMemoria(endereco);
    if(!sucesso) {
        EntradaTabela removida = AlgoritmoSubstituicao_determinaPagina();
        if(removida.sujo) {
            contadorPaginasSujas++;
        }
        //Insere pagina na memoria
    }
}