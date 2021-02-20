#include <stdlib.h>
#include "mmu.h"
#include "entrada_tabela.h"
#include "memoria_fisica.h"

MMU::MMU(MemoriaFisica* memoriaFisica, AlgoritmoSubstituicao* algoritmo, bool debug) {
    this->algoritmoSubstituicao = algoritmo;
    this->debug = debug;
    this->memoriaFisica = memoriaFisica;
}

bool MMU::lerEndereco(unsigned endereco) {
    if(this->memoriaFisica->enderecoEstaValido(endereco)) {
        return true;
    } else {
        this->buscaPaginaParaMemoria(endereco);
        return false;
    }
}

bool MMU::escreverEndereco(unsigned endereco) {
    if(this->memoriaFisica->enderecoEstaValido(endereco)) {
        this->memoriaFisica->setEnderecoSujo(endereco);
        return true;
    } else {
        this->buscaPaginaParaMemoria(endereco);
        this->memoriaFisica->setEnderecoSujo(endereco);
        return false;
    }
}

void MMU::buscaPaginaParaMemoria(unsigned endereco) {
    if(algoritmoSubstituicao->precisaDeSubstituicao()) {
        algoritmoSubstituicao->determinaPagina();
    } else {

    }
}