#include <stdlib.h>
#include "memoria_fisica.h"
#include "entrada_tabela.h"

MemoriaFisica::MemoriaFisica(unsigned tamanhoMemoria, unsigned tamanhoPagina, unsigned numeroPaginas, bool debug){
    this->tamanhoMemoria = tamanhoMemoria;
    this->tabelaPaginas = (EntradaTabela*) malloc(numeroPaginas * sizeof(EntradaTabela));
    this->numeroPaginas = numeroPaginas;
    this->paginasOcupadas = 0;
}

MemoriaFisica::~MemoriaFisica() {
    free(this->tabelaPaginas);
}

bool MemoriaFisica::enderecoEstaValido(unsigned endereco) {
    return this->tabelaPaginas[endereco].estaValido();
}

bool MemoriaFisica::enderecoEstaSujo(unsigned endereco) {
    return this->tabelaPaginas[endereco].estaSujo();
}

void MemoriaFisica::setEnderecoValido(unsigned endereco, bool valido) {
    this->tabelaPaginas[endereco].setValido(valido);
}

bool MemoriaFisica::colocaPaginaMemoria(unsigned endereco) {
    if(this->paginasOcupadas < this->numeroPaginas) {
        this->paginasOcupadas++;
        this->setEnderecoValido(endereco, true);
        this->setEnderecoSujo(endereco, false);
        return true;
    }
    return false;
}

void MemoriaFisica::setEnderecoSujo(unsigned endereco, bool sujo) {
    this->tabelaPaginas[endereco].setSujo(sujo);
}