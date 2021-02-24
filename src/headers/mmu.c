#include <stdlib.h>
#include "mmu.h"
#include "entrada_tabela.h"
#include "memoria_fisica.h"

MMU::MMU(MemoriaFisica* memoriaFisica, unsigned* contadorPaginasSujas, AlgoritmoSubstituicao* algoritmo, bool debug) {
    this->algoritmoSubstituicao = algoritmo;
    this->debug = debug;
    this->memoriaFisica = memoriaFisica;
    this->contadorPaginasSujas = contadorPaginasSujas;
}

bool MMU::lerEndereco(unsigned endereco) {
    if(this->memoriaFisica->enderecoEstaValido(endereco)) {
        return false;
    } else {
        this->buscaPaginaParaMemoria(endereco, false);
        return true;
    }
}

bool MMU::escreverEndereco(unsigned endereco) {
    if(this->memoriaFisica->enderecoEstaValido(endereco)) {
        this->memoriaFisica->setEnderecoSujo(endereco, true);
        return false;
    } else {
        this->buscaPaginaParaMemoria(endereco, true);
        this->memoriaFisica->setEnderecoSujo(endereco, true);
        return true;
    }
}

void MMU::buscaPaginaParaMemoria(unsigned endereco, bool escrita) {
    // Ver melhor quando juntar as partes
    bool sucesso = memoriaFisica->colocaPaginaMemoria(endereco);
    if(!sucesso) {
        EntradaTabela removida = algoritmoSubstituicao->determinaPagina();
        if(removida.estaSujo()) {
            this->contadorPaginasSujas++;
        }
    }
}