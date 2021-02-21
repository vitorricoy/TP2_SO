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
        this->buscaPaginaParaMemoria(endereco);
        return true;
    }
}

bool MMU::escreverEndereco(unsigned endereco) {
    if(this->memoriaFisica->enderecoEstaValido(endereco)) {
        this->memoriaFisica->setEnderecoSujo(endereco, true);
        return false;
    } else {
        this->buscaPaginaParaMemoria(endereco);
        this->memoriaFisica->setEnderecoSujo(endereco, true);
        return true;
    }
}

void MMU::buscaPaginaParaMemoria(unsigned endereco) {
    // Ver melhor quando juntar as partes
    if(algoritmoSubstituicao->precisaDeSubstituicao()) {
        EntradaTabela removida = algoritmoSubstituicao->determinaPagina();
        if(removida.estaSujo()) {
            this->contadorPaginasSujas++;
        }
    } else {

    }
}