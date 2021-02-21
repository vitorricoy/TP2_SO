#include <stdlib.h>
#include "memoria_fisica.h"
#include "entrada_tabela.h"

MemoriaFisica::MemoriaFisica(unsigned tamanhoMemoria, unsigned tamanhoPagina, unsigned numeroPaginas, bool debug){
    this->tamanhoMemoria = tamanhoMemoria;
    this->tabelaPaginas = (EntradaTabela*) malloc(numeroPaginas * sizeof(EntradaTabela));
}

MemoriaFisica::~MemoriaFisica() {
    free(this->tabelaPaginas);
}

bool MemoriaFisica::enderecoEstaValido(unsigned endereco) {
    return tabelaPaginas[endereco].estaValido();
}

bool MemoriaFisica::enderecoEstaSujo(unsigned endereco) {
    return tabelaPaginas[endereco].estaSujo();
}

void MemoriaFisica::setEnderecoValido(unsigned endereco, bool valido) {
    tabelaPaginas[endereco].setValido(valido);
}

void MemoriaFisica::setEnderecoSujo(unsigned endereco, bool sujo) {
    tabelaPaginas[endereco].setSujo(sujo);
}