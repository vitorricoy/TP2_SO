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